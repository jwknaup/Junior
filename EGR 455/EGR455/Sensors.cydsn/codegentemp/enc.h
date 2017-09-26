/*******************************************************************************
* File Name: enc.h  
* Version 3.0
*
* Description:
*  This file provides constants and parameter values for the Quadrature
*  Decoder component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_QUADRATURE_DECODER_enc_H)
#define CY_QUADRATURE_DECODER_enc_H

#include "cyfitter.h"
#include "CyLib.h"
#include "cytypes.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component QuadDec_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#define enc_COUNTER_SIZE               (32u)
#define enc_COUNTER_SIZE_8_BIT         (8u)
#define enc_COUNTER_SIZE_16_BIT        (16u)
#define enc_COUNTER_SIZE_32_BIT        (32u)

#if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
    #include "enc_Cnt8.h"
#else 
    /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) || 
    *  (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT) 
    */
    #include "enc_Cnt16.h"
#endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT */

extern uint8 enc_initVar;


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define enc_COUNTER_RESOLUTION         (4u)


/***************************************
*       Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} enc_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  enc_Init(void) ;
void  enc_Start(void) ;
void  enc_Stop(void) ;
void  enc_Enable(void) ;
uint8 enc_GetEvents(void) ;
void  enc_SetInterruptMask(uint8 mask) ;
uint8 enc_GetInterruptMask(void) ;
int32 enc_GetCounter(void) ;
void  enc_SetCounter(int32 value)
;
void  enc_Sleep(void) ;
void  enc_Wakeup(void) ;
void  enc_SaveConfig(void) ;
void  enc_RestoreConfig(void) ;

#if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
    CY_ISR_PROTO(enc_ISR);
#endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */


/***************************************
*           API Constants
***************************************/

#if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
    #define enc_ISR_NUMBER             ((uint8) enc_isr__INTC_NUMBER)
    #define enc_ISR_PRIORITY           ((uint8) enc_isr__INTC_PRIOR_NUM)
#endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define enc_GLITCH_FILTERING           (0u)
#define enc_INDEX_INPUT                (0u)


/***************************************
*    Initial Parameter Constants
***************************************/

#if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
    #define enc_COUNTER_INIT_VALUE    (0x80u)
#else 
    /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) ||
    *  (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
    */
    #define enc_COUNTER_INIT_VALUE    (0x8000u)
    #define enc_COUNTER_MAX_VALUE     (0x7FFFu)
#endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT */


/***************************************
*             Registers
***************************************/

#define enc_STATUS_REG                 (* (reg8 *) enc_bQuadDec_Stsreg__STATUS_REG)
#define enc_STATUS_PTR                 (  (reg8 *) enc_bQuadDec_Stsreg__STATUS_REG)
#define enc_STATUS_MASK                (* (reg8 *) enc_bQuadDec_Stsreg__MASK_REG)
#define enc_STATUS_MASK_PTR            (  (reg8 *) enc_bQuadDec_Stsreg__MASK_REG)
#define enc_SR_AUX_CONTROL             (* (reg8 *) enc_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)
#define enc_SR_AUX_CONTROL_PTR         (  (reg8 *) enc_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)


/***************************************
*        Register Constants
***************************************/

#define enc_COUNTER_OVERFLOW_SHIFT     (0x00u)
#define enc_COUNTER_UNDERFLOW_SHIFT    (0x01u)
#define enc_COUNTER_RESET_SHIFT        (0x02u)
#define enc_INVALID_IN_SHIFT           (0x03u)
#define enc_COUNTER_OVERFLOW           ((uint8) (0x01u << enc_COUNTER_OVERFLOW_SHIFT))
#define enc_COUNTER_UNDERFLOW          ((uint8) (0x01u << enc_COUNTER_UNDERFLOW_SHIFT))
#define enc_COUNTER_RESET              ((uint8) (0x01u << enc_COUNTER_RESET_SHIFT))
#define enc_INVALID_IN                 ((uint8) (0x01u << enc_INVALID_IN_SHIFT))

#define enc_INTERRUPTS_ENABLE_SHIFT    (0x04u)
#define enc_INTERRUPTS_ENABLE          ((uint8)(0x01u << enc_INTERRUPTS_ENABLE_SHIFT))
#define enc_INIT_INT_MASK              (0x0Fu)


/******************************************************************************************
* Following code are OBSOLETE and must not be used starting from Quadrature Decoder 2.20
******************************************************************************************/
#define enc_DISABLE                    (0x00u)


#endif /* CY_QUADRATURE_DECODER_enc_H */


/* [] END OF FILE */
