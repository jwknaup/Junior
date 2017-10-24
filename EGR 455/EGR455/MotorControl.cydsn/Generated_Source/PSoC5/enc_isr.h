/*******************************************************************************
* File Name: enc_isr.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_enc_isr_H)
#define CY_ISR_enc_isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void enc_isr_Start(void);
void enc_isr_StartEx(cyisraddress address);
void enc_isr_Stop(void);

CY_ISR_PROTO(enc_isr_Interrupt);

void enc_isr_SetVector(cyisraddress address);
cyisraddress enc_isr_GetVector(void);

void enc_isr_SetPriority(uint8 priority);
uint8 enc_isr_GetPriority(void);

void enc_isr_Enable(void);
uint8 enc_isr_GetState(void);
void enc_isr_Disable(void);

void enc_isr_SetPending(void);
void enc_isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the enc_isr ISR. */
#define enc_isr_INTC_VECTOR            ((reg32 *) enc_isr__INTC_VECT)

/* Address of the enc_isr ISR priority. */
#define enc_isr_INTC_PRIOR             ((reg8 *) enc_isr__INTC_PRIOR_REG)

/* Priority of the enc_isr interrupt. */
#define enc_isr_INTC_PRIOR_NUMBER      enc_isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable enc_isr interrupt. */
#define enc_isr_INTC_SET_EN            ((reg32 *) enc_isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the enc_isr interrupt. */
#define enc_isr_INTC_CLR_EN            ((reg32 *) enc_isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the enc_isr interrupt state to pending. */
#define enc_isr_INTC_SET_PD            ((reg32 *) enc_isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the enc_isr interrupt. */
#define enc_isr_INTC_CLR_PD            ((reg32 *) enc_isr__INTC_CLR_PD_REG)


#endif /* CY_ISR_enc_isr_H */


/* [] END OF FILE */
