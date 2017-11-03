/*******************************************************************************
* File Name: uart.h
* Version 2.50
*
* Description:
*  Contains the function prototypes and constants available to the UART
*  user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_UART_uart_H)
#define CY_UART_uart_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/***************************************
* Conditional Compilation Parameters
***************************************/

#define uart_RX_ENABLED                     (1u)
#define uart_TX_ENABLED                     (1u)
#define uart_HD_ENABLED                     (0u)
#define uart_RX_INTERRUPT_ENABLED           (0u)
#define uart_TX_INTERRUPT_ENABLED           (0u)
#define uart_INTERNAL_CLOCK_USED            (1u)
#define uart_RXHW_ADDRESS_ENABLED           (0u)
#define uart_OVER_SAMPLE_COUNT              (8u)
#define uart_PARITY_TYPE                    (0u)
#define uart_PARITY_TYPE_SW                 (0u)
#define uart_BREAK_DETECT                   (0u)
#define uart_BREAK_BITS_TX                  (13u)
#define uart_BREAK_BITS_RX                  (13u)
#define uart_TXCLKGEN_DP                    (1u)
#define uart_USE23POLLING                   (1u)
#define uart_FLOW_CONTROL                   (0u)
#define uart_CLK_FREQ                       (0u)
#define uart_TX_BUFFER_SIZE                 (4u)
#define uart_RX_BUFFER_SIZE                 (4u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#if defined(uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG)
    #define uart_CONTROL_REG_REMOVED            (0u)
#else
    #define uart_CONTROL_REG_REMOVED            (1u)
#endif /* End uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Structure Definition
***************************************/

/* Sleep Mode API Support */
typedef struct uart_backupStruct_
{
    uint8 enableState;

    #if(uart_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End uart_CONTROL_REG_REMOVED */

} uart_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void uart_Start(void) ;
void uart_Stop(void) ;
uint8 uart_ReadControlRegister(void) ;
void uart_WriteControlRegister(uint8 control) ;

void uart_Init(void) ;
void uart_Enable(void) ;
void uart_SaveConfig(void) ;
void uart_RestoreConfig(void) ;
void uart_Sleep(void) ;
void uart_Wakeup(void) ;

/* Only if RX is enabled */
#if( (uart_RX_ENABLED) || (uart_HD_ENABLED) )

    #if (uart_RX_INTERRUPT_ENABLED)
        #define uart_EnableRxInt()  CyIntEnable (uart_RX_VECT_NUM)
        #define uart_DisableRxInt() CyIntDisable(uart_RX_VECT_NUM)
        CY_ISR_PROTO(uart_RXISR);
    #endif /* uart_RX_INTERRUPT_ENABLED */

    void uart_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void uart_SetRxAddress1(uint8 address) ;
    void uart_SetRxAddress2(uint8 address) ;

    void  uart_SetRxInterruptMode(uint8 intSrc) ;
    uint8 uart_ReadRxData(void) ;
    uint8 uart_ReadRxStatus(void) ;
    uint8 uart_GetChar(void) ;
    uint16 uart_GetByte(void) ;
    uint8 uart_GetRxBufferSize(void)
                                                            ;
    void uart_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define uart_GetRxInterruptSource   uart_ReadRxStatus

#endif /* End (uart_RX_ENABLED) || (uart_HD_ENABLED) */

/* Only if TX is enabled */
#if(uart_TX_ENABLED || uart_HD_ENABLED)

    #if(uart_TX_INTERRUPT_ENABLED)
        #define uart_EnableTxInt()  CyIntEnable (uart_TX_VECT_NUM)
        #define uart_DisableTxInt() CyIntDisable(uart_TX_VECT_NUM)
        #define uart_SetPendingTxInt() CyIntSetPending(uart_TX_VECT_NUM)
        #define uart_ClearPendingTxInt() CyIntClearPending(uart_TX_VECT_NUM)
        CY_ISR_PROTO(uart_TXISR);
    #endif /* uart_TX_INTERRUPT_ENABLED */

    void uart_SetTxInterruptMode(uint8 intSrc) ;
    void uart_WriteTxData(uint8 txDataByte) ;
    uint8 uart_ReadTxStatus(void) ;
    void uart_PutChar(uint8 txDataByte) ;
    void uart_PutString(const char8 string[]) ;
    void uart_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void uart_PutCRLF(uint8 txDataByte) ;
    void uart_ClearTxBuffer(void) ;
    void uart_SetTxAddressMode(uint8 addressMode) ;
    void uart_SendBreak(uint8 retMode) ;
    uint8 uart_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define uart_PutStringConst         uart_PutString
    #define uart_PutArrayConst          uart_PutArray
    #define uart_GetTxInterruptSource   uart_ReadTxStatus

#endif /* End uart_TX_ENABLED || uart_HD_ENABLED */

#if(uart_HD_ENABLED)
    void uart_LoadRxConfig(void) ;
    void uart_LoadTxConfig(void) ;
#endif /* End uart_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    uart_CyBtldrCommStart(void) CYSMALL ;
    void    uart_CyBtldrCommStop(void) CYSMALL ;
    void    uart_CyBtldrCommReset(void) CYSMALL ;
    cystatus uart_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus uart_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart)
        #define CyBtldrCommStart    uart_CyBtldrCommStart
        #define CyBtldrCommStop     uart_CyBtldrCommStop
        #define CyBtldrCommReset    uart_CyBtldrCommReset
        #define CyBtldrCommWrite    uart_CyBtldrCommWrite
        #define CyBtldrCommRead     uart_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define uart_BYTE2BYTE_TIME_OUT (25u)
    #define uart_PACKET_EOP         (0x17u) /* End of packet defined by bootloader */
    #define uart_WAIT_EOP_DELAY     (5u)    /* Additional 5ms to wait for End of packet */
    #define uart_BL_CHK_DELAY_MS    (1u)    /* Time Out quantity equal 1mS */

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define uart_SET_SPACE      (0x00u)
#define uart_SET_MARK       (0x01u)

/* Status Register definitions */
#if( (uart_TX_ENABLED) || (uart_HD_ENABLED) )
    #if(uart_TX_INTERRUPT_ENABLED)
        #define uart_TX_VECT_NUM            (uint8)uart_TXInternalInterrupt__INTC_NUMBER
        #define uart_TX_PRIOR_NUM           (uint8)uart_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* uart_TX_INTERRUPT_ENABLED */

    #define uart_TX_STS_COMPLETE_SHIFT          (0x00u)
    #define uart_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
    #define uart_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #if(uart_TX_ENABLED)
        #define uart_TX_STS_FIFO_FULL_SHIFT     (0x02u)
    #else /* (uart_HD_ENABLED) */
        #define uart_TX_STS_FIFO_FULL_SHIFT     (0x05u)  /* Needs MD=0 */
    #endif /* (uart_TX_ENABLED) */

    #define uart_TX_STS_COMPLETE            (uint8)(0x01u << uart_TX_STS_COMPLETE_SHIFT)
    #define uart_TX_STS_FIFO_EMPTY          (uint8)(0x01u << uart_TX_STS_FIFO_EMPTY_SHIFT)
    #define uart_TX_STS_FIFO_FULL           (uint8)(0x01u << uart_TX_STS_FIFO_FULL_SHIFT)
    #define uart_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << uart_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (uart_TX_ENABLED) || (uart_HD_ENABLED)*/

#if( (uart_RX_ENABLED) || (uart_HD_ENABLED) )
    #if(uart_RX_INTERRUPT_ENABLED)
        #define uart_RX_VECT_NUM            (uint8)uart_RXInternalInterrupt__INTC_NUMBER
        #define uart_RX_PRIOR_NUM           (uint8)uart_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* uart_RX_INTERRUPT_ENABLED */
    #define uart_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define uart_RX_STS_BREAK_SHIFT             (0x01u)
    #define uart_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define uart_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define uart_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define uart_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define uart_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define uart_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define uart_RX_STS_MRKSPC           (uint8)(0x01u << uart_RX_STS_MRKSPC_SHIFT)
    #define uart_RX_STS_BREAK            (uint8)(0x01u << uart_RX_STS_BREAK_SHIFT)
    #define uart_RX_STS_PAR_ERROR        (uint8)(0x01u << uart_RX_STS_PAR_ERROR_SHIFT)
    #define uart_RX_STS_STOP_ERROR       (uint8)(0x01u << uart_RX_STS_STOP_ERROR_SHIFT)
    #define uart_RX_STS_OVERRUN          (uint8)(0x01u << uart_RX_STS_OVERRUN_SHIFT)
    #define uart_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << uart_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define uart_RX_STS_ADDR_MATCH       (uint8)(0x01u << uart_RX_STS_ADDR_MATCH_SHIFT)
    #define uart_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << uart_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define uart_RX_HW_MASK                     (0x7Fu)
#endif /* End (uart_RX_ENABLED) || (uart_HD_ENABLED) */

/* Control Register definitions */
#define uart_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define uart_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define uart_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define uart_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define uart_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define uart_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define uart_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define uart_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define uart_CTRL_HD_SEND               (uint8)(0x01u << uart_CTRL_HD_SEND_SHIFT)
#define uart_CTRL_HD_SEND_BREAK         (uint8)(0x01u << uart_CTRL_HD_SEND_BREAK_SHIFT)
#define uart_CTRL_MARK                  (uint8)(0x01u << uart_CTRL_MARK_SHIFT)
#define uart_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << uart_CTRL_PARITY_TYPE0_SHIFT)
#define uart_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << uart_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define uart_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define uart_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define uart_SEND_BREAK                         (0x00u)
#define uart_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define uart_REINIT                             (0x02u)
#define uart_SEND_WAIT_REINIT                   (0x03u)

#define uart_OVER_SAMPLE_8                      (8u)
#define uart_OVER_SAMPLE_16                     (16u)

#define uart_BIT_CENTER                         (uart_OVER_SAMPLE_COUNT - 2u)

#define uart_FIFO_LENGTH                        (4u)
#define uart_NUMBER_OF_START_BIT                (1u)
#define uart_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation */
#define uart_TXBITCTR_BREAKBITS8X   ((uart_BREAK_BITS_TX * uart_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation */
#define uart_TXBITCTR_BREAKBITS ((uart_BREAK_BITS_TX * uart_OVER_SAMPLE_COUNT) - 1u)

#define uart_HALF_BIT_COUNT   \
                            (((uart_OVER_SAMPLE_COUNT / 2u) + (uart_USE23POLLING * 1u)) - 2u)
#if (uart_OVER_SAMPLE_COUNT == uart_OVER_SAMPLE_8)
    #define uart_HD_TXBITCTR_INIT   (((uart_BREAK_BITS_TX + \
                            uart_NUMBER_OF_START_BIT) * uart_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define uart_RXBITCTR_INIT  ((((uart_BREAK_BITS_RX + uart_NUMBER_OF_START_BIT) \
                            * uart_OVER_SAMPLE_COUNT) + uart_HALF_BIT_COUNT) - 1u)

#else /* uart_OVER_SAMPLE_COUNT == uart_OVER_SAMPLE_16 */
    #define uart_HD_TXBITCTR_INIT   ((8u * uart_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount = 16 */
    #define uart_RXBITCTR_INIT      (((7u * uart_OVER_SAMPLE_COUNT) - 1u) + \
                                                      uart_HALF_BIT_COUNT)
#endif /* End uart_OVER_SAMPLE_COUNT */

#define uart_HD_RXBITCTR_INIT                   uart_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 uart_initVar;
#if (uart_TX_INTERRUPT_ENABLED && uart_TX_ENABLED)
    extern volatile uint8 uart_txBuffer[uart_TX_BUFFER_SIZE];
    extern volatile uint8 uart_txBufferRead;
    extern uint8 uart_txBufferWrite;
#endif /* (uart_TX_INTERRUPT_ENABLED && uart_TX_ENABLED) */
#if (uart_RX_INTERRUPT_ENABLED && (uart_RX_ENABLED || uart_HD_ENABLED))
    extern uint8 uart_errorStatus;
    extern volatile uint8 uart_rxBuffer[uart_RX_BUFFER_SIZE];
    extern volatile uint8 uart_rxBufferRead;
    extern volatile uint8 uart_rxBufferWrite;
    extern volatile uint8 uart_rxBufferLoopDetect;
    extern volatile uint8 uart_rxBufferOverflow;
    #if (uart_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 uart_rxAddressMode;
        extern volatile uint8 uart_rxAddressDetected;
    #endif /* (uart_RXHW_ADDRESS_ENABLED) */
#endif /* (uart_RX_INTERRUPT_ENABLED && (uart_RX_ENABLED || uart_HD_ENABLED)) */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define uart__B_UART__AM_SW_BYTE_BYTE 1
#define uart__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define uart__B_UART__AM_HW_BYTE_BY_BYTE 3
#define uart__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define uart__B_UART__AM_NONE 0

#define uart__B_UART__NONE_REVB 0
#define uart__B_UART__EVEN_REVB 1
#define uart__B_UART__ODD_REVB 2
#define uart__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define uart_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define uart_NUMBER_OF_STOP_BITS    (1u)

#if (uart_RXHW_ADDRESS_ENABLED)
    #define uart_RX_ADDRESS_MODE    (0u)
    #define uart_RX_HW_ADDRESS1     (0u)
    #define uart_RX_HW_ADDRESS2     (0u)
#endif /* (uart_RXHW_ADDRESS_ENABLED) */

#define uart_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << uart_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << uart_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << uart_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << uart_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << uart_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << uart_RX_STS_BREAK_SHIFT) \
                                        | (0 << uart_RX_STS_OVERRUN_SHIFT))

#define uart_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << uart_TX_STS_COMPLETE_SHIFT) \
                                        | (0 << uart_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << uart_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << uart_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define uart_CONTROL_REG \
                            (* (reg8 *) uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define uart_CONTROL_PTR \
                            (  (reg8 *) uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(uart_TX_ENABLED)
    #define uart_TXDATA_REG          (* (reg8 *) uart_BUART_sTX_TxShifter_u0__F0_REG)
    #define uart_TXDATA_PTR          (  (reg8 *) uart_BUART_sTX_TxShifter_u0__F0_REG)
    #define uart_TXDATA_AUX_CTL_REG  (* (reg8 *) uart_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define uart_TXDATA_AUX_CTL_PTR  (  (reg8 *) uart_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define uart_TXSTATUS_REG        (* (reg8 *) uart_BUART_sTX_TxSts__STATUS_REG)
    #define uart_TXSTATUS_PTR        (  (reg8 *) uart_BUART_sTX_TxSts__STATUS_REG)
    #define uart_TXSTATUS_MASK_REG   (* (reg8 *) uart_BUART_sTX_TxSts__MASK_REG)
    #define uart_TXSTATUS_MASK_PTR   (  (reg8 *) uart_BUART_sTX_TxSts__MASK_REG)
    #define uart_TXSTATUS_ACTL_REG   (* (reg8 *) uart_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define uart_TXSTATUS_ACTL_PTR   (  (reg8 *) uart_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(uart_TXCLKGEN_DP)
        #define uart_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define uart_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define uart_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) uart_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define uart_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) uart_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define uart_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) uart_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define uart_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) uart_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define uart_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) uart_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define uart_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) uart_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define uart_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) uart_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define uart_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) uart_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* uart_TXCLKGEN_DP */

#endif /* End uart_TX_ENABLED */

#if(uart_HD_ENABLED)

    #define uart_TXDATA_REG             (* (reg8 *) uart_BUART_sRX_RxShifter_u0__F1_REG )
    #define uart_TXDATA_PTR             (  (reg8 *) uart_BUART_sRX_RxShifter_u0__F1_REG )
    #define uart_TXDATA_AUX_CTL_REG     (* (reg8 *) uart_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define uart_TXDATA_AUX_CTL_PTR     (  (reg8 *) uart_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define uart_TXSTATUS_REG           (* (reg8 *) uart_BUART_sRX_RxSts__STATUS_REG )
    #define uart_TXSTATUS_PTR           (  (reg8 *) uart_BUART_sRX_RxSts__STATUS_REG )
    #define uart_TXSTATUS_MASK_REG      (* (reg8 *) uart_BUART_sRX_RxSts__MASK_REG )
    #define uart_TXSTATUS_MASK_PTR      (  (reg8 *) uart_BUART_sRX_RxSts__MASK_REG )
    #define uart_TXSTATUS_ACTL_REG      (* (reg8 *) uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define uart_TXSTATUS_ACTL_PTR      (  (reg8 *) uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End uart_HD_ENABLED */

#if( (uart_RX_ENABLED) || (uart_HD_ENABLED) )
    #define uart_RXDATA_REG             (* (reg8 *) uart_BUART_sRX_RxShifter_u0__F0_REG )
    #define uart_RXDATA_PTR             (  (reg8 *) uart_BUART_sRX_RxShifter_u0__F0_REG )
    #define uart_RXADDRESS1_REG         (* (reg8 *) uart_BUART_sRX_RxShifter_u0__D0_REG )
    #define uart_RXADDRESS1_PTR         (  (reg8 *) uart_BUART_sRX_RxShifter_u0__D0_REG )
    #define uart_RXADDRESS2_REG         (* (reg8 *) uart_BUART_sRX_RxShifter_u0__D1_REG )
    #define uart_RXADDRESS2_PTR         (  (reg8 *) uart_BUART_sRX_RxShifter_u0__D1_REG )
    #define uart_RXDATA_AUX_CTL_REG     (* (reg8 *) uart_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define uart_RXBITCTR_PERIOD_REG    (* (reg8 *) uart_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define uart_RXBITCTR_PERIOD_PTR    (  (reg8 *) uart_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define uart_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) uart_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define uart_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) uart_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define uart_RXBITCTR_COUNTER_REG   (* (reg8 *) uart_BUART_sRX_RxBitCounter__COUNT_REG )
    #define uart_RXBITCTR_COUNTER_PTR   (  (reg8 *) uart_BUART_sRX_RxBitCounter__COUNT_REG )

    #define uart_RXSTATUS_REG           (* (reg8 *) uart_BUART_sRX_RxSts__STATUS_REG )
    #define uart_RXSTATUS_PTR           (  (reg8 *) uart_BUART_sRX_RxSts__STATUS_REG )
    #define uart_RXSTATUS_MASK_REG      (* (reg8 *) uart_BUART_sRX_RxSts__MASK_REG )
    #define uart_RXSTATUS_MASK_PTR      (  (reg8 *) uart_BUART_sRX_RxSts__MASK_REG )
    #define uart_RXSTATUS_ACTL_REG      (* (reg8 *) uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define uart_RXSTATUS_ACTL_PTR      (  (reg8 *) uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (uart_RX_ENABLED) || (uart_HD_ENABLED) */

#if(uart_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define uart_INTCLOCK_CLKEN_REG     (* (reg8 *) uart_IntClock__PM_ACT_CFG)
    #define uart_INTCLOCK_CLKEN_PTR     (  (reg8 *) uart_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define uart_INTCLOCK_CLKEN_MASK    uart_IntClock__PM_ACT_MSK
#endif /* End uart_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(uart_TX_ENABLED)
    #define uart_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End uart_TX_ENABLED */

#if(uart_HD_ENABLED)
    #define uart_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End uart_HD_ENABLED */

#if( (uart_RX_ENABLED) || (uart_HD_ENABLED) )
    #define uart_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (uart_RX_ENABLED) || (uart_HD_ENABLED) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

/* UART v2_40 obsolete definitions */
#define uart_WAIT_1_MS      uart_BL_CHK_DELAY_MS   

#define uart_TXBUFFERSIZE   uart_TX_BUFFER_SIZE
#define uart_RXBUFFERSIZE   uart_RX_BUFFER_SIZE

#if (uart_RXHW_ADDRESS_ENABLED)
    #define uart_RXADDRESSMODE  uart_RX_ADDRESS_MODE
    #define uart_RXHWADDRESS1   uart_RX_HW_ADDRESS1
    #define uart_RXHWADDRESS2   uart_RX_HW_ADDRESS2
    /* Backward compatible define */
    #define uart_RXAddressMode  uart_RXADDRESSMODE
#endif /* (uart_RXHW_ADDRESS_ENABLED) */

/* UART v2_30 obsolete definitions */
#define uart_initvar                    uart_initVar

#define uart_RX_Enabled                 uart_RX_ENABLED
#define uart_TX_Enabled                 uart_TX_ENABLED
#define uart_HD_Enabled                 uart_HD_ENABLED
#define uart_RX_IntInterruptEnabled     uart_RX_INTERRUPT_ENABLED
#define uart_TX_IntInterruptEnabled     uart_TX_INTERRUPT_ENABLED
#define uart_InternalClockUsed          uart_INTERNAL_CLOCK_USED
#define uart_RXHW_Address_Enabled       uart_RXHW_ADDRESS_ENABLED
#define uart_OverSampleCount            uart_OVER_SAMPLE_COUNT
#define uart_ParityType                 uart_PARITY_TYPE

#if( uart_TX_ENABLED && (uart_TXBUFFERSIZE > uart_FIFO_LENGTH))
    #define uart_TXBUFFER               uart_txBuffer
    #define uart_TXBUFFERREAD           uart_txBufferRead
    #define uart_TXBUFFERWRITE          uart_txBufferWrite
#endif /* End uart_TX_ENABLED */
#if( ( uart_RX_ENABLED || uart_HD_ENABLED ) && \
     (uart_RXBUFFERSIZE > uart_FIFO_LENGTH) )
    #define uart_RXBUFFER               uart_rxBuffer
    #define uart_RXBUFFERREAD           uart_rxBufferRead
    #define uart_RXBUFFERWRITE          uart_rxBufferWrite
    #define uart_RXBUFFERLOOPDETECT     uart_rxBufferLoopDetect
    #define uart_RXBUFFER_OVERFLOW      uart_rxBufferOverflow
#endif /* End uart_RX_ENABLED */

#ifdef uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define uart_CONTROL                uart_CONTROL_REG
#endif /* End uart_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(uart_TX_ENABLED)
    #define uart_TXDATA                 uart_TXDATA_REG
    #define uart_TXSTATUS               uart_TXSTATUS_REG
    #define uart_TXSTATUS_MASK          uart_TXSTATUS_MASK_REG
    #define uart_TXSTATUS_ACTL          uart_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(uart_TXCLKGEN_DP)
        #define uart_TXBITCLKGEN_CTR        uart_TXBITCLKGEN_CTR_REG
        #define uart_TXBITCLKTX_COMPLETE    uart_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define uart_TXBITCTR_PERIOD        uart_TXBITCTR_PERIOD_REG
        #define uart_TXBITCTR_CONTROL       uart_TXBITCTR_CONTROL_REG
        #define uart_TXBITCTR_COUNTER       uart_TXBITCTR_COUNTER_REG
    #endif /* uart_TXCLKGEN_DP */
#endif /* End uart_TX_ENABLED */

#if(uart_HD_ENABLED)
    #define uart_TXDATA                 uart_TXDATA_REG
    #define uart_TXSTATUS               uart_TXSTATUS_REG
    #define uart_TXSTATUS_MASK          uart_TXSTATUS_MASK_REG
    #define uart_TXSTATUS_ACTL          uart_TXSTATUS_ACTL_REG
#endif /* End uart_HD_ENABLED */

#if( (uart_RX_ENABLED) || (uart_HD_ENABLED) )
    #define uart_RXDATA                 uart_RXDATA_REG
    #define uart_RXADDRESS1             uart_RXADDRESS1_REG
    #define uart_RXADDRESS2             uart_RXADDRESS2_REG
    #define uart_RXBITCTR_PERIOD        uart_RXBITCTR_PERIOD_REG
    #define uart_RXBITCTR_CONTROL       uart_RXBITCTR_CONTROL_REG
    #define uart_RXBITCTR_COUNTER       uart_RXBITCTR_COUNTER_REG
    #define uart_RXSTATUS               uart_RXSTATUS_REG
    #define uart_RXSTATUS_MASK          uart_RXSTATUS_MASK_REG
    #define uart_RXSTATUS_ACTL          uart_RXSTATUS_ACTL_REG
#endif /* End  (uart_RX_ENABLED) || (uart_HD_ENABLED) */

#if(uart_INTERNAL_CLOCK_USED)
    #define uart_INTCLOCK_CLKEN         uart_INTCLOCK_CLKEN_REG
#endif /* End uart_INTERNAL_CLOCK_USED */

#define uart_WAIT_FOR_COMLETE_REINIT    uart_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_uart_H */


/* [] END OF FILE */
