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
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* C1 */
.set C1__0__INTTYPE, CYREG_PICU1_INTTYPE6
.set C1__0__MASK, 0x40
.set C1__0__PC, CYREG_PRT1_PC6
.set C1__0__PORT, 1
.set C1__0__SHIFT, 6
.set C1__AG, CYREG_PRT1_AG
.set C1__AMUX, CYREG_PRT1_AMUX
.set C1__BIE, CYREG_PRT1_BIE
.set C1__BIT_MASK, CYREG_PRT1_BIT_MASK
.set C1__BYP, CYREG_PRT1_BYP
.set C1__CTL, CYREG_PRT1_CTL
.set C1__DM0, CYREG_PRT1_DM0
.set C1__DM1, CYREG_PRT1_DM1
.set C1__DM2, CYREG_PRT1_DM2
.set C1__DR, CYREG_PRT1_DR
.set C1__INP_DIS, CYREG_PRT1_INP_DIS
.set C1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU1_BASE
.set C1__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set C1__LCD_EN, CYREG_PRT1_LCD_EN
.set C1__MASK, 0x40
.set C1__PORT, 1
.set C1__PRT, CYREG_PRT1_PRT
.set C1__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set C1__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set C1__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set C1__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set C1__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set C1__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set C1__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set C1__PS, CYREG_PRT1_PS
.set C1__SHIFT, 6
.set C1__SLW, CYREG_PRT1_SLW

/* C2 */
.set C2__0__INTTYPE, CYREG_PICU1_INTTYPE5
.set C2__0__MASK, 0x20
.set C2__0__PC, CYREG_PRT1_PC5
.set C2__0__PORT, 1
.set C2__0__SHIFT, 5
.set C2__AG, CYREG_PRT1_AG
.set C2__AMUX, CYREG_PRT1_AMUX
.set C2__BIE, CYREG_PRT1_BIE
.set C2__BIT_MASK, CYREG_PRT1_BIT_MASK
.set C2__BYP, CYREG_PRT1_BYP
.set C2__CTL, CYREG_PRT1_CTL
.set C2__DM0, CYREG_PRT1_DM0
.set C2__DM1, CYREG_PRT1_DM1
.set C2__DM2, CYREG_PRT1_DM2
.set C2__DR, CYREG_PRT1_DR
.set C2__INP_DIS, CYREG_PRT1_INP_DIS
.set C2__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU1_BASE
.set C2__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set C2__LCD_EN, CYREG_PRT1_LCD_EN
.set C2__MASK, 0x20
.set C2__PORT, 1
.set C2__PRT, CYREG_PRT1_PRT
.set C2__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set C2__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set C2__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set C2__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set C2__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set C2__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set C2__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set C2__PS, CYREG_PRT1_PS
.set C2__SHIFT, 5
.set C2__SLW, CYREG_PRT1_SLW

/* Clock_1 */
.set Clock_1__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set Clock_1__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set Clock_1__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set Clock_1__CFG2_SRC_SEL_MASK, 0x07
.set Clock_1__INDEX, 0x00
.set Clock_1__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_1__PM_ACT_MSK, 0x01
.set Clock_1__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_1__PM_STBY_MSK, 0x01

/* Clock_2 */
.set Clock_2__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set Clock_2__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set Clock_2__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set Clock_2__CFG2_SRC_SEL_MASK, 0x07
.set Clock_2__INDEX, 0x01
.set Clock_2__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_2__PM_ACT_MSK, 0x02
.set Clock_2__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_2__PM_STBY_MSK, 0x02

/* enc */
.set enc_bQuadDec_Stsreg__0__MASK, 0x01
.set enc_bQuadDec_Stsreg__0__POS, 0
.set enc_bQuadDec_Stsreg__1__MASK, 0x02
.set enc_bQuadDec_Stsreg__1__POS, 1
.set enc_bQuadDec_Stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB10_11_ACTL
.set enc_bQuadDec_Stsreg__16BIT_STATUS_REG, CYREG_B1_UDB10_11_ST
.set enc_bQuadDec_Stsreg__2__MASK, 0x04
.set enc_bQuadDec_Stsreg__2__POS, 2
.set enc_bQuadDec_Stsreg__3__MASK, 0x08
.set enc_bQuadDec_Stsreg__3__POS, 3
.set enc_bQuadDec_Stsreg__MASK, 0x0F
.set enc_bQuadDec_Stsreg__MASK_REG, CYREG_B1_UDB10_MSK
.set enc_bQuadDec_Stsreg__STATUS_AUX_CTL_REG, CYREG_B1_UDB10_ACTL
.set enc_bQuadDec_Stsreg__STATUS_REG, CYREG_B1_UDB10_ST
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG, CYREG_B1_UDB08_09_A0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_A1_REG, CYREG_B1_UDB08_09_A1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG, CYREG_B1_UDB08_09_D0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG, CYREG_B1_UDB08_09_D1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB08_09_ACTL
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG, CYREG_B1_UDB08_09_F0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_F1_REG, CYREG_B1_UDB08_09_F1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__A0_A1_REG, CYREG_B1_UDB08_A0_A1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG, CYREG_B1_UDB08_A0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__A1_REG, CYREG_B1_UDB08_A1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__D0_D1_REG, CYREG_B1_UDB08_D0_D1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG, CYREG_B1_UDB08_D0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG, CYREG_B1_UDB08_D1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG, CYREG_B1_UDB08_ACTL
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__F0_F1_REG, CYREG_B1_UDB08_F0_F1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG, CYREG_B1_UDB08_F0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u0__F1_REG, CYREG_B1_UDB08_F1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_A0_REG, CYREG_B1_UDB09_10_A0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_A1_REG, CYREG_B1_UDB09_10_A1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_D0_REG, CYREG_B1_UDB09_10_D0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_D1_REG, CYREG_B1_UDB09_10_D1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB09_10_ACTL
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_F0_REG, CYREG_B1_UDB09_10_F0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__16BIT_F1_REG, CYREG_B1_UDB09_10_F1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__A0_A1_REG, CYREG_B1_UDB09_A0_A1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__A0_REG, CYREG_B1_UDB09_A0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__A1_REG, CYREG_B1_UDB09_A1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__D0_D1_REG, CYREG_B1_UDB09_D0_D1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__D0_REG, CYREG_B1_UDB09_D0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__D1_REG, CYREG_B1_UDB09_D1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG, CYREG_B1_UDB09_ACTL
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__F0_F1_REG, CYREG_B1_UDB09_F0_F1
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__F0_REG, CYREG_B1_UDB09_F0
.set enc_Cnt16_CounterUDB_sC16_counterdp_u1__F1_REG, CYREG_B1_UDB09_F1
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB09_10_ACTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB09_10_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB09_10_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB09_10_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB09_10_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B0_UDB09_10_MSK
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB09_10_MSK
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB09_10_MSK
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB09_10_MSK
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__7__MASK, 0x80
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__7__POS, 7
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB09_ACTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG, CYREG_B0_UDB09_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_ST_REG, CYREG_B0_UDB09_ST_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__COUNT_REG, CYREG_B0_UDB09_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__COUNT_ST_REG, CYREG_B0_UDB09_ST_CTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__MASK, 0x80
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB09_MSK_ACTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB09_MSK_ACTL
.set enc_Cnt16_CounterUDB_sCTRLReg_ctrlreg__PERIOD_REG, CYREG_B0_UDB09_MSK
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__0__MASK, 0x01
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__0__POS, 0
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__1__MASK, 0x02
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__1__POS, 1
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB09_10_ACTL
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__16BIT_STATUS_REG, CYREG_B0_UDB09_10_ST
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__2__MASK, 0x04
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__2__POS, 2
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__3__MASK, 0x08
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__3__POS, 3
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__5__MASK, 0x20
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__5__POS, 5
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__6__MASK, 0x40
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__6__POS, 6
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__MASK, 0x6F
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__MASK_REG, CYREG_B0_UDB09_MSK
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB09_MSK_ACTL
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB09_MSK_ACTL
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG, CYREG_B0_UDB09_ACTL
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_CNT_REG, CYREG_B0_UDB09_ST_CTL
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_CONTROL_REG, CYREG_B0_UDB09_ST_CTL
.set enc_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_REG, CYREG_B0_UDB09_ST
.set enc_isr__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set enc_isr__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set enc_isr__INTC_MASK, 0x01
.set enc_isr__INTC_NUMBER, 0
.set enc_isr__INTC_PRIOR_NUM, 7
.set enc_isr__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set enc_isr__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set enc_isr__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* lcd_LCDPort */
.set lcd_LCDPort__0__INTTYPE, CYREG_PICU2_INTTYPE0
.set lcd_LCDPort__0__MASK, 0x01
.set lcd_LCDPort__0__PC, CYREG_PRT2_PC0
.set lcd_LCDPort__0__PORT, 2
.set lcd_LCDPort__0__SHIFT, 0
.set lcd_LCDPort__1__INTTYPE, CYREG_PICU2_INTTYPE1
.set lcd_LCDPort__1__MASK, 0x02
.set lcd_LCDPort__1__PC, CYREG_PRT2_PC1
.set lcd_LCDPort__1__PORT, 2
.set lcd_LCDPort__1__SHIFT, 1
.set lcd_LCDPort__2__INTTYPE, CYREG_PICU2_INTTYPE2
.set lcd_LCDPort__2__MASK, 0x04
.set lcd_LCDPort__2__PC, CYREG_PRT2_PC2
.set lcd_LCDPort__2__PORT, 2
.set lcd_LCDPort__2__SHIFT, 2
.set lcd_LCDPort__3__INTTYPE, CYREG_PICU2_INTTYPE3
.set lcd_LCDPort__3__MASK, 0x08
.set lcd_LCDPort__3__PC, CYREG_PRT2_PC3
.set lcd_LCDPort__3__PORT, 2
.set lcd_LCDPort__3__SHIFT, 3
.set lcd_LCDPort__4__INTTYPE, CYREG_PICU2_INTTYPE4
.set lcd_LCDPort__4__MASK, 0x10
.set lcd_LCDPort__4__PC, CYREG_PRT2_PC4
.set lcd_LCDPort__4__PORT, 2
.set lcd_LCDPort__4__SHIFT, 4
.set lcd_LCDPort__5__INTTYPE, CYREG_PICU2_INTTYPE5
.set lcd_LCDPort__5__MASK, 0x20
.set lcd_LCDPort__5__PC, CYREG_PRT2_PC5
.set lcd_LCDPort__5__PORT, 2
.set lcd_LCDPort__5__SHIFT, 5
.set lcd_LCDPort__6__INTTYPE, CYREG_PICU2_INTTYPE6
.set lcd_LCDPort__6__MASK, 0x40
.set lcd_LCDPort__6__PC, CYREG_PRT2_PC6
.set lcd_LCDPort__6__PORT, 2
.set lcd_LCDPort__6__SHIFT, 6
.set lcd_LCDPort__AG, CYREG_PRT2_AG
.set lcd_LCDPort__AMUX, CYREG_PRT2_AMUX
.set lcd_LCDPort__BIE, CYREG_PRT2_BIE
.set lcd_LCDPort__BIT_MASK, CYREG_PRT2_BIT_MASK
.set lcd_LCDPort__BYP, CYREG_PRT2_BYP
.set lcd_LCDPort__CTL, CYREG_PRT2_CTL
.set lcd_LCDPort__DM0, CYREG_PRT2_DM0
.set lcd_LCDPort__DM1, CYREG_PRT2_DM1
.set lcd_LCDPort__DM2, CYREG_PRT2_DM2
.set lcd_LCDPort__DR, CYREG_PRT2_DR
.set lcd_LCDPort__INP_DIS, CYREG_PRT2_INP_DIS
.set lcd_LCDPort__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set lcd_LCDPort__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set lcd_LCDPort__LCD_EN, CYREG_PRT2_LCD_EN
.set lcd_LCDPort__MASK, 0x7F
.set lcd_LCDPort__PORT, 2
.set lcd_LCDPort__PRT, CYREG_PRT2_PRT
.set lcd_LCDPort__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set lcd_LCDPort__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set lcd_LCDPort__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set lcd_LCDPort__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set lcd_LCDPort__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set lcd_LCDPort__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set lcd_LCDPort__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set lcd_LCDPort__PS, CYREG_PRT2_PS
.set lcd_LCDPort__SHIFT, 0
.set lcd_LCDPort__SLW, CYREG_PRT2_SLW

/* motora */
.set motora__0__INTTYPE, CYREG_PICU1_INTTYPE2
.set motora__0__MASK, 0x04
.set motora__0__PC, CYREG_PRT1_PC2
.set motora__0__PORT, 1
.set motora__0__SHIFT, 2
.set motora__AG, CYREG_PRT1_AG
.set motora__AMUX, CYREG_PRT1_AMUX
.set motora__BIE, CYREG_PRT1_BIE
.set motora__BIT_MASK, CYREG_PRT1_BIT_MASK
.set motora__BYP, CYREG_PRT1_BYP
.set motora__CTL, CYREG_PRT1_CTL
.set motora__DM0, CYREG_PRT1_DM0
.set motora__DM1, CYREG_PRT1_DM1
.set motora__DM2, CYREG_PRT1_DM2
.set motora__DR, CYREG_PRT1_DR
.set motora__INP_DIS, CYREG_PRT1_INP_DIS
.set motora__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU1_BASE
.set motora__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set motora__LCD_EN, CYREG_PRT1_LCD_EN
.set motora__MASK, 0x04
.set motora__PORT, 1
.set motora__PRT, CYREG_PRT1_PRT
.set motora__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set motora__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set motora__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set motora__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set motora__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set motora__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set motora__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set motora__PS, CYREG_PRT1_PS
.set motora__SHIFT, 2
.set motora__SLW, CYREG_PRT1_SLW

/* motorb */
.set motorb__0__INTTYPE, CYREG_PICU0_INTTYPE7
.set motorb__0__MASK, 0x80
.set motorb__0__PC, CYREG_PRT0_PC7
.set motorb__0__PORT, 0
.set motorb__0__SHIFT, 7
.set motorb__AG, CYREG_PRT0_AG
.set motorb__AMUX, CYREG_PRT0_AMUX
.set motorb__BIE, CYREG_PRT0_BIE
.set motorb__BIT_MASK, CYREG_PRT0_BIT_MASK
.set motorb__BYP, CYREG_PRT0_BYP
.set motorb__CTL, CYREG_PRT0_CTL
.set motorb__DM0, CYREG_PRT0_DM0
.set motorb__DM1, CYREG_PRT0_DM1
.set motorb__DM2, CYREG_PRT0_DM2
.set motorb__DR, CYREG_PRT0_DR
.set motorb__INP_DIS, CYREG_PRT0_INP_DIS
.set motorb__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set motorb__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set motorb__LCD_EN, CYREG_PRT0_LCD_EN
.set motorb__MASK, 0x80
.set motorb__PORT, 0
.set motorb__PRT, CYREG_PRT0_PRT
.set motorb__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set motorb__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set motorb__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set motorb__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set motorb__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set motorb__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set motorb__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set motorb__PS, CYREG_PRT0_PS
.set motorb__SHIFT, 7
.set motorb__SLW, CYREG_PRT0_SLW

/* pwm */
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB07_08_ACTL
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB07_08_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB07_08_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB07_08_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB07_08_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B0_UDB07_08_MSK
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB07_08_MSK
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB07_08_MSK
.set pwm_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB07_08_MSK
.set pwm_PWMUDB_genblk1_ctrlreg__7__MASK, 0x80
.set pwm_PWMUDB_genblk1_ctrlreg__7__POS, 7
.set pwm_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB07_ACTL
.set pwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG, CYREG_B0_UDB07_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG, CYREG_B0_UDB07_ST_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__COUNT_REG, CYREG_B0_UDB07_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG, CYREG_B0_UDB07_ST_CTL
.set pwm_PWMUDB_genblk1_ctrlreg__MASK, 0x80
.set pwm_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB07_MSK_ACTL
.set pwm_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB07_MSK_ACTL
.set pwm_PWMUDB_genblk1_ctrlreg__PERIOD_REG, CYREG_B0_UDB07_MSK
.set pwm_PWMUDB_genblk8_stsreg__0__MASK, 0x01
.set pwm_PWMUDB_genblk8_stsreg__0__POS, 0
.set pwm_PWMUDB_genblk8_stsreg__1__MASK, 0x02
.set pwm_PWMUDB_genblk8_stsreg__1__POS, 1
.set pwm_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB07_08_ACTL
.set pwm_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG, CYREG_B0_UDB07_08_ST
.set pwm_PWMUDB_genblk8_stsreg__2__MASK, 0x04
.set pwm_PWMUDB_genblk8_stsreg__2__POS, 2
.set pwm_PWMUDB_genblk8_stsreg__3__MASK, 0x08
.set pwm_PWMUDB_genblk8_stsreg__3__POS, 3
.set pwm_PWMUDB_genblk8_stsreg__MASK, 0x0F
.set pwm_PWMUDB_genblk8_stsreg__MASK_REG, CYREG_B0_UDB07_MSK
.set pwm_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB07_MSK_ACTL
.set pwm_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB07_MSK_ACTL
.set pwm_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG, CYREG_B0_UDB07_ACTL
.set pwm_PWMUDB_genblk8_stsreg__STATUS_CNT_REG, CYREG_B0_UDB07_ST_CTL
.set pwm_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG, CYREG_B0_UDB07_ST_CTL
.set pwm_PWMUDB_genblk8_stsreg__STATUS_REG, CYREG_B0_UDB07_ST
.set pwm_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG, CYREG_B0_UDB07_08_A0
.set pwm_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG, CYREG_B0_UDB07_08_A1
.set pwm_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG, CYREG_B0_UDB07_08_D0
.set pwm_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG, CYREG_B0_UDB07_08_D1
.set pwm_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB07_08_ACTL
.set pwm_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG, CYREG_B0_UDB07_08_F0
.set pwm_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG, CYREG_B0_UDB07_08_F1
.set pwm_PWMUDB_sP8_pwmdp_u0__A0_A1_REG, CYREG_B0_UDB07_A0_A1
.set pwm_PWMUDB_sP8_pwmdp_u0__A0_REG, CYREG_B0_UDB07_A0
.set pwm_PWMUDB_sP8_pwmdp_u0__A1_REG, CYREG_B0_UDB07_A1
.set pwm_PWMUDB_sP8_pwmdp_u0__D0_D1_REG, CYREG_B0_UDB07_D0_D1
.set pwm_PWMUDB_sP8_pwmdp_u0__D0_REG, CYREG_B0_UDB07_D0
.set pwm_PWMUDB_sP8_pwmdp_u0__D1_REG, CYREG_B0_UDB07_D1
.set pwm_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB07_ACTL
.set pwm_PWMUDB_sP8_pwmdp_u0__F0_F1_REG, CYREG_B0_UDB07_F0_F1
.set pwm_PWMUDB_sP8_pwmdp_u0__F0_REG, CYREG_B0_UDB07_F0
.set pwm_PWMUDB_sP8_pwmdp_u0__F1_REG, CYREG_B0_UDB07_F1
.set pwm_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB07_MSK_ACTL
.set pwm_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG, CYREG_B0_UDB07_MSK_ACTL

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
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
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
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
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
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
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000001
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif