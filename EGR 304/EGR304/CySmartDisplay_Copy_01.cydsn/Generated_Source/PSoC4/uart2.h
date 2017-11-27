/*******************************************************************************
* File Name: uart2.h
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


#if !defined(CY_UART_uart2_H)
#define CY_UART_uart2_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/***************************************
* Conditional Compilation Parameters
***************************************/

#define uart2_RX_ENABLED                     (1u)
#define uart2_TX_ENABLED                     (1u)
#define uart2_HD_ENABLED                     (0u)
#define uart2_RX_INTERRUPT_ENABLED           (0u)
#define uart2_TX_INTERRUPT_ENABLED           (0u)
#define uart2_INTERNAL_CLOCK_USED            (1u)
#define uart2_RXHW_ADDRESS_ENABLED           (0u)
#define uart2_OVER_SAMPLE_COUNT              (8u)
#define uart2_PARITY_TYPE                    (0u)
#define uart2_PARITY_TYPE_SW                 (0u)
#define uart2_BREAK_DETECT                   (0u)
#define uart2_BREAK_BITS_TX                  (13u)
#define uart2_BREAK_BITS_RX                  (13u)
#define uart2_TXCLKGEN_DP                    (1u)
#define uart2_USE23POLLING                   (1u)
#define uart2_FLOW_CONTROL                   (0u)
#define uart2_CLK_FREQ                       (0u)
#define uart2_TX_BUFFER_SIZE                 (4u)
#define uart2_RX_BUFFER_SIZE                 (4u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#if defined(uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG)
    #define uart2_CONTROL_REG_REMOVED            (0u)
#else
    #define uart2_CONTROL_REG_REMOVED            (1u)
#endif /* End uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Structure Definition
***************************************/

/* Sleep Mode API Support */
typedef struct uart2_backupStruct_
{
    uint8 enableState;

    #if(uart2_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End uart2_CONTROL_REG_REMOVED */

} uart2_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void uart2_Start(void) ;
void uart2_Stop(void) ;
uint8 uart2_ReadControlRegister(void) ;
void uart2_WriteControlRegister(uint8 control) ;

void uart2_Init(void) ;
void uart2_Enable(void) ;
void uart2_SaveConfig(void) ;
void uart2_RestoreConfig(void) ;
void uart2_Sleep(void) ;
void uart2_Wakeup(void) ;

/* Only if RX is enabled */
#if( (uart2_RX_ENABLED) || (uart2_HD_ENABLED) )

    #if (uart2_RX_INTERRUPT_ENABLED)
        #define uart2_EnableRxInt()  CyIntEnable (uart2_RX_VECT_NUM)
        #define uart2_DisableRxInt() CyIntDisable(uart2_RX_VECT_NUM)
        CY_ISR_PROTO(uart2_RXISR);
    #endif /* uart2_RX_INTERRUPT_ENABLED */

    void uart2_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void uart2_SetRxAddress1(uint8 address) ;
    void uart2_SetRxAddress2(uint8 address) ;

    void  uart2_SetRxInterruptMode(uint8 intSrc) ;
    uint8 uart2_ReadRxData(void) ;
    uint8 uart2_ReadRxStatus(void) ;
    uint8 uart2_GetChar(void) ;
    uint16 uart2_GetByte(void) ;
    uint8 uart2_GetRxBufferSize(void)
                                                            ;
    void uart2_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define uart2_GetRxInterruptSource   uart2_ReadRxStatus

#endif /* End (uart2_RX_ENABLED) || (uart2_HD_ENABLED) */

/* Only if TX is enabled */
#if(uart2_TX_ENABLED || uart2_HD_ENABLED)

    #if(uart2_TX_INTERRUPT_ENABLED)
        #define uart2_EnableTxInt()  CyIntEnable (uart2_TX_VECT_NUM)
        #define uart2_DisableTxInt() CyIntDisable(uart2_TX_VECT_NUM)
        #define uart2_SetPendingTxInt() CyIntSetPending(uart2_TX_VECT_NUM)
        #define uart2_ClearPendingTxInt() CyIntClearPending(uart2_TX_VECT_NUM)
        CY_ISR_PROTO(uart2_TXISR);
    #endif /* uart2_TX_INTERRUPT_ENABLED */

    void uart2_SetTxInterruptMode(uint8 intSrc) ;
    void uart2_WriteTxData(uint8 txDataByte) ;
    uint8 uart2_ReadTxStatus(void) ;
    void uart2_PutChar(uint8 txDataByte) ;
    void uart2_PutString(const char8 string[]) ;
    void uart2_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void uart2_PutCRLF(uint8 txDataByte) ;
    void uart2_ClearTxBuffer(void) ;
    void uart2_SetTxAddressMode(uint8 addressMode) ;
    void uart2_SendBreak(uint8 retMode) ;
    uint8 uart2_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define uart2_PutStringConst         uart2_PutString
    #define uart2_PutArrayConst          uart2_PutArray
    #define uart2_GetTxInterruptSource   uart2_ReadTxStatus

#endif /* End uart2_TX_ENABLED || uart2_HD_ENABLED */

#if(uart2_HD_ENABLED)
    void uart2_LoadRxConfig(void) ;
    void uart2_LoadTxConfig(void) ;
#endif /* End uart2_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart2) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    uart2_CyBtldrCommStart(void) CYSMALL ;
    void    uart2_CyBtldrCommStop(void) CYSMALL ;
    void    uart2_CyBtldrCommReset(void) CYSMALL ;
    cystatus uart2_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus uart2_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart2)
        #define CyBtldrCommStart    uart2_CyBtldrCommStart
        #define CyBtldrCommStop     uart2_CyBtldrCommStop
        #define CyBtldrCommReset    uart2_CyBtldrCommReset
        #define CyBtldrCommWrite    uart2_CyBtldrCommWrite
        #define CyBtldrCommRead     uart2_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart2) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define uart2_BYTE2BYTE_TIME_OUT (25u)
    #define uart2_PACKET_EOP         (0x17u) /* End of packet defined by bootloader */
    #define uart2_WAIT_EOP_DELAY     (5u)    /* Additional 5ms to wait for End of packet */
    #define uart2_BL_CHK_DELAY_MS    (1u)    /* Time Out quantity equal 1mS */

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define uart2_SET_SPACE      (0x00u)
#define uart2_SET_MARK       (0x01u)

/* Status Register definitions */
#if( (uart2_TX_ENABLED) || (uart2_HD_ENABLED) )
    #if(uart2_TX_INTERRUPT_ENABLED)
        #define uart2_TX_VECT_NUM            (uint8)uart2_TXInternalInterrupt__INTC_NUMBER
        #define uart2_TX_PRIOR_NUM           (uint8)uart2_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* uart2_TX_INTERRUPT_ENABLED */

    #define uart2_TX_STS_COMPLETE_SHIFT          (0x00u)
    #define uart2_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
    #define uart2_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #if(uart2_TX_ENABLED)
        #define uart2_TX_STS_FIFO_FULL_SHIFT     (0x02u)
    #else /* (uart2_HD_ENABLED) */
        #define uart2_TX_STS_FIFO_FULL_SHIFT     (0x05u)  /* Needs MD=0 */
    #endif /* (uart2_TX_ENABLED) */

    #define uart2_TX_STS_COMPLETE            (uint8)(0x01u << uart2_TX_STS_COMPLETE_SHIFT)
    #define uart2_TX_STS_FIFO_EMPTY          (uint8)(0x01u << uart2_TX_STS_FIFO_EMPTY_SHIFT)
    #define uart2_TX_STS_FIFO_FULL           (uint8)(0x01u << uart2_TX_STS_FIFO_FULL_SHIFT)
    #define uart2_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << uart2_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (uart2_TX_ENABLED) || (uart2_HD_ENABLED)*/

#if( (uart2_RX_ENABLED) || (uart2_HD_ENABLED) )
    #if(uart2_RX_INTERRUPT_ENABLED)
        #define uart2_RX_VECT_NUM            (uint8)uart2_RXInternalInterrupt__INTC_NUMBER
        #define uart2_RX_PRIOR_NUM           (uint8)uart2_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* uart2_RX_INTERRUPT_ENABLED */
    #define uart2_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define uart2_RX_STS_BREAK_SHIFT             (0x01u)
    #define uart2_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define uart2_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define uart2_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define uart2_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define uart2_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define uart2_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define uart2_RX_STS_MRKSPC           (uint8)(0x01u << uart2_RX_STS_MRKSPC_SHIFT)
    #define uart2_RX_STS_BREAK            (uint8)(0x01u << uart2_RX_STS_BREAK_SHIFT)
    #define uart2_RX_STS_PAR_ERROR        (uint8)(0x01u << uart2_RX_STS_PAR_ERROR_SHIFT)
    #define uart2_RX_STS_STOP_ERROR       (uint8)(0x01u << uart2_RX_STS_STOP_ERROR_SHIFT)
    #define uart2_RX_STS_OVERRUN          (uint8)(0x01u << uart2_RX_STS_OVERRUN_SHIFT)
    #define uart2_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << uart2_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define uart2_RX_STS_ADDR_MATCH       (uint8)(0x01u << uart2_RX_STS_ADDR_MATCH_SHIFT)
    #define uart2_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << uart2_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define uart2_RX_HW_MASK                     (0x7Fu)
#endif /* End (uart2_RX_ENABLED) || (uart2_HD_ENABLED) */

/* Control Register definitions */
#define uart2_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define uart2_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define uart2_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define uart2_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define uart2_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define uart2_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define uart2_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define uart2_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define uart2_CTRL_HD_SEND               (uint8)(0x01u << uart2_CTRL_HD_SEND_SHIFT)
#define uart2_CTRL_HD_SEND_BREAK         (uint8)(0x01u << uart2_CTRL_HD_SEND_BREAK_SHIFT)
#define uart2_CTRL_MARK                  (uint8)(0x01u << uart2_CTRL_MARK_SHIFT)
#define uart2_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << uart2_CTRL_PARITY_TYPE0_SHIFT)
#define uart2_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << uart2_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define uart2_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define uart2_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define uart2_SEND_BREAK                         (0x00u)
#define uart2_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define uart2_REINIT                             (0x02u)
#define uart2_SEND_WAIT_REINIT                   (0x03u)

#define uart2_OVER_SAMPLE_8                      (8u)
#define uart2_OVER_SAMPLE_16                     (16u)

#define uart2_BIT_CENTER                         (uart2_OVER_SAMPLE_COUNT - 2u)

#define uart2_FIFO_LENGTH                        (4u)
#define uart2_NUMBER_OF_START_BIT                (1u)
#define uart2_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation */
#define uart2_TXBITCTR_BREAKBITS8X   ((uart2_BREAK_BITS_TX * uart2_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation */
#define uart2_TXBITCTR_BREAKBITS ((uart2_BREAK_BITS_TX * uart2_OVER_SAMPLE_COUNT) - 1u)

#define uart2_HALF_BIT_COUNT   \
                            (((uart2_OVER_SAMPLE_COUNT / 2u) + (uart2_USE23POLLING * 1u)) - 2u)
#if (uart2_OVER_SAMPLE_COUNT == uart2_OVER_SAMPLE_8)
    #define uart2_HD_TXBITCTR_INIT   (((uart2_BREAK_BITS_TX + \
                            uart2_NUMBER_OF_START_BIT) * uart2_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define uart2_RXBITCTR_INIT  ((((uart2_BREAK_BITS_RX + uart2_NUMBER_OF_START_BIT) \
                            * uart2_OVER_SAMPLE_COUNT) + uart2_HALF_BIT_COUNT) - 1u)

#else /* uart2_OVER_SAMPLE_COUNT == uart2_OVER_SAMPLE_16 */
    #define uart2_HD_TXBITCTR_INIT   ((8u * uart2_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount = 16 */
    #define uart2_RXBITCTR_INIT      (((7u * uart2_OVER_SAMPLE_COUNT) - 1u) + \
                                                      uart2_HALF_BIT_COUNT)
#endif /* End uart2_OVER_SAMPLE_COUNT */

#define uart2_HD_RXBITCTR_INIT                   uart2_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 uart2_initVar;
#if (uart2_TX_INTERRUPT_ENABLED && uart2_TX_ENABLED)
    extern volatile uint8 uart2_txBuffer[uart2_TX_BUFFER_SIZE];
    extern volatile uint8 uart2_txBufferRead;
    extern uint8 uart2_txBufferWrite;
#endif /* (uart2_TX_INTERRUPT_ENABLED && uart2_TX_ENABLED) */
#if (uart2_RX_INTERRUPT_ENABLED && (uart2_RX_ENABLED || uart2_HD_ENABLED))
    extern uint8 uart2_errorStatus;
    extern volatile uint8 uart2_rxBuffer[uart2_RX_BUFFER_SIZE];
    extern volatile uint8 uart2_rxBufferRead;
    extern volatile uint8 uart2_rxBufferWrite;
    extern volatile uint8 uart2_rxBufferLoopDetect;
    extern volatile uint8 uart2_rxBufferOverflow;
    #if (uart2_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 uart2_rxAddressMode;
        extern volatile uint8 uart2_rxAddressDetected;
    #endif /* (uart2_RXHW_ADDRESS_ENABLED) */
#endif /* (uart2_RX_INTERRUPT_ENABLED && (uart2_RX_ENABLED || uart2_HD_ENABLED)) */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define uart2__B_UART__AM_SW_BYTE_BYTE 1
#define uart2__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define uart2__B_UART__AM_HW_BYTE_BY_BYTE 3
#define uart2__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define uart2__B_UART__AM_NONE 0

#define uart2__B_UART__NONE_REVB 0
#define uart2__B_UART__EVEN_REVB 1
#define uart2__B_UART__ODD_REVB 2
#define uart2__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define uart2_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define uart2_NUMBER_OF_STOP_BITS    (1u)

#if (uart2_RXHW_ADDRESS_ENABLED)
    #define uart2_RX_ADDRESS_MODE    (0u)
    #define uart2_RX_HW_ADDRESS1     (0u)
    #define uart2_RX_HW_ADDRESS2     (0u)
#endif /* (uart2_RXHW_ADDRESS_ENABLED) */

#define uart2_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << uart2_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << uart2_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << uart2_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << uart2_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << uart2_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << uart2_RX_STS_BREAK_SHIFT) \
                                        | (0 << uart2_RX_STS_OVERRUN_SHIFT))

#define uart2_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << uart2_TX_STS_COMPLETE_SHIFT) \
                                        | (0 << uart2_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << uart2_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << uart2_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define uart2_CONTROL_REG \
                            (* (reg8 *) uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define uart2_CONTROL_PTR \
                            (  (reg8 *) uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(uart2_TX_ENABLED)
    #define uart2_TXDATA_REG          (* (reg8 *) uart2_BUART_sTX_TxShifter_u0__F0_REG)
    #define uart2_TXDATA_PTR          (  (reg8 *) uart2_BUART_sTX_TxShifter_u0__F0_REG)
    #define uart2_TXDATA_AUX_CTL_REG  (* (reg8 *) uart2_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define uart2_TXDATA_AUX_CTL_PTR  (  (reg8 *) uart2_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define uart2_TXSTATUS_REG        (* (reg8 *) uart2_BUART_sTX_TxSts__STATUS_REG)
    #define uart2_TXSTATUS_PTR        (  (reg8 *) uart2_BUART_sTX_TxSts__STATUS_REG)
    #define uart2_TXSTATUS_MASK_REG   (* (reg8 *) uart2_BUART_sTX_TxSts__MASK_REG)
    #define uart2_TXSTATUS_MASK_PTR   (  (reg8 *) uart2_BUART_sTX_TxSts__MASK_REG)
    #define uart2_TXSTATUS_ACTL_REG   (* (reg8 *) uart2_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define uart2_TXSTATUS_ACTL_PTR   (  (reg8 *) uart2_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(uart2_TXCLKGEN_DP)
        #define uart2_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define uart2_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define uart2_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define uart2_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define uart2_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define uart2_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define uart2_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define uart2_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define uart2_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define uart2_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) uart2_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* uart2_TXCLKGEN_DP */

#endif /* End uart2_TX_ENABLED */

#if(uart2_HD_ENABLED)

    #define uart2_TXDATA_REG             (* (reg8 *) uart2_BUART_sRX_RxShifter_u0__F1_REG )
    #define uart2_TXDATA_PTR             (  (reg8 *) uart2_BUART_sRX_RxShifter_u0__F1_REG )
    #define uart2_TXDATA_AUX_CTL_REG     (* (reg8 *) uart2_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define uart2_TXDATA_AUX_CTL_PTR     (  (reg8 *) uart2_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define uart2_TXSTATUS_REG           (* (reg8 *) uart2_BUART_sRX_RxSts__STATUS_REG )
    #define uart2_TXSTATUS_PTR           (  (reg8 *) uart2_BUART_sRX_RxSts__STATUS_REG )
    #define uart2_TXSTATUS_MASK_REG      (* (reg8 *) uart2_BUART_sRX_RxSts__MASK_REG )
    #define uart2_TXSTATUS_MASK_PTR      (  (reg8 *) uart2_BUART_sRX_RxSts__MASK_REG )
    #define uart2_TXSTATUS_ACTL_REG      (* (reg8 *) uart2_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define uart2_TXSTATUS_ACTL_PTR      (  (reg8 *) uart2_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End uart2_HD_ENABLED */

#if( (uart2_RX_ENABLED) || (uart2_HD_ENABLED) )
    #define uart2_RXDATA_REG             (* (reg8 *) uart2_BUART_sRX_RxShifter_u0__F0_REG )
    #define uart2_RXDATA_PTR             (  (reg8 *) uart2_BUART_sRX_RxShifter_u0__F0_REG )
    #define uart2_RXADDRESS1_REG         (* (reg8 *) uart2_BUART_sRX_RxShifter_u0__D0_REG )
    #define uart2_RXADDRESS1_PTR         (  (reg8 *) uart2_BUART_sRX_RxShifter_u0__D0_REG )
    #define uart2_RXADDRESS2_REG         (* (reg8 *) uart2_BUART_sRX_RxShifter_u0__D1_REG )
    #define uart2_RXADDRESS2_PTR         (  (reg8 *) uart2_BUART_sRX_RxShifter_u0__D1_REG )
    #define uart2_RXDATA_AUX_CTL_REG     (* (reg8 *) uart2_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define uart2_RXBITCTR_PERIOD_REG    (* (reg8 *) uart2_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define uart2_RXBITCTR_PERIOD_PTR    (  (reg8 *) uart2_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define uart2_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) uart2_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define uart2_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) uart2_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define uart2_RXBITCTR_COUNTER_REG   (* (reg8 *) uart2_BUART_sRX_RxBitCounter__COUNT_REG )
    #define uart2_RXBITCTR_COUNTER_PTR   (  (reg8 *) uart2_BUART_sRX_RxBitCounter__COUNT_REG )

    #define uart2_RXSTATUS_REG           (* (reg8 *) uart2_BUART_sRX_RxSts__STATUS_REG )
    #define uart2_RXSTATUS_PTR           (  (reg8 *) uart2_BUART_sRX_RxSts__STATUS_REG )
    #define uart2_RXSTATUS_MASK_REG      (* (reg8 *) uart2_BUART_sRX_RxSts__MASK_REG )
    #define uart2_RXSTATUS_MASK_PTR      (  (reg8 *) uart2_BUART_sRX_RxSts__MASK_REG )
    #define uart2_RXSTATUS_ACTL_REG      (* (reg8 *) uart2_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define uart2_RXSTATUS_ACTL_PTR      (  (reg8 *) uart2_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (uart2_RX_ENABLED) || (uart2_HD_ENABLED) */

#if(uart2_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define uart2_INTCLOCK_CLKEN_REG     (* (reg8 *) uart2_IntClock__PM_ACT_CFG)
    #define uart2_INTCLOCK_CLKEN_PTR     (  (reg8 *) uart2_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define uart2_INTCLOCK_CLKEN_MASK    uart2_IntClock__PM_ACT_MSK
#endif /* End uart2_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(uart2_TX_ENABLED)
    #define uart2_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End uart2_TX_ENABLED */

#if(uart2_HD_ENABLED)
    #define uart2_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End uart2_HD_ENABLED */

#if( (uart2_RX_ENABLED) || (uart2_HD_ENABLED) )
    #define uart2_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (uart2_RX_ENABLED) || (uart2_HD_ENABLED) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

/* UART v2_40 obsolete definitions */
#define uart2_WAIT_1_MS      uart2_BL_CHK_DELAY_MS   

#define uart2_TXBUFFERSIZE   uart2_TX_BUFFER_SIZE
#define uart2_RXBUFFERSIZE   uart2_RX_BUFFER_SIZE

#if (uart2_RXHW_ADDRESS_ENABLED)
    #define uart2_RXADDRESSMODE  uart2_RX_ADDRESS_MODE
    #define uart2_RXHWADDRESS1   uart2_RX_HW_ADDRESS1
    #define uart2_RXHWADDRESS2   uart2_RX_HW_ADDRESS2
    /* Backward compatible define */
    #define uart2_RXAddressMode  uart2_RXADDRESSMODE
#endif /* (uart2_RXHW_ADDRESS_ENABLED) */

/* UART v2_30 obsolete definitions */
#define uart2_initvar                    uart2_initVar

#define uart2_RX_Enabled                 uart2_RX_ENABLED
#define uart2_TX_Enabled                 uart2_TX_ENABLED
#define uart2_HD_Enabled                 uart2_HD_ENABLED
#define uart2_RX_IntInterruptEnabled     uart2_RX_INTERRUPT_ENABLED
#define uart2_TX_IntInterruptEnabled     uart2_TX_INTERRUPT_ENABLED
#define uart2_InternalClockUsed          uart2_INTERNAL_CLOCK_USED
#define uart2_RXHW_Address_Enabled       uart2_RXHW_ADDRESS_ENABLED
#define uart2_OverSampleCount            uart2_OVER_SAMPLE_COUNT
#define uart2_ParityType                 uart2_PARITY_TYPE

#if( uart2_TX_ENABLED && (uart2_TXBUFFERSIZE > uart2_FIFO_LENGTH))
    #define uart2_TXBUFFER               uart2_txBuffer
    #define uart2_TXBUFFERREAD           uart2_txBufferRead
    #define uart2_TXBUFFERWRITE          uart2_txBufferWrite
#endif /* End uart2_TX_ENABLED */
#if( ( uart2_RX_ENABLED || uart2_HD_ENABLED ) && \
     (uart2_RXBUFFERSIZE > uart2_FIFO_LENGTH) )
    #define uart2_RXBUFFER               uart2_rxBuffer
    #define uart2_RXBUFFERREAD           uart2_rxBufferRead
    #define uart2_RXBUFFERWRITE          uart2_rxBufferWrite
    #define uart2_RXBUFFERLOOPDETECT     uart2_rxBufferLoopDetect
    #define uart2_RXBUFFER_OVERFLOW      uart2_rxBufferOverflow
#endif /* End uart2_RX_ENABLED */

#ifdef uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define uart2_CONTROL                uart2_CONTROL_REG
#endif /* End uart2_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(uart2_TX_ENABLED)
    #define uart2_TXDATA                 uart2_TXDATA_REG
    #define uart2_TXSTATUS               uart2_TXSTATUS_REG
    #define uart2_TXSTATUS_MASK          uart2_TXSTATUS_MASK_REG
    #define uart2_TXSTATUS_ACTL          uart2_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(uart2_TXCLKGEN_DP)
        #define uart2_TXBITCLKGEN_CTR        uart2_TXBITCLKGEN_CTR_REG
        #define uart2_TXBITCLKTX_COMPLETE    uart2_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define uart2_TXBITCTR_PERIOD        uart2_TXBITCTR_PERIOD_REG
        #define uart2_TXBITCTR_CONTROL       uart2_TXBITCTR_CONTROL_REG
        #define uart2_TXBITCTR_COUNTER       uart2_TXBITCTR_COUNTER_REG
    #endif /* uart2_TXCLKGEN_DP */
#endif /* End uart2_TX_ENABLED */

#if(uart2_HD_ENABLED)
    #define uart2_TXDATA                 uart2_TXDATA_REG
    #define uart2_TXSTATUS               uart2_TXSTATUS_REG
    #define uart2_TXSTATUS_MASK          uart2_TXSTATUS_MASK_REG
    #define uart2_TXSTATUS_ACTL          uart2_TXSTATUS_ACTL_REG
#endif /* End uart2_HD_ENABLED */

#if( (uart2_RX_ENABLED) || (uart2_HD_ENABLED) )
    #define uart2_RXDATA                 uart2_RXDATA_REG
    #define uart2_RXADDRESS1             uart2_RXADDRESS1_REG
    #define uart2_RXADDRESS2             uart2_RXADDRESS2_REG
    #define uart2_RXBITCTR_PERIOD        uart2_RXBITCTR_PERIOD_REG
    #define uart2_RXBITCTR_CONTROL       uart2_RXBITCTR_CONTROL_REG
    #define uart2_RXBITCTR_COUNTER       uart2_RXBITCTR_COUNTER_REG
    #define uart2_RXSTATUS               uart2_RXSTATUS_REG
    #define uart2_RXSTATUS_MASK          uart2_RXSTATUS_MASK_REG
    #define uart2_RXSTATUS_ACTL          uart2_RXSTATUS_ACTL_REG
#endif /* End  (uart2_RX_ENABLED) || (uart2_HD_ENABLED) */

#if(uart2_INTERNAL_CLOCK_USED)
    #define uart2_INTCLOCK_CLKEN         uart2_INTCLOCK_CLKEN_REG
#endif /* End uart2_INTERNAL_CLOCK_USED */

#define uart2_WAIT_FOR_COMLETE_REINIT    uart2_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_uart2_H */


/* [] END OF FILE */
