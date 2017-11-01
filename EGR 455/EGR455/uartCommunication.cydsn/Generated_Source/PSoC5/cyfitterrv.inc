;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.1 Update 1
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; C1
C1__0__INTTYPE EQU CYREG_PICU1_INTTYPE6
C1__0__MASK EQU 0x40
C1__0__PC EQU CYREG_PRT1_PC6
C1__0__PORT EQU 1
C1__0__SHIFT EQU 6
C1__AG EQU CYREG_PRT1_AG
C1__AMUX EQU CYREG_PRT1_AMUX
C1__BIE EQU CYREG_PRT1_BIE
C1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
C1__BYP EQU CYREG_PRT1_BYP
C1__CTL EQU CYREG_PRT1_CTL
C1__DM0 EQU CYREG_PRT1_DM0
C1__DM1 EQU CYREG_PRT1_DM1
C1__DM2 EQU CYREG_PRT1_DM2
C1__DR EQU CYREG_PRT1_DR
C1__INP_DIS EQU CYREG_PRT1_INP_DIS
C1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
C1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
C1__LCD_EN EQU CYREG_PRT1_LCD_EN
C1__MASK EQU 0x40
C1__PORT EQU 1
C1__PRT EQU CYREG_PRT1_PRT
C1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
C1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
C1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
C1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
C1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
C1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
C1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
C1__PS EQU CYREG_PRT1_PS
C1__SHIFT EQU 6
C1__SLW EQU CYREG_PRT1_SLW

; C2
C2__0__INTTYPE EQU CYREG_PICU1_INTTYPE5
C2__0__MASK EQU 0x20
C2__0__PC EQU CYREG_PRT1_PC5
C2__0__PORT EQU 1
C2__0__SHIFT EQU 5
C2__AG EQU CYREG_PRT1_AG
C2__AMUX EQU CYREG_PRT1_AMUX
C2__BIE EQU CYREG_PRT1_BIE
C2__BIT_MASK EQU CYREG_PRT1_BIT_MASK
C2__BYP EQU CYREG_PRT1_BYP
C2__CTL EQU CYREG_PRT1_CTL
C2__DM0 EQU CYREG_PRT1_DM0
C2__DM1 EQU CYREG_PRT1_DM1
C2__DM2 EQU CYREG_PRT1_DM2
C2__DR EQU CYREG_PRT1_DR
C2__INP_DIS EQU CYREG_PRT1_INP_DIS
C2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
C2__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
C2__LCD_EN EQU CYREG_PRT1_LCD_EN
C2__MASK EQU 0x20
C2__PORT EQU 1
C2__PRT EQU CYREG_PRT1_PRT
C2__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
C2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
C2__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
C2__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
C2__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
C2__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
C2__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
C2__PS EQU CYREG_PRT1_PS
C2__SHIFT EQU 5
C2__SLW EQU CYREG_PRT1_SLW

; Clock_1
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x00
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x01
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x01

; Clock_2
Clock_2__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
Clock_2__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
Clock_2__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
Clock_2__CFG2_SRC_SEL_MASK EQU 0x07
Clock_2__INDEX EQU 0x01
Clock_2__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_2__PM_ACT_MSK EQU 0x02
Clock_2__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_2__PM_STBY_MSK EQU 0x02

; Rx_1
Rx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE6
Rx_1__0__MASK EQU 0x40
Rx_1__0__PC EQU CYREG_PRT12_PC6
Rx_1__0__PORT EQU 12
Rx_1__0__SHIFT EQU 6
Rx_1__AG EQU CYREG_PRT12_AG
Rx_1__BIE EQU CYREG_PRT12_BIE
Rx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Rx_1__BYP EQU CYREG_PRT12_BYP
Rx_1__DM0 EQU CYREG_PRT12_DM0
Rx_1__DM1 EQU CYREG_PRT12_DM1
Rx_1__DM2 EQU CYREG_PRT12_DM2
Rx_1__DR EQU CYREG_PRT12_DR
Rx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Rx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Rx_1__MASK EQU 0x40
Rx_1__PORT EQU 12
Rx_1__PRT EQU CYREG_PRT12_PRT
Rx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Rx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Rx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Rx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Rx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Rx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Rx_1__PS EQU CYREG_PRT12_PS
Rx_1__SHIFT EQU 6
Rx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Rx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Rx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Rx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Rx_1__SLW EQU CYREG_PRT12_SLW

; Tx_1
Tx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE7
Tx_1__0__MASK EQU 0x80
Tx_1__0__PC EQU CYREG_PRT12_PC7
Tx_1__0__PORT EQU 12
Tx_1__0__SHIFT EQU 7
Tx_1__AG EQU CYREG_PRT12_AG
Tx_1__BIE EQU CYREG_PRT12_BIE
Tx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Tx_1__BYP EQU CYREG_PRT12_BYP
Tx_1__DM0 EQU CYREG_PRT12_DM0
Tx_1__DM1 EQU CYREG_PRT12_DM1
Tx_1__DM2 EQU CYREG_PRT12_DM2
Tx_1__DR EQU CYREG_PRT12_DR
Tx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Tx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Tx_1__MASK EQU 0x80
Tx_1__PORT EQU 12
Tx_1__PRT EQU CYREG_PRT12_PRT
Tx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Tx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Tx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Tx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Tx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Tx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Tx_1__PS EQU CYREG_PRT12_PS
Tx_1__SHIFT EQU 7
Tx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Tx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Tx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Tx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Tx_1__SLW EQU CYREG_PRT12_SLW

; enc
enc_bQuadDec_Stsreg__0__MASK EQU 0x01
enc_bQuadDec_Stsreg__0__POS EQU 0
enc_bQuadDec_Stsreg__1__MASK EQU 0x02
enc_bQuadDec_Stsreg__1__POS EQU 1
enc_bQuadDec_Stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
enc_bQuadDec_Stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB13_14_ST
enc_bQuadDec_Stsreg__2__MASK EQU 0x04
enc_bQuadDec_Stsreg__2__POS EQU 2
enc_bQuadDec_Stsreg__3__MASK EQU 0x08
enc_bQuadDec_Stsreg__3__POS EQU 3
enc_bQuadDec_Stsreg__MASK EQU 0x0F
enc_bQuadDec_Stsreg__MASK_REG EQU CYREG_B0_UDB13_MSK
enc_bQuadDec_Stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
enc_bQuadDec_Stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
enc_bQuadDec_Stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
enc_bQuadDec_Stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB13_ST_CTL
enc_bQuadDec_Stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB13_ST_CTL
enc_bQuadDec_Stsreg__STATUS_REG EQU CYREG_B0_UDB13_ST
enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB10_11_A0
enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB10_11_A1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB10_11_D0
enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB10_11_D1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB10_11_F0
enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB10_11_F1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__A0_A1_REG EQU CYREG_B0_UDB10_A0_A1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG EQU CYREG_B0_UDB10_A0
enc_Cnt16_CounterUDB_sC16_counterdp_u0__A1_REG EQU CYREG_B0_UDB10_A1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__D0_D1_REG EQU CYREG_B0_UDB10_D0_D1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG EQU CYREG_B0_UDB10_D0
enc_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG EQU CYREG_B0_UDB10_D1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
enc_Cnt16_CounterUDB_sC16_counterdp_u0__F0_F1_REG EQU CYREG_B0_UDB10_F0_F1
enc_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG EQU CYREG_B0_UDB10_F0
enc_Cnt16_CounterUDB_sC16_counterdp_u0__F1_REG EQU CYREG_B0_UDB10_F1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB11_12_A0
enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB11_12_A1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB11_12_D0
enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB11_12_D1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB11_12_F0
enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB11_12_F1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__A0_A1_REG EQU CYREG_B0_UDB11_A0_A1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__A0_REG EQU CYREG_B0_UDB11_A0
enc_Cnt16_CounterUDB_sC16_counterdp_u1__A1_REG EQU CYREG_B0_UDB11_A1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__D0_D1_REG EQU CYREG_B0_UDB11_D0_D1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__D0_REG EQU CYREG_B0_UDB11_D0
enc_Cnt16_CounterUDB_sC16_counterdp_u1__D1_REG EQU CYREG_B0_UDB11_D1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
enc_Cnt16_CounterUDB_sC16_counterdp_u1__F0_F1_REG EQU CYREG_B0_UDB11_F0_F1
enc_Cnt16_CounterUDB_sC16_counterdp_u1__F0_REG EQU CYREG_B0_UDB11_F0
enc_Cnt16_CounterUDB_sC16_counterdp_u1__F1_REG EQU CYREG_B0_UDB11_F1
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB13_14_MSK
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB13_14_MSK
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__7__MASK EQU 0x80
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__7__POS EQU 7
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB13_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB13_ST_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__COUNT_REG EQU CYREG_B0_UDB13_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB13_ST_CTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__MASK EQU 0x80
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB13_MSK
enc_Cnt16_CounterUDB_sSTSReg_stsreg__0__MASK EQU 0x01
enc_Cnt16_CounterUDB_sSTSReg_stsreg__0__POS EQU 0
enc_Cnt16_CounterUDB_sSTSReg_stsreg__1__MASK EQU 0x02
enc_Cnt16_CounterUDB_sSTSReg_stsreg__1__POS EQU 1
enc_Cnt16_CounterUDB_sSTSReg_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
enc_Cnt16_CounterUDB_sSTSReg_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB11_12_ST
enc_Cnt16_CounterUDB_sSTSReg_stsreg__2__MASK EQU 0x04
enc_Cnt16_CounterUDB_sSTSReg_stsreg__2__POS EQU 2
enc_Cnt16_CounterUDB_sSTSReg_stsreg__3__MASK EQU 0x08
enc_Cnt16_CounterUDB_sSTSReg_stsreg__3__POS EQU 3
enc_Cnt16_CounterUDB_sSTSReg_stsreg__5__MASK EQU 0x20
enc_Cnt16_CounterUDB_sSTSReg_stsreg__5__POS EQU 5
enc_Cnt16_CounterUDB_sSTSReg_stsreg__6__MASK EQU 0x40
enc_Cnt16_CounterUDB_sSTSReg_stsreg__6__POS EQU 6
enc_Cnt16_CounterUDB_sSTSReg_stsreg__MASK EQU 0x6F
enc_Cnt16_CounterUDB_sSTSReg_stsreg__MASK_REG EQU CYREG_B0_UDB11_MSK
enc_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
enc_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_REG EQU CYREG_B0_UDB11_ST
enc_isr__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
enc_isr__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
enc_isr__INTC_MASK EQU 0x01
enc_isr__INTC_NUMBER EQU 0
enc_isr__INTC_PRIOR_NUM EQU 7
enc_isr__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
enc_isr__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
enc_isr__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; lcd_LCDPort
lcd_LCDPort__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
lcd_LCDPort__0__MASK EQU 0x01
lcd_LCDPort__0__PC EQU CYREG_PRT2_PC0
lcd_LCDPort__0__PORT EQU 2
lcd_LCDPort__0__SHIFT EQU 0
lcd_LCDPort__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
lcd_LCDPort__1__MASK EQU 0x02
lcd_LCDPort__1__PC EQU CYREG_PRT2_PC1
lcd_LCDPort__1__PORT EQU 2
lcd_LCDPort__1__SHIFT EQU 1
lcd_LCDPort__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
lcd_LCDPort__2__MASK EQU 0x04
lcd_LCDPort__2__PC EQU CYREG_PRT2_PC2
lcd_LCDPort__2__PORT EQU 2
lcd_LCDPort__2__SHIFT EQU 2
lcd_LCDPort__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
lcd_LCDPort__3__MASK EQU 0x08
lcd_LCDPort__3__PC EQU CYREG_PRT2_PC3
lcd_LCDPort__3__PORT EQU 2
lcd_LCDPort__3__SHIFT EQU 3
lcd_LCDPort__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
lcd_LCDPort__4__MASK EQU 0x10
lcd_LCDPort__4__PC EQU CYREG_PRT2_PC4
lcd_LCDPort__4__PORT EQU 2
lcd_LCDPort__4__SHIFT EQU 4
lcd_LCDPort__5__INTTYPE EQU CYREG_PICU2_INTTYPE5
lcd_LCDPort__5__MASK EQU 0x20
lcd_LCDPort__5__PC EQU CYREG_PRT2_PC5
lcd_LCDPort__5__PORT EQU 2
lcd_LCDPort__5__SHIFT EQU 5
lcd_LCDPort__6__INTTYPE EQU CYREG_PICU2_INTTYPE6
lcd_LCDPort__6__MASK EQU 0x40
lcd_LCDPort__6__PC EQU CYREG_PRT2_PC6
lcd_LCDPort__6__PORT EQU 2
lcd_LCDPort__6__SHIFT EQU 6
lcd_LCDPort__AG EQU CYREG_PRT2_AG
lcd_LCDPort__AMUX EQU CYREG_PRT2_AMUX
lcd_LCDPort__BIE EQU CYREG_PRT2_BIE
lcd_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
lcd_LCDPort__BYP EQU CYREG_PRT2_BYP
lcd_LCDPort__CTL EQU CYREG_PRT2_CTL
lcd_LCDPort__DM0 EQU CYREG_PRT2_DM0
lcd_LCDPort__DM1 EQU CYREG_PRT2_DM1
lcd_LCDPort__DM2 EQU CYREG_PRT2_DM2
lcd_LCDPort__DR EQU CYREG_PRT2_DR
lcd_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
lcd_LCDPort__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
lcd_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
lcd_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
lcd_LCDPort__MASK EQU 0x7F
lcd_LCDPort__PORT EQU 2
lcd_LCDPort__PRT EQU CYREG_PRT2_PRT
lcd_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
lcd_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
lcd_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
lcd_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
lcd_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
lcd_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
lcd_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
lcd_LCDPort__PS EQU CYREG_PRT2_PS
lcd_LCDPort__SHIFT EQU 0
lcd_LCDPort__SLW EQU CYREG_PRT2_SLW

; motora
motora__0__INTTYPE EQU CYREG_PICU1_INTTYPE2
motora__0__MASK EQU 0x04
motora__0__PC EQU CYREG_PRT1_PC2
motora__0__PORT EQU 1
motora__0__SHIFT EQU 2
motora__AG EQU CYREG_PRT1_AG
motora__AMUX EQU CYREG_PRT1_AMUX
motora__BIE EQU CYREG_PRT1_BIE
motora__BIT_MASK EQU CYREG_PRT1_BIT_MASK
motora__BYP EQU CYREG_PRT1_BYP
motora__CTL EQU CYREG_PRT1_CTL
motora__DM0 EQU CYREG_PRT1_DM0
motora__DM1 EQU CYREG_PRT1_DM1
motora__DM2 EQU CYREG_PRT1_DM2
motora__DR EQU CYREG_PRT1_DR
motora__INP_DIS EQU CYREG_PRT1_INP_DIS
motora__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
motora__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
motora__LCD_EN EQU CYREG_PRT1_LCD_EN
motora__MASK EQU 0x04
motora__PORT EQU 1
motora__PRT EQU CYREG_PRT1_PRT
motora__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
motora__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
motora__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
motora__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
motora__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
motora__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
motora__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
motora__PS EQU CYREG_PRT1_PS
motora__SHIFT EQU 2
motora__SLW EQU CYREG_PRT1_SLW

; motorb
motorb__0__INTTYPE EQU CYREG_PICU0_INTTYPE7
motorb__0__MASK EQU 0x80
motorb__0__PC EQU CYREG_PRT0_PC7
motorb__0__PORT EQU 0
motorb__0__SHIFT EQU 7
motorb__AG EQU CYREG_PRT0_AG
motorb__AMUX EQU CYREG_PRT0_AMUX
motorb__BIE EQU CYREG_PRT0_BIE
motorb__BIT_MASK EQU CYREG_PRT0_BIT_MASK
motorb__BYP EQU CYREG_PRT0_BYP
motorb__CTL EQU CYREG_PRT0_CTL
motorb__DM0 EQU CYREG_PRT0_DM0
motorb__DM1 EQU CYREG_PRT0_DM1
motorb__DM2 EQU CYREG_PRT0_DM2
motorb__DR EQU CYREG_PRT0_DR
motorb__INP_DIS EQU CYREG_PRT0_INP_DIS
motorb__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
motorb__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
motorb__LCD_EN EQU CYREG_PRT0_LCD_EN
motorb__MASK EQU 0x80
motorb__PORT EQU 0
motorb__PRT EQU CYREG_PRT0_PRT
motorb__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
motorb__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
motorb__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
motorb__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
motorb__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
motorb__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
motorb__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
motorb__PS EQU CYREG_PRT0_PS
motorb__SHIFT EQU 7
motorb__SLW EQU CYREG_PRT0_SLW

; pwm
pwm_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB06_07_ACTL
pwm_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB06_07_CTL
pwm_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB06_07_CTL
pwm_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB06_07_CTL
pwm_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB06_07_CTL
pwm_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB06_07_MSK
pwm_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB06_07_MSK
pwm_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB06_07_MSK
pwm_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB06_07_MSK
pwm_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
pwm_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
pwm_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB06_ACTL
pwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB06_CTL
pwm_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB06_ST_CTL
pwm_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_B0_UDB06_CTL
pwm_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB06_ST_CTL
pwm_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
pwm_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB06_MSK_ACTL
pwm_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB06_MSK_ACTL
pwm_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB06_MSK
pwm_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
pwm_PWMUDB_genblk8_stsreg__0__POS EQU 0
pwm_PWMUDB_genblk8_stsreg__1__MASK EQU 0x02
pwm_PWMUDB_genblk8_stsreg__1__POS EQU 1
pwm_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB07_08_ACTL
pwm_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB07_08_ST
pwm_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
pwm_PWMUDB_genblk8_stsreg__2__POS EQU 2
pwm_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
pwm_PWMUDB_genblk8_stsreg__3__POS EQU 3
pwm_PWMUDB_genblk8_stsreg__MASK EQU 0x0F
pwm_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB07_MSK
pwm_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB07_ACTL
pwm_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB07_ST
pwm_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB07_08_A0
pwm_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB07_08_A1
pwm_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB07_08_D0
pwm_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB07_08_D1
pwm_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB07_08_ACTL
pwm_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB07_08_F0
pwm_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB07_08_F1
pwm_PWMUDB_sP8_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB07_A0_A1
pwm_PWMUDB_sP8_pwmdp_u0__A0_REG EQU CYREG_B0_UDB07_A0
pwm_PWMUDB_sP8_pwmdp_u0__A1_REG EQU CYREG_B0_UDB07_A1
pwm_PWMUDB_sP8_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB07_D0_D1
pwm_PWMUDB_sP8_pwmdp_u0__D0_REG EQU CYREG_B0_UDB07_D0
pwm_PWMUDB_sP8_pwmdp_u0__D1_REG EQU CYREG_B0_UDB07_D1
pwm_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB07_ACTL
pwm_PWMUDB_sP8_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB07_F0_F1
pwm_PWMUDB_sP8_pwmdp_u0__F0_REG EQU CYREG_B0_UDB07_F0
pwm_PWMUDB_sP8_pwmdp_u0__F1_REG EQU CYREG_B0_UDB07_F1

; uart_BUART
uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
uart_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
uart_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
uart_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB09_10_MSK
uart_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB09_10_MSK
uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
uart_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
uart_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB09_CTL
uart_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB09_ST_CTL
uart_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB09_CTL
uart_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB09_ST_CTL
uart_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
uart_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
uart_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB09_MSK
uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB09_10_ST
uart_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB09_MSK
uart_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
uart_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB09_ST_CTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB09_ST_CTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB09_ST
uart_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B1_UDB10_11_A0
uart_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B1_UDB10_11_A1
uart_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B1_UDB10_11_D0
uart_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B1_UDB10_11_D1
uart_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
uart_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B1_UDB10_11_F0
uart_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B1_UDB10_11_F1
uart_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B1_UDB10_A0_A1
uart_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B1_UDB10_A0
uart_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B1_UDB10_A1
uart_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B1_UDB10_D0_D1
uart_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B1_UDB10_D0
uart_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B1_UDB10_D1
uart_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
uart_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B1_UDB10_F0_F1
uart_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B1_UDB10_F0
uart_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B1_UDB10_F1
uart_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
uart_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB10_11_ST
uart_BUART_sRX_RxSts__3__MASK EQU 0x08
uart_BUART_sRX_RxSts__3__POS EQU 3
uart_BUART_sRX_RxSts__4__MASK EQU 0x10
uart_BUART_sRX_RxSts__4__POS EQU 4
uart_BUART_sRX_RxSts__5__MASK EQU 0x20
uart_BUART_sRX_RxSts__5__POS EQU 5
uart_BUART_sRX_RxSts__MASK EQU 0x38
uart_BUART_sRX_RxSts__MASK_REG EQU CYREG_B1_UDB10_MSK
uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
uart_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B1_UDB10_ST
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B1_UDB09_10_A0
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B1_UDB09_10_A1
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B1_UDB09_10_D0
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B1_UDB09_10_D1
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B1_UDB09_10_F0
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B1_UDB09_10_F1
uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B1_UDB09_A0_A1
uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B1_UDB09_A0
uart_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B1_UDB09_A1
uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B1_UDB09_D0_D1
uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B1_UDB09_D0
uart_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B1_UDB09_D1
uart_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B1_UDB09_F0_F1
uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B1_UDB09_F0
uart_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B1_UDB09_F1
uart_BUART_sTX_sCLOCK_TxBitClkGen__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
uart_BUART_sTX_sCLOCK_TxBitClkGen__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
uart_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB09_10_A0
uart_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB09_10_A1
uart_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB09_10_D0
uart_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB09_10_D1
uart_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
uart_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB09_10_F0
uart_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB09_10_F1
uart_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB09_A0_A1
uart_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB09_A0
uart_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB09_A1
uart_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB09_D0_D1
uart_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB09_D0
uart_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB09_D1
uart_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
uart_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB09_F0_F1
uart_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB09_F0
uart_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB09_F1
uart_BUART_sTX_TxSts__0__MASK EQU 0x01
uart_BUART_sTX_TxSts__0__POS EQU 0
uart_BUART_sTX_TxSts__1__MASK EQU 0x02
uart_BUART_sTX_TxSts__1__POS EQU 1
uart_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
uart_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB09_10_ST
uart_BUART_sTX_TxSts__2__MASK EQU 0x04
uart_BUART_sTX_TxSts__2__POS EQU 2
uart_BUART_sTX_TxSts__3__MASK EQU 0x08
uart_BUART_sTX_TxSts__3__POS EQU 3
uart_BUART_sTX_TxSts__MASK EQU 0x0F
uart_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB09_MSK
uart_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
uart_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB09_ST

; uart_IntClock
uart_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG2_CFG0
uart_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG2_CFG1
uart_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG2_CFG2
uart_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
uart_IntClock__INDEX EQU 0x02
uart_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
uart_IntClock__PM_ACT_MSK EQU 0x04
uart_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
uart_IntClock__PM_STBY_MSK EQU 0x04

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 16
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 16
CYDEV_CHIP_MEMBER_4D EQU 12
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 17
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 15
CYDEV_CHIP_MEMBER_4I EQU 21
CYDEV_CHIP_MEMBER_4J EQU 13
CYDEV_CHIP_MEMBER_4K EQU 14
CYDEV_CHIP_MEMBER_4L EQU 20
CYDEV_CHIP_MEMBER_4M EQU 19
CYDEV_CHIP_MEMBER_4N EQU 9
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 18
CYDEV_CHIP_MEMBER_4Q EQU 11
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 22
CYDEV_CHIP_MEMBER_FM3 EQU 26
CYDEV_CHIP_MEMBER_FM4 EQU 27
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 23
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 24
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 25
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 0
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000001
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END