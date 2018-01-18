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
    GET cydevicerv_trm.inc

; A0
A0__0__DR EQU CYREG_GPIO_PRT2_DR
A0__0__DR_CLR EQU CYREG_GPIO_PRT2_DR_CLR
A0__0__DR_INV EQU CYREG_GPIO_PRT2_DR_INV
A0__0__DR_SET EQU CYREG_GPIO_PRT2_DR_SET
A0__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
A0__0__HSIOM_MASK EQU 0x0000000F
A0__0__HSIOM_SHIFT EQU 0
A0__0__INTCFG EQU CYREG_GPIO_PRT2_INTR_CFG
A0__0__INTR EQU CYREG_GPIO_PRT2_INTR
A0__0__INTR_CFG EQU CYREG_GPIO_PRT2_INTR_CFG
A0__0__INTSTAT EQU CYREG_GPIO_PRT2_INTR
A0__0__MASK EQU 0x01
A0__0__OUT_SEL EQU CYREG_UDB_PA2_CFG10
A0__0__OUT_SEL_SHIFT EQU 0
A0__0__OUT_SEL_VAL EQU 2
A0__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
A0__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
A0__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
A0__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
A0__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
A0__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
A0__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
A0__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
A0__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
A0__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
A0__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
A0__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
A0__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
A0__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
A0__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
A0__0__PC EQU CYREG_GPIO_PRT2_PC
A0__0__PC2 EQU CYREG_GPIO_PRT2_PC2
A0__0__PORT EQU 2
A0__0__PS EQU CYREG_GPIO_PRT2_PS
A0__0__SHIFT EQU 0
A0__DR EQU CYREG_GPIO_PRT2_DR
A0__DR_CLR EQU CYREG_GPIO_PRT2_DR_CLR
A0__DR_INV EQU CYREG_GPIO_PRT2_DR_INV
A0__DR_SET EQU CYREG_GPIO_PRT2_DR_SET
A0__INTCFG EQU CYREG_GPIO_PRT2_INTR_CFG
A0__INTR EQU CYREG_GPIO_PRT2_INTR
A0__INTR_CFG EQU CYREG_GPIO_PRT2_INTR_CFG
A0__INTSTAT EQU CYREG_GPIO_PRT2_INTR
A0__MASK EQU 0x01
A0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
A0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
A0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
A0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
A0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
A0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
A0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
A0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
A0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
A0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
A0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
A0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
A0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
A0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
A0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
A0__PC EQU CYREG_GPIO_PRT2_PC
A0__PC2 EQU CYREG_GPIO_PRT2_PC2
A0__PORT EQU 2
A0__PS EQU CYREG_GPIO_PRT2_PS
A0__SHIFT EQU 0

; ADC
ADC_cy_psoc4_sar__CLOCK_DIV_ID EQU 0x00000041
ADC_cy_psoc4_sar__SAR_ANA_TRIM EQU CYREG_SAR_ANA_TRIM
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG00 EQU CYREG_SAR_CHAN_CONFIG0
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG01 EQU CYREG_SAR_CHAN_CONFIG1
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG02 EQU CYREG_SAR_CHAN_CONFIG2
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG03 EQU CYREG_SAR_CHAN_CONFIG3
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG04 EQU CYREG_SAR_CHAN_CONFIG4
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG05 EQU CYREG_SAR_CHAN_CONFIG5
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG06 EQU CYREG_SAR_CHAN_CONFIG6
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG07 EQU CYREG_SAR_CHAN_CONFIG7
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG08 EQU CYREG_SAR_CHAN_CONFIG8
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG09 EQU CYREG_SAR_CHAN_CONFIG9
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG10 EQU CYREG_SAR_CHAN_CONFIG10
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG11 EQU CYREG_SAR_CHAN_CONFIG11
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG12 EQU CYREG_SAR_CHAN_CONFIG12
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG13 EQU CYREG_SAR_CHAN_CONFIG13
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG14 EQU CYREG_SAR_CHAN_CONFIG14
ADC_cy_psoc4_sar__SAR_CHAN_CONFIG15 EQU CYREG_SAR_CHAN_CONFIG15
ADC_cy_psoc4_sar__SAR_CHAN_EN EQU CYREG_SAR_CHAN_EN
ADC_cy_psoc4_sar__SAR_CHAN_RESULT_VALID EQU CYREG_SAR_CHAN_RESULT_VALID
ADC_cy_psoc4_sar__SAR_CHAN_RESULT00 EQU CYREG_SAR_CHAN_RESULT0
ADC_cy_psoc4_sar__SAR_CHAN_RESULT01 EQU CYREG_SAR_CHAN_RESULT1
ADC_cy_psoc4_sar__SAR_CHAN_RESULT02 EQU CYREG_SAR_CHAN_RESULT2
ADC_cy_psoc4_sar__SAR_CHAN_RESULT03 EQU CYREG_SAR_CHAN_RESULT3
ADC_cy_psoc4_sar__SAR_CHAN_RESULT04 EQU CYREG_SAR_CHAN_RESULT4
ADC_cy_psoc4_sar__SAR_CHAN_RESULT05 EQU CYREG_SAR_CHAN_RESULT5
ADC_cy_psoc4_sar__SAR_CHAN_RESULT06 EQU CYREG_SAR_CHAN_RESULT6
ADC_cy_psoc4_sar__SAR_CHAN_RESULT07 EQU CYREG_SAR_CHAN_RESULT7
ADC_cy_psoc4_sar__SAR_CHAN_RESULT08 EQU CYREG_SAR_CHAN_RESULT8
ADC_cy_psoc4_sar__SAR_CHAN_RESULT09 EQU CYREG_SAR_CHAN_RESULT9
ADC_cy_psoc4_sar__SAR_CHAN_RESULT10 EQU CYREG_SAR_CHAN_RESULT10
ADC_cy_psoc4_sar__SAR_CHAN_RESULT11 EQU CYREG_SAR_CHAN_RESULT11
ADC_cy_psoc4_sar__SAR_CHAN_RESULT12 EQU CYREG_SAR_CHAN_RESULT12
ADC_cy_psoc4_sar__SAR_CHAN_RESULT13 EQU CYREG_SAR_CHAN_RESULT13
ADC_cy_psoc4_sar__SAR_CHAN_RESULT14 EQU CYREG_SAR_CHAN_RESULT14
ADC_cy_psoc4_sar__SAR_CHAN_RESULT15 EQU CYREG_SAR_CHAN_RESULT15
ADC_cy_psoc4_sar__SAR_CHAN_WORK_VALID EQU CYREG_SAR_CHAN_WORK_VALID
ADC_cy_psoc4_sar__SAR_CHAN_WORK00 EQU CYREG_SAR_CHAN_WORK0
ADC_cy_psoc4_sar__SAR_CHAN_WORK01 EQU CYREG_SAR_CHAN_WORK1
ADC_cy_psoc4_sar__SAR_CHAN_WORK02 EQU CYREG_SAR_CHAN_WORK2
ADC_cy_psoc4_sar__SAR_CHAN_WORK03 EQU CYREG_SAR_CHAN_WORK3
ADC_cy_psoc4_sar__SAR_CHAN_WORK04 EQU CYREG_SAR_CHAN_WORK4
ADC_cy_psoc4_sar__SAR_CHAN_WORK05 EQU CYREG_SAR_CHAN_WORK5
ADC_cy_psoc4_sar__SAR_CHAN_WORK06 EQU CYREG_SAR_CHAN_WORK6
ADC_cy_psoc4_sar__SAR_CHAN_WORK07 EQU CYREG_SAR_CHAN_WORK7
ADC_cy_psoc4_sar__SAR_CHAN_WORK08 EQU CYREG_SAR_CHAN_WORK8
ADC_cy_psoc4_sar__SAR_CHAN_WORK09 EQU CYREG_SAR_CHAN_WORK9
ADC_cy_psoc4_sar__SAR_CHAN_WORK10 EQU CYREG_SAR_CHAN_WORK10
ADC_cy_psoc4_sar__SAR_CHAN_WORK11 EQU CYREG_SAR_CHAN_WORK11
ADC_cy_psoc4_sar__SAR_CHAN_WORK12 EQU CYREG_SAR_CHAN_WORK12
ADC_cy_psoc4_sar__SAR_CHAN_WORK13 EQU CYREG_SAR_CHAN_WORK13
ADC_cy_psoc4_sar__SAR_CHAN_WORK14 EQU CYREG_SAR_CHAN_WORK14
ADC_cy_psoc4_sar__SAR_CHAN_WORK15 EQU CYREG_SAR_CHAN_WORK15
ADC_cy_psoc4_sar__SAR_CTRL EQU CYREG_SAR_CTRL
ADC_cy_psoc4_sar__SAR_DFT_CTRL EQU CYREG_SAR_DFT_CTRL
ADC_cy_psoc4_sar__SAR_INTR EQU CYREG_SAR_INTR
ADC_cy_psoc4_sar__SAR_INTR_CAUSE EQU CYREG_SAR_INTR_CAUSE
ADC_cy_psoc4_sar__SAR_INTR_MASK EQU CYREG_SAR_INTR_MASK
ADC_cy_psoc4_sar__SAR_INTR_MASKED EQU CYREG_SAR_INTR_MASKED
ADC_cy_psoc4_sar__SAR_INTR_SET EQU CYREG_SAR_INTR_SET
ADC_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL EQU CYREG_SAR_MUX_SWITCH_HW_CTRL
ADC_cy_psoc4_sar__SAR_MUX_SWITCH0 EQU CYREG_SAR_MUX_SWITCH0
ADC_cy_psoc4_sar__SAR_NUMBER EQU 0
ADC_cy_psoc4_sar__SAR_PUMP_CTRL EQU CYREG_SAR_PUMP_CTRL
ADC_cy_psoc4_sar__SAR_RANGE_COND EQU CYREG_SAR_RANGE_COND
ADC_cy_psoc4_sar__SAR_RANGE_INTR EQU CYREG_SAR_RANGE_INTR
ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASK EQU CYREG_SAR_RANGE_INTR_MASK
ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASKED EQU CYREG_SAR_RANGE_INTR_MASKED
ADC_cy_psoc4_sar__SAR_RANGE_INTR_SET EQU CYREG_SAR_RANGE_INTR_SET
ADC_cy_psoc4_sar__SAR_RANGE_THRES EQU CYREG_SAR_RANGE_THRES
ADC_cy_psoc4_sar__SAR_SAMPLE_CTRL EQU CYREG_SAR_SAMPLE_CTRL
ADC_cy_psoc4_sar__SAR_SAMPLE_TIME01 EQU CYREG_SAR_SAMPLE_TIME01
ADC_cy_psoc4_sar__SAR_SAMPLE_TIME23 EQU CYREG_SAR_SAMPLE_TIME23
ADC_cy_psoc4_sar__SAR_SATURATE_INTR EQU CYREG_SAR_SATURATE_INTR
ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASK EQU CYREG_SAR_SATURATE_INTR_MASK
ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED EQU CYREG_SAR_SATURATE_INTR_MASKED
ADC_cy_psoc4_sar__SAR_SATURATE_INTR_SET EQU CYREG_SAR_SATURATE_INTR_SET
ADC_cy_psoc4_sar__SAR_START_CTRL EQU CYREG_SAR_START_CTRL
ADC_cy_psoc4_sar__SAR_STATUS EQU CYREG_SAR_STATUS
ADC_cy_psoc4_sar__SAR_WOUNDING EQU CYREG_SAR_WOUNDING
ADC_intClock__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL6
ADC_intClock__DIV_ID EQU 0x00000041
ADC_intClock__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL1
ADC_intClock__PA_DIV_ID EQU 0x000000FF
ADC_IRQ__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
ADC_IRQ__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
ADC_IRQ__INTC_MASK EQU 0x8000
ADC_IRQ__INTC_NUMBER EQU 15
ADC_IRQ__INTC_PRIOR_MASK EQU 0xC0000000
ADC_IRQ__INTC_PRIOR_NUM EQU 3
ADC_IRQ__INTC_PRIOR_REG EQU CYREG_CM0_IPR3
ADC_IRQ__INTC_SET_EN_REG EQU CYREG_CM0_ISER
ADC_IRQ__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Clock_PWM
Clock_PWM__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL10
Clock_PWM__DIV_ID EQU 0x00000040
Clock_PWM__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL0
Clock_PWM__PA_DIV_ID EQU 0x000000FF

; PWM_B
PWM_B_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT1_CC
PWM_B_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT1_CC_BUFF
PWM_B_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT1_COUNTER
PWM_B_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT1_CTRL
PWM_B_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT1_INTR
PWM_B_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT1_INTR_MASK
PWM_B_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT1_INTR_MASKED
PWM_B_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT1_INTR_SET
PWM_B_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT1_PERIOD
PWM_B_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT1_PERIOD_BUFF
PWM_B_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT1_STATUS
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x02
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 1
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x200
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 9
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x2000000
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 25
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x20000
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 17
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x02
PWM_B_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 1
PWM_B_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_B_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x02
PWM_B_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 1
PWM_B_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 1
PWM_B_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT1_TR_CTRL0
PWM_B_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT1_TR_CTRL1
PWM_B_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT1_TR_CTRL2

; PWM_G
PWM_G_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT3_CC
PWM_G_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT3_CC_BUFF
PWM_G_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT3_COUNTER
PWM_G_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT3_CTRL
PWM_G_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT3_INTR
PWM_G_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT3_INTR_MASK
PWM_G_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT3_INTR_MASKED
PWM_G_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT3_INTR_SET
PWM_G_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT3_PERIOD
PWM_G_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT3_PERIOD_BUFF
PWM_G_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT3_STATUS
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x08
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 3
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x800
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 11
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x8000000
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 27
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x80000
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 19
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x08
PWM_G_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 3
PWM_G_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_G_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x08
PWM_G_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 3
PWM_G_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 3
PWM_G_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT3_TR_CTRL0
PWM_G_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT3_TR_CTRL1
PWM_G_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT3_TR_CTRL2

; PWM_R
PWM_R_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
PWM_R_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
PWM_R_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
PWM_R_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
PWM_R_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
PWM_R_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
PWM_R_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
PWM_R_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
PWM_R_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
PWM_R_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
PWM_R_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
PWM_R_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
PWM_R_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_R_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
PWM_R_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
PWM_R_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
PWM_R_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
PWM_R_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
PWM_R_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

; Pin_BlueLED
Pin_BlueLED__0__DR EQU CYREG_GPIO_PRT3_DR
Pin_BlueLED__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
Pin_BlueLED__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
Pin_BlueLED__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
Pin_BlueLED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
Pin_BlueLED__0__HSIOM_MASK EQU 0xF0000000
Pin_BlueLED__0__HSIOM_SHIFT EQU 28
Pin_BlueLED__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_BlueLED__0__INTR EQU CYREG_GPIO_PRT3_INTR
Pin_BlueLED__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_BlueLED__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
Pin_BlueLED__0__MASK EQU 0x80
Pin_BlueLED__0__OUT_SEL EQU CYREG_UDB_PA3_CFG10
Pin_BlueLED__0__OUT_SEL_SHIFT EQU 14
Pin_BlueLED__0__OUT_SEL_VAL EQU 3
Pin_BlueLED__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
Pin_BlueLED__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
Pin_BlueLED__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
Pin_BlueLED__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
Pin_BlueLED__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
Pin_BlueLED__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
Pin_BlueLED__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
Pin_BlueLED__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
Pin_BlueLED__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
Pin_BlueLED__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
Pin_BlueLED__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
Pin_BlueLED__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
Pin_BlueLED__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
Pin_BlueLED__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
Pin_BlueLED__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
Pin_BlueLED__0__PC EQU CYREG_GPIO_PRT3_PC
Pin_BlueLED__0__PC2 EQU CYREG_GPIO_PRT3_PC2
Pin_BlueLED__0__PORT EQU 3
Pin_BlueLED__0__PS EQU CYREG_GPIO_PRT3_PS
Pin_BlueLED__0__SHIFT EQU 7
Pin_BlueLED__DR EQU CYREG_GPIO_PRT3_DR
Pin_BlueLED__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
Pin_BlueLED__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
Pin_BlueLED__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
Pin_BlueLED__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_BlueLED__INTR EQU CYREG_GPIO_PRT3_INTR
Pin_BlueLED__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_BlueLED__INTSTAT EQU CYREG_GPIO_PRT3_INTR
Pin_BlueLED__MASK EQU 0x80
Pin_BlueLED__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
Pin_BlueLED__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
Pin_BlueLED__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
Pin_BlueLED__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
Pin_BlueLED__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
Pin_BlueLED__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
Pin_BlueLED__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
Pin_BlueLED__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
Pin_BlueLED__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
Pin_BlueLED__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
Pin_BlueLED__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
Pin_BlueLED__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
Pin_BlueLED__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
Pin_BlueLED__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
Pin_BlueLED__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
Pin_BlueLED__PC EQU CYREG_GPIO_PRT3_PC
Pin_BlueLED__PC2 EQU CYREG_GPIO_PRT3_PC2
Pin_BlueLED__PORT EQU 3
Pin_BlueLED__PS EQU CYREG_GPIO_PRT3_PS
Pin_BlueLED__SHIFT EQU 7

; Pin_GreenLED
Pin_GreenLED__0__DR EQU CYREG_GPIO_PRT3_DR
Pin_GreenLED__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
Pin_GreenLED__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
Pin_GreenLED__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
Pin_GreenLED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
Pin_GreenLED__0__HSIOM_MASK EQU 0x0F000000
Pin_GreenLED__0__HSIOM_SHIFT EQU 24
Pin_GreenLED__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_GreenLED__0__INTR EQU CYREG_GPIO_PRT3_INTR
Pin_GreenLED__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_GreenLED__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
Pin_GreenLED__0__MASK EQU 0x40
Pin_GreenLED__0__OUT_SEL EQU CYREG_UDB_PA3_CFG10
Pin_GreenLED__0__OUT_SEL_SHIFT EQU 12
Pin_GreenLED__0__OUT_SEL_VAL EQU -1
Pin_GreenLED__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
Pin_GreenLED__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
Pin_GreenLED__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
Pin_GreenLED__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
Pin_GreenLED__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
Pin_GreenLED__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
Pin_GreenLED__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
Pin_GreenLED__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
Pin_GreenLED__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
Pin_GreenLED__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
Pin_GreenLED__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
Pin_GreenLED__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
Pin_GreenLED__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
Pin_GreenLED__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
Pin_GreenLED__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
Pin_GreenLED__0__PC EQU CYREG_GPIO_PRT3_PC
Pin_GreenLED__0__PC2 EQU CYREG_GPIO_PRT3_PC2
Pin_GreenLED__0__PORT EQU 3
Pin_GreenLED__0__PS EQU CYREG_GPIO_PRT3_PS
Pin_GreenLED__0__SHIFT EQU 6
Pin_GreenLED__DR EQU CYREG_GPIO_PRT3_DR
Pin_GreenLED__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
Pin_GreenLED__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
Pin_GreenLED__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
Pin_GreenLED__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_GreenLED__INTR EQU CYREG_GPIO_PRT3_INTR
Pin_GreenLED__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
Pin_GreenLED__INTSTAT EQU CYREG_GPIO_PRT3_INTR
Pin_GreenLED__MASK EQU 0x40
Pin_GreenLED__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
Pin_GreenLED__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
Pin_GreenLED__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
Pin_GreenLED__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
Pin_GreenLED__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
Pin_GreenLED__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
Pin_GreenLED__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
Pin_GreenLED__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
Pin_GreenLED__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
Pin_GreenLED__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
Pin_GreenLED__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
Pin_GreenLED__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
Pin_GreenLED__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
Pin_GreenLED__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
Pin_GreenLED__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
Pin_GreenLED__PC EQU CYREG_GPIO_PRT3_PC
Pin_GreenLED__PC2 EQU CYREG_GPIO_PRT3_PC2
Pin_GreenLED__PORT EQU 3
Pin_GreenLED__PS EQU CYREG_GPIO_PRT3_PS
Pin_GreenLED__SHIFT EQU 6

; Pin_RedLED
Pin_RedLED__0__DR EQU CYREG_GPIO_PRT2_DR
Pin_RedLED__0__DR_CLR EQU CYREG_GPIO_PRT2_DR_CLR
Pin_RedLED__0__DR_INV EQU CYREG_GPIO_PRT2_DR_INV
Pin_RedLED__0__DR_SET EQU CYREG_GPIO_PRT2_DR_SET
Pin_RedLED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
Pin_RedLED__0__HSIOM_MASK EQU 0x0F000000
Pin_RedLED__0__HSIOM_SHIFT EQU 24
Pin_RedLED__0__INTCFG EQU CYREG_GPIO_PRT2_INTR_CFG
Pin_RedLED__0__INTR EQU CYREG_GPIO_PRT2_INTR
Pin_RedLED__0__INTR_CFG EQU CYREG_GPIO_PRT2_INTR_CFG
Pin_RedLED__0__INTSTAT EQU CYREG_GPIO_PRT2_INTR
Pin_RedLED__0__MASK EQU 0x40
Pin_RedLED__0__OUT_SEL EQU CYREG_UDB_PA2_CFG10
Pin_RedLED__0__OUT_SEL_SHIFT EQU 12
Pin_RedLED__0__OUT_SEL_VAL EQU 1
Pin_RedLED__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin_RedLED__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin_RedLED__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin_RedLED__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin_RedLED__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin_RedLED__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin_RedLED__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin_RedLED__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin_RedLED__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin_RedLED__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin_RedLED__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin_RedLED__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin_RedLED__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin_RedLED__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin_RedLED__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin_RedLED__0__PC EQU CYREG_GPIO_PRT2_PC
Pin_RedLED__0__PC2 EQU CYREG_GPIO_PRT2_PC2
Pin_RedLED__0__PORT EQU 2
Pin_RedLED__0__PS EQU CYREG_GPIO_PRT2_PS
Pin_RedLED__0__SHIFT EQU 6
Pin_RedLED__DR EQU CYREG_GPIO_PRT2_DR
Pin_RedLED__DR_CLR EQU CYREG_GPIO_PRT2_DR_CLR
Pin_RedLED__DR_INV EQU CYREG_GPIO_PRT2_DR_INV
Pin_RedLED__DR_SET EQU CYREG_GPIO_PRT2_DR_SET
Pin_RedLED__INTCFG EQU CYREG_GPIO_PRT2_INTR_CFG
Pin_RedLED__INTR EQU CYREG_GPIO_PRT2_INTR
Pin_RedLED__INTR_CFG EQU CYREG_GPIO_PRT2_INTR_CFG
Pin_RedLED__INTSTAT EQU CYREG_GPIO_PRT2_INTR
Pin_RedLED__MASK EQU 0x40
Pin_RedLED__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin_RedLED__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin_RedLED__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin_RedLED__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin_RedLED__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin_RedLED__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin_RedLED__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin_RedLED__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin_RedLED__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin_RedLED__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin_RedLED__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin_RedLED__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin_RedLED__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin_RedLED__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin_RedLED__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin_RedLED__PC EQU CYREG_GPIO_PRT2_PC
Pin_RedLED__PC2 EQU CYREG_GPIO_PRT2_PC2
Pin_RedLED__PORT EQU 2
Pin_RedLED__PS EQU CYREG_GPIO_PRT2_PS
Pin_RedLED__SHIFT EQU 6

; Rx_1
Rx_1__0__DR EQU CYREG_GPIO_PRT0_DR
Rx_1__0__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
Rx_1__0__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
Rx_1__0__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
Rx_1__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Rx_1__0__HSIOM_MASK EQU 0x000F0000
Rx_1__0__HSIOM_SHIFT EQU 16
Rx_1__0__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
Rx_1__0__INTR EQU CYREG_GPIO_PRT0_INTR
Rx_1__0__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
Rx_1__0__INTSTAT EQU CYREG_GPIO_PRT0_INTR
Rx_1__0__MASK EQU 0x10
Rx_1__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Rx_1__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Rx_1__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Rx_1__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Rx_1__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Rx_1__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Rx_1__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Rx_1__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Rx_1__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Rx_1__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Rx_1__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Rx_1__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Rx_1__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Rx_1__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Rx_1__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Rx_1__0__PC EQU CYREG_GPIO_PRT0_PC
Rx_1__0__PC2 EQU CYREG_GPIO_PRT0_PC2
Rx_1__0__PORT EQU 0
Rx_1__0__PS EQU CYREG_GPIO_PRT0_PS
Rx_1__0__SHIFT EQU 4
Rx_1__DR EQU CYREG_GPIO_PRT0_DR
Rx_1__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
Rx_1__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
Rx_1__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
Rx_1__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
Rx_1__INTR EQU CYREG_GPIO_PRT0_INTR
Rx_1__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
Rx_1__INTSTAT EQU CYREG_GPIO_PRT0_INTR
Rx_1__MASK EQU 0x10
Rx_1__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Rx_1__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Rx_1__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Rx_1__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Rx_1__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Rx_1__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Rx_1__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Rx_1__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Rx_1__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Rx_1__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Rx_1__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Rx_1__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Rx_1__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Rx_1__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Rx_1__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Rx_1__PC EQU CYREG_GPIO_PRT0_PC
Rx_1__PC2 EQU CYREG_GPIO_PRT0_PC2
Rx_1__PORT EQU 0
Rx_1__PS EQU CYREG_GPIO_PRT0_PS
Rx_1__SHIFT EQU 4

; Tx_1
Tx_1__0__DR EQU CYREG_GPIO_PRT0_DR
Tx_1__0__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
Tx_1__0__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
Tx_1__0__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
Tx_1__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Tx_1__0__HSIOM_MASK EQU 0x00F00000
Tx_1__0__HSIOM_SHIFT EQU 20
Tx_1__0__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
Tx_1__0__INTR EQU CYREG_GPIO_PRT0_INTR
Tx_1__0__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
Tx_1__0__INTSTAT EQU CYREG_GPIO_PRT0_INTR
Tx_1__0__MASK EQU 0x20
Tx_1__0__OUT_SEL EQU CYREG_UDB_PA0_CFG10
Tx_1__0__OUT_SEL_SHIFT EQU 10
Tx_1__0__OUT_SEL_VAL EQU 2
Tx_1__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Tx_1__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Tx_1__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Tx_1__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Tx_1__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Tx_1__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Tx_1__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Tx_1__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Tx_1__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Tx_1__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Tx_1__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Tx_1__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Tx_1__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Tx_1__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Tx_1__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Tx_1__0__PC EQU CYREG_GPIO_PRT0_PC
Tx_1__0__PC2 EQU CYREG_GPIO_PRT0_PC2
Tx_1__0__PORT EQU 0
Tx_1__0__PS EQU CYREG_GPIO_PRT0_PS
Tx_1__0__SHIFT EQU 5
Tx_1__DR EQU CYREG_GPIO_PRT0_DR
Tx_1__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
Tx_1__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
Tx_1__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
Tx_1__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
Tx_1__INTR EQU CYREG_GPIO_PRT0_INTR
Tx_1__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
Tx_1__INTSTAT EQU CYREG_GPIO_PRT0_INTR
Tx_1__MASK EQU 0x20
Tx_1__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Tx_1__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Tx_1__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Tx_1__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Tx_1__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Tx_1__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Tx_1__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Tx_1__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Tx_1__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Tx_1__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Tx_1__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Tx_1__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Tx_1__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Tx_1__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Tx_1__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Tx_1__PC EQU CYREG_GPIO_PRT0_PC
Tx_1__PC2 EQU CYREG_GPIO_PRT0_PC2
Tx_1__PORT EQU 0
Tx_1__PS EQU CYREG_GPIO_PRT0_PS
Tx_1__SHIFT EQU 5

; UART_1_BUART
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_UDB_W16_CTL0
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_UDB_W16_CTL0
UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_UDB_W16_CTL0
UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_UDB_W16_CTL0
UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_UDB_W16_MSK0
UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_UDB_W16_MSK0
UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_UDB_W16_MSK0
UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_UDB_W16_MSK0
UART_1_BUART_sRX_RxBitCounter__32BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
UART_1_BUART_sRX_RxBitCounter__32BIT_CONTROL_REG EQU CYREG_UDB_W32_CTL
UART_1_BUART_sRX_RxBitCounter__32BIT_COUNT_REG EQU CYREG_UDB_W32_CTL
UART_1_BUART_sRX_RxBitCounter__32BIT_PERIOD_REG EQU CYREG_UDB_W32_MSK
UART_1_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
UART_1_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_UDB_W8_CTL0
UART_1_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST0
UART_1_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_UDB_W8_CTL0
UART_1_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST0
UART_1_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
UART_1_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
UART_1_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_UDB_W8_MSK0
UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_UDB_W16_ST0
UART_1_BUART_sRX_RxBitCounter_ST__32BIT_MASK_REG EQU CYREG_UDB_W32_MSK
UART_1_BUART_sRX_RxBitCounter_ST__32BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__32BIT_STATUS_REG EQU CYREG_UDB_W32_ST
UART_1_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_UDB_W8_MSK0
UART_1_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
UART_1_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_UDB_CAT16_CTL_ST0
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_UDB_CAT16_CTL_ST0
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_UDB_W8_ST0
UART_1_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_UDB_W16_A00
UART_1_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_UDB_W16_A10
UART_1_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_UDB_W16_D00
UART_1_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_UDB_W16_D10
UART_1_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
UART_1_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_UDB_W16_F00
UART_1_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_UDB_W16_F10
UART_1_BUART_sRX_RxShifter_u0__32BIT_A0_REG EQU CYREG_UDB_W32_A0
UART_1_BUART_sRX_RxShifter_u0__32BIT_A1_REG EQU CYREG_UDB_W32_A1
UART_1_BUART_sRX_RxShifter_u0__32BIT_D0_REG EQU CYREG_UDB_W32_D0
UART_1_BUART_sRX_RxShifter_u0__32BIT_D1_REG EQU CYREG_UDB_W32_D1
UART_1_BUART_sRX_RxShifter_u0__32BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
UART_1_BUART_sRX_RxShifter_u0__32BIT_F0_REG EQU CYREG_UDB_W32_F0
UART_1_BUART_sRX_RxShifter_u0__32BIT_F1_REG EQU CYREG_UDB_W32_F1
UART_1_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A0
UART_1_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_UDB_W8_A00
UART_1_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_UDB_W8_A10
UART_1_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D0
UART_1_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_UDB_W8_D00
UART_1_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_UDB_W8_D10
UART_1_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
UART_1_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F0
UART_1_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_UDB_W8_F00
UART_1_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_UDB_W8_F10
UART_1_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
UART_1_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
UART_1_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL1
UART_1_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_UDB_W16_ST1
UART_1_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_1_BUART_sRX_RxSts__3__POS EQU 3
UART_1_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_1_BUART_sRX_RxSts__4__POS EQU 4
UART_1_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_1_BUART_sRX_RxSts__5__POS EQU 5
UART_1_BUART_sRX_RxSts__MASK EQU 0x38
UART_1_BUART_sRX_RxSts__MASK_REG EQU CYREG_UDB_W8_MSK1
UART_1_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL1
UART_1_BUART_sRX_RxSts__STATUS_REG EQU CYREG_UDB_W8_ST1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_UDB_W16_A02
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_UDB_W16_A12
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_UDB_W16_D02
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_UDB_W16_D12
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL2
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_UDB_W16_F02
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_UDB_W16_F12
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_UDB_CAT16_A2
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_UDB_W8_A02
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_UDB_W8_A12
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_UDB_CAT16_D2
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_UDB_W8_D02
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_UDB_W8_D12
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL2
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_UDB_CAT16_F2
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_UDB_W8_F02
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_UDB_W8_F12
UART_1_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A3
UART_1_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_UDB_W8_A03
UART_1_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_UDB_W8_A13
UART_1_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D3
UART_1_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_UDB_W8_D03
UART_1_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_UDB_W8_D13
UART_1_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL3
UART_1_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F3
UART_1_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_UDB_W8_F03
UART_1_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_UDB_W8_F13
UART_1_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_1_BUART_sTX_TxSts__0__POS EQU 0
UART_1_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_1_BUART_sTX_TxSts__1__POS EQU 1
UART_1_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_1_BUART_sTX_TxSts__2__POS EQU 2
UART_1_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_1_BUART_sTX_TxSts__3__POS EQU 3
UART_1_BUART_sTX_TxSts__MASK EQU 0x0F
UART_1_BUART_sTX_TxSts__MASK_REG EQU CYREG_UDB_W8_MSK3
UART_1_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL3
UART_1_BUART_sTX_TxSts__STATUS_REG EQU CYREG_UDB_W8_ST3

; UART_1_IntClock
UART_1_IntClock__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL11
UART_1_IntClock__DIV_ID EQU 0x00000042
UART_1_IntClock__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL2
UART_1_IntClock__PA_DIV_ID EQU 0x000000FF

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
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
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x1A1711AA
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
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4F
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
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 10
CYDEV_DFT_SELECT_CLK1 EQU 11
CYDEV_DMA_CHANNELS_AVAILABLE EQU 8
CYDEV_HEAP_SIZE EQU 0x0100
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_INTR_NUMBER_DMA EQU 21
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDR_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 0
CYIPBLOCK_m0s8bless_VERSION EQU 2
CYIPBLOCK_m0s8cpussv2_VERSION EQU 1
CYIPBLOCK_m0s8csd_VERSION EQU 1
CYIPBLOCK_m0s8ioss_VERSION EQU 1
CYIPBLOCK_m0s8lcd_VERSION EQU 2
CYIPBLOCK_m0s8lpcomp_VERSION EQU 2
CYIPBLOCK_m0s8peri_VERSION EQU 1
CYIPBLOCK_m0s8scb_VERSION EQU 2
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 2
CYIPBLOCK_m0s8udbif_VERSION EQU 1
CYIPBLOCK_s8pass4al_VERSION EQU 1
DMA_CHANNELS_USED__MASK EQU 0
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END