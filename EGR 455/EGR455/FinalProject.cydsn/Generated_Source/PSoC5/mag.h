/*******************************************************************************
* File Name: mag.h  
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

#if !defined(CY_PINS_mag_H) /* Pins mag_H */
#define CY_PINS_mag_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "mag_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 mag__PORT == 15 && ((mag__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    mag_Write(uint8 value);
void    mag_SetDriveMode(uint8 mode);
uint8   mag_ReadDataReg(void);
uint8   mag_Read(void);
void    mag_SetInterruptMode(uint16 position, uint16 mode);
uint8   mag_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the mag_SetDriveMode() function.
     *  @{
     */
        #define mag_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define mag_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define mag_DM_RES_UP          PIN_DM_RES_UP
        #define mag_DM_RES_DWN         PIN_DM_RES_DWN
        #define mag_DM_OD_LO           PIN_DM_OD_LO
        #define mag_DM_OD_HI           PIN_DM_OD_HI
        #define mag_DM_STRONG          PIN_DM_STRONG
        #define mag_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define mag_MASK               mag__MASK
#define mag_SHIFT              mag__SHIFT
#define mag_WIDTH              1u

/* Interrupt constants */
#if defined(mag__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in mag_SetInterruptMode() function.
     *  @{
     */
        #define mag_INTR_NONE      (uint16)(0x0000u)
        #define mag_INTR_RISING    (uint16)(0x0001u)
        #define mag_INTR_FALLING   (uint16)(0x0002u)
        #define mag_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define mag_INTR_MASK      (0x01u) 
#endif /* (mag__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define mag_PS                     (* (reg8 *) mag__PS)
/* Data Register */
#define mag_DR                     (* (reg8 *) mag__DR)
/* Port Number */
#define mag_PRT_NUM                (* (reg8 *) mag__PRT) 
/* Connect to Analog Globals */                                                  
#define mag_AG                     (* (reg8 *) mag__AG)                       
/* Analog MUX bux enable */
#define mag_AMUX                   (* (reg8 *) mag__AMUX) 
/* Bidirectional Enable */                                                        
#define mag_BIE                    (* (reg8 *) mag__BIE)
/* Bit-mask for Aliased Register Access */
#define mag_BIT_MASK               (* (reg8 *) mag__BIT_MASK)
/* Bypass Enable */
#define mag_BYP                    (* (reg8 *) mag__BYP)
/* Port wide control signals */                                                   
#define mag_CTL                    (* (reg8 *) mag__CTL)
/* Drive Modes */
#define mag_DM0                    (* (reg8 *) mag__DM0) 
#define mag_DM1                    (* (reg8 *) mag__DM1)
#define mag_DM2                    (* (reg8 *) mag__DM2) 
/* Input Buffer Disable Override */
#define mag_INP_DIS                (* (reg8 *) mag__INP_DIS)
/* LCD Common or Segment Drive */
#define mag_LCD_COM_SEG            (* (reg8 *) mag__LCD_COM_SEG)
/* Enable Segment LCD */
#define mag_LCD_EN                 (* (reg8 *) mag__LCD_EN)
/* Slew Rate Control */
#define mag_SLW                    (* (reg8 *) mag__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define mag_PRTDSI__CAPS_SEL       (* (reg8 *) mag__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define mag_PRTDSI__DBL_SYNC_IN    (* (reg8 *) mag__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define mag_PRTDSI__OE_SEL0        (* (reg8 *) mag__PRTDSI__OE_SEL0) 
#define mag_PRTDSI__OE_SEL1        (* (reg8 *) mag__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define mag_PRTDSI__OUT_SEL0       (* (reg8 *) mag__PRTDSI__OUT_SEL0) 
#define mag_PRTDSI__OUT_SEL1       (* (reg8 *) mag__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define mag_PRTDSI__SYNC_OUT       (* (reg8 *) mag__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(mag__SIO_CFG)
    #define mag_SIO_HYST_EN        (* (reg8 *) mag__SIO_HYST_EN)
    #define mag_SIO_REG_HIFREQ     (* (reg8 *) mag__SIO_REG_HIFREQ)
    #define mag_SIO_CFG            (* (reg8 *) mag__SIO_CFG)
    #define mag_SIO_DIFF           (* (reg8 *) mag__SIO_DIFF)
#endif /* (mag__SIO_CFG) */

/* Interrupt Registers */
#if defined(mag__INTSTAT)
    #define mag_INTSTAT            (* (reg8 *) mag__INTSTAT)
    #define mag_SNAP               (* (reg8 *) mag__SNAP)
    
	#define mag_0_INTTYPE_REG 		(* (reg8 *) mag__0__INTTYPE)
#endif /* (mag__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_mag_H */


/* [] END OF FILE */
