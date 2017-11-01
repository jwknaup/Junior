/*******************************************************************************
* File Name: adc.h
* Version 2.0
*
* Description:
*  Contains the function prototypes, constants and register definition of the
*  ADC SAR Sequencer Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_adc_H)
    #define CY_adc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "adc_TempBuf_dma.h"
#include "adc_FinalBuf_dma.h"
#include "adc_SAR.h"

#define adc_NUMBER_OF_CHANNELS    (1u)
#define adc_SAMPLE_MODE           (0u)
#define adc_CLOCK_SOURCE          (0u)

extern int16  adc_finalArray[adc_NUMBER_OF_CHANNELS];
extern uint32 adc_initVar;

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ADC_SAR_SEQ_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*        Function Prototypes
***************************************/
void adc_Init(void);
void adc_Enable(void);
void adc_Disable(void);
void adc_Start(void);
void adc_Stop(void);

uint32 adc_IsEndConversion(uint8 retMode);
int16 adc_GetResult16(uint16 chan);
int16 adc_GetAdcResult(void);
void adc_SetOffset(int32 offset);
void adc_SetResolution(uint8 resolution);
void adc_SetScaledGain(int32 adcGain);
int32 adc_CountsTo_mVolts(int16 adcCounts);
int32 adc_CountsTo_uVolts(int16 adcCounts);
float32 adc_CountsTo_Volts(int16 adcCounts);
void adc_Sleep(void);
void adc_Wakeup(void);
void adc_SaveConfig(void);
void adc_RestoreConfig(void);

CY_ISR_PROTO( adc_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void adc_SetGain(int32 adcGain);


/**************************************
*    Initial Parameter Constants
**************************************/
#define adc_IRQ_REMOVE             (0u)                /* Removes internal interrupt */


/***************************************
*             Registers
***************************************/
#define adc_CYCLE_COUNTER_AUX_CONTROL_REG \
                                               (*(reg8 *) adc_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define adc_CYCLE_COUNTER_AUX_CONTROL_PTR \
                                               ( (reg8 *) adc_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define adc_CONTROL_REG    (*(reg8 *) \
                                             adc_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define adc_CONTROL_PTR    ( (reg8 *) \
                                             adc_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define adc_COUNT_REG      (*(reg8 *) \
                                             adc_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define adc_COUNT_PTR      ( (reg8 *) \
                                             adc_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define adc_STATUS_REG     (*(reg8 *) adc_bSAR_SEQ_EOCSts__STATUS_REG)
#define adc_STATUS_PTR     ( (reg8 *) adc_bSAR_SEQ_EOCSts__STATUS_REG)

#define adc_SAR_DATA_ADDR_0 (adc_SAR_ADC_SAR__WRK0)
#define adc_SAR_DATA_ADDR_1 (adc_SAR_ADC_SAR__WRK1)
#define adc_SAR_DATA_ADDR_0_REG (*(reg8 *) \
                                              adc_SAR_ADC_SAR__WRK0)
#define adc_SAR_DATA_ADDR_1_REG (*(reg8 *) \
                                              adc_SAR_ADC_SAR__WRK1)


/**************************************
*       Register Constants
**************************************/

#if(adc_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define adc_INTC_PRIOR_NUMBER          (uint8)(adc_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define adc_INTC_NUMBER                (uint8)(adc_IRQ__INTC_NUMBER)

#endif   /* End adc_IRQ_REMOVE */


/***************************************
*       API Constants
***************************************/

/* Constants for IsEndConversion() "retMode" parameter */
#define adc_RETURN_STATUS              (0x01u)
#define adc_WAIT_FOR_RESULT            (0x00u)

/* Defines for the Resolution parameter */
#define adc_BITS_12    adc_SAR__BITS_12
#define adc_BITS_10    adc_SAR__BITS_10
#define adc_BITS_8     adc_SAR__BITS_8

#define adc_CYCLE_COUNTER_ENABLE    (0x20u)
#define adc_BASE_COMPONENT_ENABLE   (0x01u)
#define adc_LOAD_COUNTER_PERIOD     (0x02u)
#define adc_SOFTWARE_SOC_PULSE      (0x04u)

/* Generic DMA Configuration parameters */
#define adc_TEMP_BYTES_PER_BURST     (uint8)(2u)
#define adc_TEMP_TRANSFER_COUNT      ((uint16)adc_NUMBER_OF_CHANNELS << 1u)
#define adc_FINAL_BYTES_PER_BURST    ((uint16)adc_NUMBER_OF_CHANNELS << 1u)
#define adc_REQUEST_PER_BURST        (uint8)(1u)

#define adc_GET_RESULT_INDEX_OFFSET    ((uint8)adc_NUMBER_OF_CHANNELS - 1u)

/* Define for Sample Mode  */
#define adc_SAMPLE_MODE_FREE_RUNNING    (0x00u)
#define adc_SAMPLE_MODE_SW_TRIGGERED    (0x01u)
#define adc_SAMPLE_MODE_HW_TRIGGERED    (0x02u)

/* Define for Clock Source  */
#define adc_CLOCK_INTERNAL              (0x00u)
#define adc_CLOCK_EXTERNAL              (0x01u)


/***************************************
*        Optional Function Prototypes
***************************************/
#if(adc_SAMPLE_MODE != adc_SAMPLE_MODE_HW_TRIGGERED)
    void adc_StartConvert(void);
    void adc_StopConvert(void);
#endif /* adc_SAMPLE_MODE != adc_SAMPLE_MODE_HW_TRIGGERED */

#endif  /* !defined(CY_adc_H) */

/* [] END OF FILE */
