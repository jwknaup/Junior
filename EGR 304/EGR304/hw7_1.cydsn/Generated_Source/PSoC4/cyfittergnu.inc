/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.1 Update 1
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* Rx_1 */
.set Rx_1__0__DR, CYREG_GPIO_PRT0_DR
.set Rx_1__0__DR_CLR, CYREG_GPIO_PRT0_DR_CLR
.set Rx_1__0__DR_INV, CYREG_GPIO_PRT0_DR_INV
.set Rx_1__0__DR_SET, CYREG_GPIO_PRT0_DR_SET
.set Rx_1__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set Rx_1__0__HSIOM_MASK, 0x000F0000
.set Rx_1__0__HSIOM_SHIFT, 16
.set Rx_1__0__INTCFG, CYREG_GPIO_PRT0_INTR_CFG
.set Rx_1__0__INTR, CYREG_GPIO_PRT0_INTR
.set Rx_1__0__INTR_CFG, CYREG_GPIO_PRT0_INTR_CFG
.set Rx_1__0__INTSTAT, CYREG_GPIO_PRT0_INTR
.set Rx_1__0__MASK, 0x10
.set Rx_1__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Rx_1__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Rx_1__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Rx_1__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Rx_1__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Rx_1__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Rx_1__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Rx_1__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Rx_1__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Rx_1__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Rx_1__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Rx_1__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Rx_1__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Rx_1__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Rx_1__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Rx_1__0__PC, CYREG_GPIO_PRT0_PC
.set Rx_1__0__PC2, CYREG_GPIO_PRT0_PC2
.set Rx_1__0__PORT, 0
.set Rx_1__0__PS, CYREG_GPIO_PRT0_PS
.set Rx_1__0__SHIFT, 4
.set Rx_1__DR, CYREG_GPIO_PRT0_DR
.set Rx_1__DR_CLR, CYREG_GPIO_PRT0_DR_CLR
.set Rx_1__DR_INV, CYREG_GPIO_PRT0_DR_INV
.set Rx_1__DR_SET, CYREG_GPIO_PRT0_DR_SET
.set Rx_1__INTCFG, CYREG_GPIO_PRT0_INTR_CFG
.set Rx_1__INTR, CYREG_GPIO_PRT0_INTR
.set Rx_1__INTR_CFG, CYREG_GPIO_PRT0_INTR_CFG
.set Rx_1__INTSTAT, CYREG_GPIO_PRT0_INTR
.set Rx_1__MASK, 0x10
.set Rx_1__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Rx_1__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Rx_1__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Rx_1__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Rx_1__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Rx_1__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Rx_1__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Rx_1__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Rx_1__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Rx_1__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Rx_1__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Rx_1__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Rx_1__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Rx_1__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Rx_1__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Rx_1__PC, CYREG_GPIO_PRT0_PC
.set Rx_1__PC2, CYREG_GPIO_PRT0_PC2
.set Rx_1__PORT, 0
.set Rx_1__PS, CYREG_GPIO_PRT0_PS
.set Rx_1__SHIFT, 4

/* Tx_1 */
.set Tx_1__0__DR, CYREG_GPIO_PRT0_DR
.set Tx_1__0__DR_CLR, CYREG_GPIO_PRT0_DR_CLR
.set Tx_1__0__DR_INV, CYREG_GPIO_PRT0_DR_INV
.set Tx_1__0__DR_SET, CYREG_GPIO_PRT0_DR_SET
.set Tx_1__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set Tx_1__0__HSIOM_MASK, 0x00F00000
.set Tx_1__0__HSIOM_SHIFT, 20
.set Tx_1__0__INTCFG, CYREG_GPIO_PRT0_INTR_CFG
.set Tx_1__0__INTR, CYREG_GPIO_PRT0_INTR
.set Tx_1__0__INTR_CFG, CYREG_GPIO_PRT0_INTR_CFG
.set Tx_1__0__INTSTAT, CYREG_GPIO_PRT0_INTR
.set Tx_1__0__MASK, 0x20
.set Tx_1__0__OUT_SEL, CYREG_UDB_PA0_CFG10
.set Tx_1__0__OUT_SEL_SHIFT, 10
.set Tx_1__0__OUT_SEL_VAL, 3
.set Tx_1__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Tx_1__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Tx_1__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Tx_1__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Tx_1__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Tx_1__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Tx_1__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Tx_1__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Tx_1__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Tx_1__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Tx_1__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Tx_1__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Tx_1__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Tx_1__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Tx_1__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Tx_1__0__PC, CYREG_GPIO_PRT0_PC
.set Tx_1__0__PC2, CYREG_GPIO_PRT0_PC2
.set Tx_1__0__PORT, 0
.set Tx_1__0__PS, CYREG_GPIO_PRT0_PS
.set Tx_1__0__SHIFT, 5
.set Tx_1__DR, CYREG_GPIO_PRT0_DR
.set Tx_1__DR_CLR, CYREG_GPIO_PRT0_DR_CLR
.set Tx_1__DR_INV, CYREG_GPIO_PRT0_DR_INV
.set Tx_1__DR_SET, CYREG_GPIO_PRT0_DR_SET
.set Tx_1__INTCFG, CYREG_GPIO_PRT0_INTR_CFG
.set Tx_1__INTR, CYREG_GPIO_PRT0_INTR
.set Tx_1__INTR_CFG, CYREG_GPIO_PRT0_INTR_CFG
.set Tx_1__INTSTAT, CYREG_GPIO_PRT0_INTR
.set Tx_1__MASK, 0x20
.set Tx_1__PA__CFG0, CYREG_UDB_PA0_CFG0
.set Tx_1__PA__CFG1, CYREG_UDB_PA0_CFG1
.set Tx_1__PA__CFG10, CYREG_UDB_PA0_CFG10
.set Tx_1__PA__CFG11, CYREG_UDB_PA0_CFG11
.set Tx_1__PA__CFG12, CYREG_UDB_PA0_CFG12
.set Tx_1__PA__CFG13, CYREG_UDB_PA0_CFG13
.set Tx_1__PA__CFG14, CYREG_UDB_PA0_CFG14
.set Tx_1__PA__CFG2, CYREG_UDB_PA0_CFG2
.set Tx_1__PA__CFG3, CYREG_UDB_PA0_CFG3
.set Tx_1__PA__CFG4, CYREG_UDB_PA0_CFG4
.set Tx_1__PA__CFG5, CYREG_UDB_PA0_CFG5
.set Tx_1__PA__CFG6, CYREG_UDB_PA0_CFG6
.set Tx_1__PA__CFG7, CYREG_UDB_PA0_CFG7
.set Tx_1__PA__CFG8, CYREG_UDB_PA0_CFG8
.set Tx_1__PA__CFG9, CYREG_UDB_PA0_CFG9
.set Tx_1__PC, CYREG_GPIO_PRT0_PC
.set Tx_1__PC2, CYREG_GPIO_PRT0_PC2
.set Tx_1__PORT, 0
.set Tx_1__PS, CYREG_GPIO_PRT0_PS
.set Tx_1__SHIFT, 5

/* uart_BUART */
.set uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG, CYREG_UDB_W16_ACTL1
.set uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG, CYREG_UDB_W16_CTL1
.set uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG, CYREG_UDB_W16_CTL1
.set uart_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG, CYREG_UDB_W16_CTL1
.set uart_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG, CYREG_UDB_W16_CTL1
.set uart_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG, CYREG_UDB_W16_MSK1
.set uart_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG, CYREG_UDB_W16_MSK1
.set uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG, CYREG_UDB_W16_MSK1
.set uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG, CYREG_UDB_W16_MSK1
.set uart_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG, CYREG_UDB_W8_ACTL1
.set uart_BUART_sRX_RxBitCounter__CONTROL_REG, CYREG_UDB_W8_CTL1
.set uart_BUART_sRX_RxBitCounter__CONTROL_ST_REG, CYREG_UDB_CAT16_CTL_ST1
.set uart_BUART_sRX_RxBitCounter__COUNT_REG, CYREG_UDB_W8_CTL1
.set uart_BUART_sRX_RxBitCounter__COUNT_ST_REG, CYREG_UDB_CAT16_CTL_ST1
.set uart_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK1
.set uart_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK1
.set uart_BUART_sRX_RxBitCounter__PERIOD_REG, CYREG_UDB_W8_MSK1
.set uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG, CYREG_UDB_W16_ACTL1
.set uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG, CYREG_UDB_W16_ST1
.set uart_BUART_sRX_RxBitCounter_ST__MASK_REG, CYREG_UDB_W8_MSK1
.set uart_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK1
.set uart_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK1
.set uart_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG, CYREG_UDB_W8_ACTL1
.set uart_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG, CYREG_UDB_CAT16_CTL_ST1
.set uart_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG, CYREG_UDB_CAT16_CTL_ST1
.set uart_BUART_sRX_RxBitCounter_ST__STATUS_REG, CYREG_UDB_W8_ST1
.set uart_BUART_sRX_RxShifter_u0__16BIT_A0_REG, CYREG_UDB_W16_A01
.set uart_BUART_sRX_RxShifter_u0__16BIT_A1_REG, CYREG_UDB_W16_A11
.set uart_BUART_sRX_RxShifter_u0__16BIT_D0_REG, CYREG_UDB_W16_D01
.set uart_BUART_sRX_RxShifter_u0__16BIT_D1_REG, CYREG_UDB_W16_D11
.set uart_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG, CYREG_UDB_W16_ACTL1
.set uart_BUART_sRX_RxShifter_u0__16BIT_F0_REG, CYREG_UDB_W16_F01
.set uart_BUART_sRX_RxShifter_u0__16BIT_F1_REG, CYREG_UDB_W16_F11
.set uart_BUART_sRX_RxShifter_u0__A0_A1_REG, CYREG_UDB_CAT16_A1
.set uart_BUART_sRX_RxShifter_u0__A0_REG, CYREG_UDB_W8_A01
.set uart_BUART_sRX_RxShifter_u0__A1_REG, CYREG_UDB_W8_A11
.set uart_BUART_sRX_RxShifter_u0__D0_D1_REG, CYREG_UDB_CAT16_D1
.set uart_BUART_sRX_RxShifter_u0__D0_REG, CYREG_UDB_W8_D01
.set uart_BUART_sRX_RxShifter_u0__D1_REG, CYREG_UDB_W8_D11
.set uart_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG, CYREG_UDB_W8_ACTL1
.set uart_BUART_sRX_RxShifter_u0__F0_F1_REG, CYREG_UDB_CAT16_F1
.set uart_BUART_sRX_RxShifter_u0__F0_REG, CYREG_UDB_W8_F01
.set uart_BUART_sRX_RxShifter_u0__F1_REG, CYREG_UDB_W8_F11
.set uart_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK1
.set uart_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG, CYREG_UDB_CAT16_ACTL_MSK1
.set uart_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG, CYREG_UDB_W16_ACTL0
.set uart_BUART_sRX_RxSts__16BIT_STATUS_REG, CYREG_UDB_W16_ST0
.set uart_BUART_sRX_RxSts__3__MASK, 0x08
.set uart_BUART_sRX_RxSts__3__POS, 3
.set uart_BUART_sRX_RxSts__32BIT_MASK_REG, CYREG_UDB_W32_MSK
.set uart_BUART_sRX_RxSts__32BIT_STATUS_AUX_CTL_REG, CYREG_UDB_W32_ACTL
.set uart_BUART_sRX_RxSts__32BIT_STATUS_REG, CYREG_UDB_W32_ST
.set uart_BUART_sRX_RxSts__4__MASK, 0x10
.set uart_BUART_sRX_RxSts__4__POS, 4
.set uart_BUART_sRX_RxSts__5__MASK, 0x20
.set uart_BUART_sRX_RxSts__5__POS, 5
.set uart_BUART_sRX_RxSts__MASK, 0x38
.set uart_BUART_sRX_RxSts__MASK_REG, CYREG_UDB_W8_MSK0
.set uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG, CYREG_UDB_W8_ACTL0
.set uart_BUART_sRX_RxSts__STATUS_REG, CYREG_UDB_W8_ST0
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG, CYREG_UDB_CAT16_A3
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG, CYREG_UDB_W8_A03
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG, CYREG_UDB_W8_A13
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG, CYREG_UDB_CAT16_D3
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG, CYREG_UDB_W8_D03
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG, CYREG_UDB_W8_D13
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG, CYREG_UDB_W8_ACTL3
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG, CYREG_UDB_CAT16_F3
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG, CYREG_UDB_W8_F03
.set uart_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG, CYREG_UDB_W8_F13
.set uart_BUART_sTX_TxShifter_u0__16BIT_A0_REG, CYREG_UDB_W16_A02
.set uart_BUART_sTX_TxShifter_u0__16BIT_A1_REG, CYREG_UDB_W16_A12
.set uart_BUART_sTX_TxShifter_u0__16BIT_D0_REG, CYREG_UDB_W16_D02
.set uart_BUART_sTX_TxShifter_u0__16BIT_D1_REG, CYREG_UDB_W16_D12
.set uart_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG, CYREG_UDB_W16_ACTL2
.set uart_BUART_sTX_TxShifter_u0__16BIT_F0_REG, CYREG_UDB_W16_F02
.set uart_BUART_sTX_TxShifter_u0__16BIT_F1_REG, CYREG_UDB_W16_F12
.set uart_BUART_sTX_TxShifter_u0__A0_A1_REG, CYREG_UDB_CAT16_A2
.set uart_BUART_sTX_TxShifter_u0__A0_REG, CYREG_UDB_W8_A02
.set uart_BUART_sTX_TxShifter_u0__A1_REG, CYREG_UDB_W8_A12
.set uart_BUART_sTX_TxShifter_u0__D0_D1_REG, CYREG_UDB_CAT16_D2
.set uart_BUART_sTX_TxShifter_u0__D0_REG, CYREG_UDB_W8_D02
.set uart_BUART_sTX_TxShifter_u0__D1_REG, CYREG_UDB_W8_D12
.set uart_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG, CYREG_UDB_W8_ACTL2
.set uart_BUART_sTX_TxShifter_u0__F0_F1_REG, CYREG_UDB_CAT16_F2
.set uart_BUART_sTX_TxShifter_u0__F0_REG, CYREG_UDB_W8_F02
.set uart_BUART_sTX_TxShifter_u0__F1_REG, CYREG_UDB_W8_F12
.set uart_BUART_sTX_TxSts__0__MASK, 0x01
.set uart_BUART_sTX_TxSts__0__POS, 0
.set uart_BUART_sTX_TxSts__1__MASK, 0x02
.set uart_BUART_sTX_TxSts__1__POS, 1
.set uart_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG, CYREG_UDB_W16_ACTL2
.set uart_BUART_sTX_TxSts__16BIT_STATUS_REG, CYREG_UDB_W16_ST2
.set uart_BUART_sTX_TxSts__2__MASK, 0x04
.set uart_BUART_sTX_TxSts__2__POS, 2
.set uart_BUART_sTX_TxSts__3__MASK, 0x08
.set uart_BUART_sTX_TxSts__3__POS, 3
.set uart_BUART_sTX_TxSts__MASK, 0x0F
.set uart_BUART_sTX_TxSts__MASK_REG, CYREG_UDB_W8_MSK2
.set uart_BUART_sTX_TxSts__STATUS_AUX_CTL_REG, CYREG_UDB_W8_ACTL2
.set uart_BUART_sTX_TxSts__STATUS_REG, CYREG_UDB_W8_ST2

/* uart_IntClock */
.set uart_IntClock__CTRL_REGISTER, CYREG_PERI_PCLK_CTL11
.set uart_IntClock__DIV_ID, 0x00000040
.set uart_IntClock__DIV_REGISTER, CYREG_PERI_DIV_16_CTL0
.set uart_IntClock__PA_DIV_ID, 0x000000FF

/* Miscellaneous */
.set CYDEV_BCLK__HFCLK__HZ, 48000000
.set CYDEV_BCLK__HFCLK__KHZ, 48000
.set CYDEV_BCLK__HFCLK__MHZ, 48
.set CYDEV_BCLK__SYSCLK__HZ, 48000000
.set CYDEV_BCLK__SYSCLK__KHZ, 48000
.set CYDEV_BCLK__SYSCLK__MHZ, 48
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 16
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x1A1711AA
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 16
.set CYDEV_CHIP_MEMBER_4D, 12
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 17
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 15
.set CYDEV_CHIP_MEMBER_4I, 21
.set CYDEV_CHIP_MEMBER_4J, 13
.set CYDEV_CHIP_MEMBER_4K, 14
.set CYDEV_CHIP_MEMBER_4L, 20
.set CYDEV_CHIP_MEMBER_4M, 19
.set CYDEV_CHIP_MEMBER_4N, 9
.set CYDEV_CHIP_MEMBER_4O, 7
.set CYDEV_CHIP_MEMBER_4P, 18
.set CYDEV_CHIP_MEMBER_4Q, 11
.set CYDEV_CHIP_MEMBER_4R, 8
.set CYDEV_CHIP_MEMBER_4S, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 22
.set CYDEV_CHIP_MEMBER_FM3, 26
.set CYDEV_CHIP_MEMBER_FM4, 27
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 23
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 24
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 25
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4F
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 0
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_Disallowed
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DFT_SELECT_CLK0, 10
.set CYDEV_DFT_SELECT_CLK1, 11
.set CYDEV_DMA_CHANNELS_AVAILABLE, 8
.set CYDEV_HEAP_SIZE, 0x0200
.set CYDEV_IMO_TRIMMED_BY_USB, 0
.set CYDEV_IMO_TRIMMED_BY_WCO, 0
.set CYDEV_INTR_NUMBER_DMA, 21
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYDEV_VDDR_MV, 3300
.set CYDEV_WDT_GENERATE_ISR, 1
.set CYIPBLOCK_m0s8bless_VERSION, 2
.set CYIPBLOCK_m0s8cpussv2_VERSION, 1
.set CYIPBLOCK_m0s8csd_VERSION, 1
.set CYIPBLOCK_m0s8ioss_VERSION, 1
.set CYIPBLOCK_m0s8lcd_VERSION, 2
.set CYIPBLOCK_m0s8lpcomp_VERSION, 2
.set CYIPBLOCK_m0s8peri_VERSION, 1
.set CYIPBLOCK_m0s8scb_VERSION, 2
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 2
.set CYIPBLOCK_m0s8udbif_VERSION, 1
.set CYIPBLOCK_s8pass4al_VERSION, 1
.set DMA_CHANNELS_USED__MASK, 0
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif