/*******************************************************************************
* File Name: uart2INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service functionality of the UART component
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "uart2.h"



/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if (uart2_RX_INTERRUPT_ENABLED && (uart2_RX_ENABLED || uart2_HD_ENABLED))
    /*******************************************************************************
    * Function Name: uart2_RXISR
    ********************************************************************************
    *
    * Summary:
    *  Interrupt Service Routine for RX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart2_rxBuffer - RAM buffer pointer for save received data.
    *  uart2_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  uart2_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  uart2_rxBufferOverflow - software overflow flag. Set to one
    *     when uart2_rxBufferWrite index overtakes
    *     uart2_rxBufferRead index.
    *  uart2_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when uart2_rxBufferWrite is equal to
    *    uart2_rxBufferRead
    *  uart2_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  uart2_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(uart2_RXISR)
    {
        uint8 readData;
        uint8 readStatus;
        uint8 increment_pointer = 0u;

    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

    #ifdef uart2_RXISR_ENTRY_CALLBACK
        uart2_RXISR_EntryCallback();
    #endif /* uart2_RXISR_ENTRY_CALLBACK */

        /* User code required at start of ISR */
        /* `#START uart2_RXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        do
        {
            /* Read receiver status register */
            readStatus = uart2_RXSTATUS_REG;
            /* Copy the same status to readData variable for backward compatibility support 
            *  of the user code in uart2_RXISR_ERROR` section. 
            */
            readData = readStatus;

            if((readStatus & (uart2_RX_STS_BREAK | 
                            uart2_RX_STS_PAR_ERROR |
                            uart2_RX_STS_STOP_ERROR | 
                            uart2_RX_STS_OVERRUN)) != 0u)
            {
                /* ERROR handling. */
                uart2_errorStatus |= readStatus & ( uart2_RX_STS_BREAK | 
                                                            uart2_RX_STS_PAR_ERROR | 
                                                            uart2_RX_STS_STOP_ERROR | 
                                                            uart2_RX_STS_OVERRUN);
                /* `#START uart2_RXISR_ERROR` */

                /* `#END` */
                
            #ifdef uart2_RXISR_ERROR_CALLBACK
                uart2_RXISR_ERROR_Callback();
            #endif /* uart2_RXISR_ERROR_CALLBACK */
            }
            
            if((readStatus & uart2_RX_STS_FIFO_NOTEMPTY) != 0u)
            {
                /* Read data from the RX data register */
                readData = uart2_RXDATA_REG;
            #if (uart2_RXHW_ADDRESS_ENABLED)
                if(uart2_rxAddressMode == (uint8)uart2__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readStatus & uart2_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readStatus & uart2_RX_STS_ADDR_MATCH) != 0u)
                        {
                            uart2_rxAddressDetected = 1u;
                        }
                        else
                        {
                            uart2_rxAddressDetected = 0u;
                        }
                    }
                    if(uart2_rxAddressDetected != 0u)
                    {   /* Store only addressed data */
                        uart2_rxBuffer[uart2_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* Without software addressing */
                {
                    uart2_rxBuffer[uart2_rxBufferWrite] = readData;
                    increment_pointer = 1u;
                }
            #else  /* Without addressing */
                uart2_rxBuffer[uart2_rxBufferWrite] = readData;
                increment_pointer = 1u;
            #endif /* (uart2_RXHW_ADDRESS_ENABLED) */

                /* Do not increment buffer pointer when skip not addressed data */
                if(increment_pointer != 0u)
                {
                    if(uart2_rxBufferLoopDetect != 0u)
                    {   /* Set Software Buffer status Overflow */
                        uart2_rxBufferOverflow = 1u;
                    }
                    /* Set next pointer. */
                    uart2_rxBufferWrite++;

                    /* Check pointer for a loop condition */
                    if(uart2_rxBufferWrite >= uart2_RX_BUFFER_SIZE)
                    {
                        uart2_rxBufferWrite = 0u;
                    }

                    /* Detect pre-overload condition and set flag */
                    if(uart2_rxBufferWrite == uart2_rxBufferRead)
                    {
                        uart2_rxBufferLoopDetect = 1u;
                        /* When Hardware Flow Control selected */
                        #if (uart2_FLOW_CONTROL != 0u)
                            /* Disable RX interrupt mask, it is enabled when user read data from the buffer using APIs */
                            uart2_RXSTATUS_MASK_REG  &= (uint8)~uart2_RX_STS_FIFO_NOTEMPTY;
                            CyIntClearPending(uart2_RX_VECT_NUM);
                            break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                        #endif /* (uart2_FLOW_CONTROL != 0u) */
                    }
                }
            }
        }while((readStatus & uart2_RX_STS_FIFO_NOTEMPTY) != 0u);

        /* User code required at end of ISR (Optional) */
        /* `#START uart2_RXISR_END` */

        /* `#END` */

    #ifdef uart2_RXISR_EXIT_CALLBACK
        uart2_RXISR_ExitCallback();
    #endif /* uart2_RXISR_EXIT_CALLBACK */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
    }
    
#endif /* (uart2_RX_INTERRUPT_ENABLED && (uart2_RX_ENABLED || uart2_HD_ENABLED)) */


#if (uart2_TX_INTERRUPT_ENABLED && uart2_TX_ENABLED)
    /*******************************************************************************
    * Function Name: uart2_TXISR
    ********************************************************************************
    *
    * Summary:
    * Interrupt Service Routine for the TX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart2_txBuffer - RAM buffer pointer for transmit data from.
    *  uart2_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmitted byte.
    *  uart2_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(uart2_TXISR)
    {
    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

    #ifdef uart2_TXISR_ENTRY_CALLBACK
        uart2_TXISR_EntryCallback();
    #endif /* uart2_TXISR_ENTRY_CALLBACK */

        /* User code required at start of ISR */
        /* `#START uart2_TXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        while((uart2_txBufferRead != uart2_txBufferWrite) &&
             ((uart2_TXSTATUS_REG & uart2_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer wrap around */
            if(uart2_txBufferRead >= uart2_TX_BUFFER_SIZE)
            {
                uart2_txBufferRead = 0u;
            }

            uart2_TXDATA_REG = uart2_txBuffer[uart2_txBufferRead];

            /* Set next pointer */
            uart2_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START uart2_TXISR_END` */

        /* `#END` */

    #ifdef uart2_TXISR_EXIT_CALLBACK
        uart2_TXISR_ExitCallback();
    #endif /* uart2_TXISR_EXIT_CALLBACK */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
   }
#endif /* (uart2_TX_INTERRUPT_ENABLED && uart2_TX_ENABLED) */


/* [] END OF FILE */
