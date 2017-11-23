/*******************************************************************************
* File Name: motorb.h  
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

#if !defined(CY_PINS_motorb_H) /* Pins motorb_H */
#define CY_PINS_motorb_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "motorb_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 motorb__PORT == 15 && ((motorb__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    motorb_Write(uint8 value);
void    motorb_SetDriveMode(uint8 mode);
uint8   motorb_ReadDataReg(void);
uint8   motorb_Read(void);
void    motorb_SetInterruptMode(uint16 position, uint16 mode);
uint8   motorb_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the motorb_SetDriveMode() function.
     *  @{
     */
        #define motorb_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define motorb_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define motorb_DM_RES_UP          PIN_DM_RES_UP
        #define motorb_DM_RES_DWN         PIN_DM_RES_DWN
        #define motorb_DM_OD_LO           PIN_DM_OD_LO
        #define motorb_DM_OD_HI           PIN_DM_OD_HI
        #define motorb_DM_STRONG          PIN_DM_STRONG
        #define motorb_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define motorb_MASK               motorb__MASK
#define motorb_SHIFT              motorb__SHIFT
#define motorb_WIDTH              1u

/* Interrupt constants */
#if defined(motorb__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in motorb_SetInterruptMode() function.
     *  @{
     */
        #define motorb_INTR_NONE      (uint16)(0x0000u)
        #define motorb_INTR_RISING    (uint16)(0x0001u)
        #define motorb_INTR_FALLING   (uint16)(0x0002u)
        #define motorb_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define motorb_INTR_MASK      (0x01u) 
#endif /* (motorb__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define motorb_PS                     (* (reg8 *) motorb__PS)
/* Data Register */
#define motorb_DR                     (* (reg8 *) motorb__DR)
/* Port Number */
#define motorb_PRT_NUM                (* (reg8 *) motorb__PRT) 
/* Connect to Analog Globals */                                                  
#define motorb_AG                     (* (reg8 *) motorb__AG)                       
/* Analog MUX bux enable */
#define motorb_AMUX                   (* (reg8 *) motorb__AMUX) 
/* Bidirectional Enable */                                                        
#define motorb_BIE                    (* (reg8 *) motorb__BIE)
/* Bit-mask for Aliased Register Access */
#define motorb_BIT_MASK               (* (reg8 *) motorb__BIT_MASK)
/* Bypass Enable */
#define motorb_BYP                    (* (reg8 *) motorb__BYP)
/* Port wide control signals */                                                   
#define motorb_CTL                    (* (reg8 *) motorb__CTL)
/* Drive Modes */
#define motorb_DM0                    (* (reg8 *) motorb__DM0) 
#define motorb_DM1                    (* (reg8 *) motorb__DM1)
#define motorb_DM2                    (* (reg8 *) motorb__DM2) 
/* Input Buffer Disable Override */
#define motorb_INP_DIS                (* (reg8 *) motorb__INP_DIS)
/* LCD Common or Segment Drive */
#define motorb_LCD_COM_SEG            (* (reg8 *) motorb__LCD_COM_SEG)
/* Enable Segment LCD */
#define motorb_LCD_EN                 (* (reg8 *) motorb__LCD_EN)
/* Slew Rate Control */
#define motorb_SLW                    (* (reg8 *) motorb__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define motorb_PRTDSI__CAPS_SEL       (* (reg8 *) motorb__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define motorb_PRTDSI__DBL_SYNC_IN    (* (reg8 *) motorb__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define motorb_PRTDSI__OE_SEL0        (* (reg8 *) motorb__PRTDSI__OE_SEL0) 
#define motorb_PRTDSI__OE_SEL1        (* (reg8 *) motorb__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define motorb_PRTDSI__OUT_SEL0       (* (reg8 *) motorb__PRTDSI__OUT_SEL0) 
#define motorb_PRTDSI__OUT_SEL1       (* (reg8 *) motorb__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define motorb_PRTDSI__SYNC_OUT       (* (reg8 *) motorb__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(motorb__SIO_CFG)
    #define motorb_SIO_HYST_EN        (* (reg8 *) motorb__SIO_HYST_EN)
    #define motorb_SIO_REG_HIFREQ     (* (reg8 *) motorb__SIO_REG_HIFREQ)
    #define motorb_SIO_CFG            (* (reg8 *) motorb__SIO_CFG)
    #define motorb_SIO_DIFF           (* (reg8 *) motorb__SIO_DIFF)
#endif /* (motorb__SIO_CFG) */

/* Interrupt Registers */
#if defined(motorb__INTSTAT)
    #define motorb_INTSTAT            (* (reg8 *) motorb__INTSTAT)
    #define motorb_SNAP               (* (reg8 *) motorb__SNAP)
    
	#define motorb_0_INTTYPE_REG 		(* (reg8 *) motorb__0__INTTYPE)
#endif /* (motorb__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_motorb_H */


/* [] END OF FILE */
