/*******************************************************************************
* File Name: uartINT.c
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

#include "uart.h"
#include "cyapicallbacks.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if (uart_RX_INTERRUPT_ENABLED && (uart_RX_ENABLED || uart_HD_ENABLED))
    /*******************************************************************************
    * Function Name: uart_RXISR
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
    *  uart_rxBuffer - RAM buffer pointer for save received data.
    *  uart_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  uart_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  uart_rxBufferOverflow - software overflow flag. Set to one
    *     when uart_rxBufferWrite index overtakes
    *     uart_rxBufferRead index.
    *  uart_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when uart_rxBufferWrite is equal to
    *    uart_rxBufferRead
    *  uart_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  uart_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(uart_RXISR)
    {
        uint8 readData;
        uint8 readStatus;
        uint8 increment_pointer = 0u;

    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

    #ifdef uart_RXISR_ENTRY_CALLBACK
        uart_RXISR_EntryCallback();
    #endif /* uart_RXISR_ENTRY_CALLBACK */

        /* User code required at start of ISR */
        /* `#START uart_RXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        do
        {
            /* Read receiver status register */
            readStatus = uart_RXSTATUS_REG;
            /* Copy the same status to readData variable for backward compatibility support 
            *  of the user code in uart_RXISR_ERROR` section. 
            */
            readData = readStatus;

            if((readStatus & (uart_RX_STS_BREAK | 
                            uart_RX_STS_PAR_ERROR |
                            uart_RX_STS_STOP_ERROR | 
                            uart_RX_STS_OVERRUN)) != 0u)
            {
                /* ERROR handling. */
                uart_errorStatus |= readStatus & ( uart_RX_STS_BREAK | 
                                                            uart_RX_STS_PAR_ERROR | 
                                                            uart_RX_STS_STOP_ERROR | 
                                                            uart_RX_STS_OVERRUN);
                /* `#START uart_RXISR_ERROR` */

                /* `#END` */
                
            #ifdef uart_RXISR_ERROR_CALLBACK
                uart_RXISR_ERROR_Callback();
            #endif /* uart_RXISR_ERROR_CALLBACK */
            }
            
            if((readStatus & uart_RX_STS_FIFO_NOTEMPTY) != 0u)
            {
                /* Read data from the RX data register */
                readData = uart_RXDATA_REG;
            #if (uart_RXHW_ADDRESS_ENABLED)
                if(uart_rxAddressMode == (uint8)uart__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readStatus & uart_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readStatus & uart_RX_STS_ADDR_MATCH) != 0u)
                        {
                            uart_rxAddressDetected = 1u;
                        }
                        else
                        {
                            uart_rxAddressDetected = 0u;
                        }
                    }
                    if(uart_rxAddressDetected != 0u)
                    {   /* Store only addressed data */
                        uart_rxBuffer[uart_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* Without software addressing */
                {
                    uart_rxBuffer[uart_rxBufferWrite] = readData;
                    increment_pointer = 1u;
                }
            #else  /* Without addressing */
                uart_rxBuffer[uart_rxBufferWrite] = readData;
                increment_pointer = 1u;
            #endif /* (uart_RXHW_ADDRESS_ENABLED) */

                /* Do not increment buffer pointer when skip not addressed data */
                if(increment_pointer != 0u)
                {
                    if(uart_rxBufferLoopDetect != 0u)
                    {   /* Set Software Buffer status Overflow */
                        uart_rxBufferOverflow = 1u;
                    }
                    /* Set next pointer. */
                    uart_rxBufferWrite++;

                    /* Check pointer for a loop condition */
                    if(uart_rxBufferWrite >= uart_RX_BUFFER_SIZE)
                    {
                        uart_rxBufferWrite = 0u;
                    }

                    /* Detect pre-overload condition and set flag */
                    if(uart_rxBufferWrite == uart_rxBufferRead)
                    {
                        uart_rxBufferLoopDetect = 1u;
                        /* When Hardware Flow Control selected */
                        #if (uart_FLOW_CONTROL != 0u)
                            /* Disable RX interrupt mask, it is enabled when user read data from the buffer using APIs */
                            uart_RXSTATUS_MASK_REG  &= (uint8)~uart_RX_STS_FIFO_NOTEMPTY;
                            CyIntClearPending(uart_RX_VECT_NUM);
                            break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                        #endif /* (uart_FLOW_CONTROL != 0u) */
                    }
                }
            }
        }while((readStatus & uart_RX_STS_FIFO_NOTEMPTY) != 0u);

        /* User code required at end of ISR (Optional) */
        /* `#START uart_RXISR_END` */

        /* `#END` */

    #ifdef uart_RXISR_EXIT_CALLBACK
        uart_RXISR_ExitCallback();
    #endif /* uart_RXISR_EXIT_CALLBACK */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
    }
    
#endif /* (uart_RX_INTERRUPT_ENABLED && (uart_RX_ENABLED || uart_HD_ENABLED)) */


#if (uart_TX_INTERRUPT_ENABLED && uart_TX_ENABLED)
    /*******************************************************************************
    * Function Name: uart_TXISR
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
    *  uart_txBuffer - RAM buffer pointer for transmit data from.
    *  uart_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmitted byte.
    *  uart_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(uart_TXISR)
    {
    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

    #ifdef uart_TXISR_ENTRY_CALLBACK
        uart_TXISR_EntryCallback();
    #endif /* uart_TXISR_ENTRY_CALLBACK */

        /* User code required at start of ISR */
        /* `#START uart_TXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        while((uart_txBufferRead != uart_txBufferWrite) &&
             ((uart_TXSTATUS_REG & uart_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer wrap around */
            if(uart_txBufferRead >= uart_TX_BUFFER_SIZE)
            {
                uart_txBufferRead = 0u;
            }

            uart_TXDATA_REG = uart_txBuffer[uart_txBufferRead];

            /* Set next pointer */
            uart_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START uart_TXISR_END` */

        /* `#END` */

    #ifdef uart_TXISR_EXIT_CALLBACK
        uart_TXISR_ExitCallback();
    #endif /* uart_TXISR_EXIT_CALLBACK */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
   }
#endif /* (uart_TX_INTERRUPT_ENABLED && uart_TX_ENABLED) */


/* [] END OF FILE */
