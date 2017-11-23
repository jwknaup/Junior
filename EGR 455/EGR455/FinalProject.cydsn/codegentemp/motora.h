/*******************************************************************************
* File Name: motora.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_motora_H) /* Pins motora_H */
#define CY_PINS_motora_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "motora_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 motora__PORT == 15 && ((motora__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    motora_Write(uint8 value);
void    motora_SetDriveMode(uint8 mode);
uint8   motora_ReadDataReg(void);
uint8   motora_Read(void);
void    motora_SetInterruptMode(uint16 position, uint16 mode);
uint8   motora_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the motora_SetDriveMode() function.
     *  @{
     */
        #define motora_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define motora_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define motora_DM_RES_UP          PIN_DM_RES_UP
        #define motora_DM_RES_DWN         PIN_DM_RES_DWN
        #define motora_DM_OD_LO           PIN_DM_OD_LO
        #define motora_DM_OD_HI           PIN_DM_OD_HI
        #define motora_DM_STRONG          PIN_DM_STRONG
        #define motora_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define motora_MASK               motora__MASK
#define motora_SHIFT              motora__SHIFT
#define motora_WIDTH              1u

/* Interrupt constants */
#if defined(motora__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in motora_SetInterruptMode() function.
     *  @{
     */
        #define motora_INTR_NONE      (uint16)(0x0000u)
        #define motora_INTR_RISING    (uint16)(0x0001u)
        #define motora_INTR_FALLING   (uint16)(0x0002u)
        #define motora_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define motora_INTR_MASK      (0x01u) 
#endif /* (motora__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define motora_PS                     (* (reg8 *) motora__PS)
/* Data Register */
#define motora_DR                     (* (reg8 *) motora__DR)
/* Port Number */
#define motora_PRT_NUM                (* (reg8 *) motora__PRT) 
/* Connect to Analog Globals */                                                  
#define motora_AG                     (* (reg8 *) motora__AG)                       
/* Analog MUX bux enable */
#define motora_AMUX                   (* (reg8 *) motora__AMUX) 
/* Bidirectional Enable */                                                        
#define motora_BIE                    (* (reg8 *) motora__BIE)
/* Bit-mask for Aliased Register Access */
#define motora_BIT_MASK               (* (reg8 *) motora__BIT_MASK)
/* Bypass Enable */
#define motora_BYP                    (* (reg8 *) motora__BYP)
/* Port wide control signals */                                                   
#define motora_CTL                    (* (reg8 *) motora__CTL)
/* Drive Modes */
#define motora_DM0                    (* (reg8 *) motora__DM0) 
#define motora_DM1                    (* (reg8 *) motora__DM1)
#define motora_DM2                    (* (reg8 *) motora__DM2) 
/* Input Buffer Disable Override */
#define motora_INP_DIS                (* (reg8 *) motora__INP_DIS)
/* LCD Common or Segment Drive */
#define motora_LCD_COM_SEG            (* (reg8 *) motora__LCD_COM_SEG)
/* Enable Segment LCD */
#define motora_LCD_EN                 (* (reg8 *) motora__LCD_EN)
/* Slew Rate Control */
#define motora_SLW                    (* (reg8 *) motora__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define motora_PRTDSI__CAPS_SEL       (* (reg8 *) motora__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define motora_PRTDSI__DBL_SYNC_IN    (* (reg8 *) motora__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define motora_PRTDSI__OE_SEL0        (* (reg8 *) motora__PRTDSI__OE_SEL0) 
#define motora_PRTDSI__OE_SEL1        (* (reg8 *) motora__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define motora_PRTDSI__OUT_SEL0       (* (reg8 *) motora__PRTDSI__OUT_SEL0) 
#define motora_PRTDSI__OUT_SEL1       (* (reg8 *) motora__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define motora_PRTDSI__SYNC_OUT       (* (reg8 *) motora__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(motora__SIO_CFG)
    #define motora_SIO_HYST_EN        (* (reg8 *) motora__SIO_HYST_EN)
    #define motora_SIO_REG_HIFREQ     (* (reg8 *) motora__SIO_REG_HIFREQ)
    #define motora_SIO_CFG            (* (reg8 *) motora__SIO_CFG)
    #define motora_SIO_DIFF           (* (reg8 *) motora__SIO_DIFF)
#endif /* (motora__SIO_CFG) */

/* Interrupt Registers */
#if defined(motora__INTSTAT)
    #define motora_INTSTAT            (* (reg8 *) motora__INTSTAT)
    #define motora_SNAP               (* (reg8 *) motora__SNAP)
    
	#define motora_0_INTTYPE_REG 		(* (reg8 *) motora__0__INTTYPE)
#endif /* (motora__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_motora_H */


/* [] END OF FILE */
