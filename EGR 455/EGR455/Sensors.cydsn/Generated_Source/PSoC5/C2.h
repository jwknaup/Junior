/*******************************************************************************
* File Name: C2.h  
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

#if !defined(CY_PINS_C2_H) /* Pins C2_H */
#define CY_PINS_C2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C2__PORT == 15 && ((C2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C2_Write(uint8 value);
void    C2_SetDriveMode(uint8 mode);
uint8   C2_ReadDataReg(void);
uint8   C2_Read(void);
void    C2_SetInterruptMode(uint16 position, uint16 mode);
uint8   C2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C2_SetDriveMode() function.
     *  @{
     */
        #define C2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C2_DM_RES_UP          PIN_DM_RES_UP
        #define C2_DM_RES_DWN         PIN_DM_RES_DWN
        #define C2_DM_OD_LO           PIN_DM_OD_LO
        #define C2_DM_OD_HI           PIN_DM_OD_HI
        #define C2_DM_STRONG          PIN_DM_STRONG
        #define C2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C2_MASK               C2__MASK
#define C2_SHIFT              C2__SHIFT
#define C2_WIDTH              1u

/* Interrupt constants */
#if defined(C2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C2_SetInterruptMode() function.
     *  @{
     */
        #define C2_INTR_NONE      (uint16)(0x0000u)
        #define C2_INTR_RISING    (uint16)(0x0001u)
        #define C2_INTR_FALLING   (uint16)(0x0002u)
        #define C2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C2_INTR_MASK      (0x01u) 
#endif /* (C2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C2_PS                     (* (reg8 *) C2__PS)
/* Data Register */
#define C2_DR                     (* (reg8 *) C2__DR)
/* Port Number */
#define C2_PRT_NUM                (* (reg8 *) C2__PRT) 
/* Connect to Analog Globals */                                                  
#define C2_AG                     (* (reg8 *) C2__AG)                       
/* Analog MUX bux enable */
#define C2_AMUX                   (* (reg8 *) C2__AMUX) 
/* Bidirectional Enable */                                                        
#define C2_BIE                    (* (reg8 *) C2__BIE)
/* Bit-mask for Aliased Register Access */
#define C2_BIT_MASK               (* (reg8 *) C2__BIT_MASK)
/* Bypass Enable */
#define C2_BYP                    (* (reg8 *) C2__BYP)
/* Port wide control signals */                                                   
#define C2_CTL                    (* (reg8 *) C2__CTL)
/* Drive Modes */
#define C2_DM0                    (* (reg8 *) C2__DM0) 
#define C2_DM1                    (* (reg8 *) C2__DM1)
#define C2_DM2                    (* (reg8 *) C2__DM2) 
/* Input Buffer Disable Override */
#define C2_INP_DIS                (* (reg8 *) C2__INP_DIS)
/* LCD Common or Segment Drive */
#define C2_LCD_COM_SEG            (* (reg8 *) C2__LCD_COM_SEG)
/* Enable Segment LCD */
#define C2_LCD_EN                 (* (reg8 *) C2__LCD_EN)
/* Slew Rate Control */
#define C2_SLW                    (* (reg8 *) C2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C2_PRTDSI__CAPS_SEL       (* (reg8 *) C2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C2_PRTDSI__OE_SEL0        (* (reg8 *) C2__PRTDSI__OE_SEL0) 
#define C2_PRTDSI__OE_SEL1        (* (reg8 *) C2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C2_PRTDSI__OUT_SEL0       (* (reg8 *) C2__PRTDSI__OUT_SEL0) 
#define C2_PRTDSI__OUT_SEL1       (* (reg8 *) C2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C2_PRTDSI__SYNC_OUT       (* (reg8 *) C2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C2__SIO_CFG)
    #define C2_SIO_HYST_EN        (* (reg8 *) C2__SIO_HYST_EN)
    #define C2_SIO_REG_HIFREQ     (* (reg8 *) C2__SIO_REG_HIFREQ)
    #define C2_SIO_CFG            (* (reg8 *) C2__SIO_CFG)
    #define C2_SIO_DIFF           (* (reg8 *) C2__SIO_DIFF)
#endif /* (C2__SIO_CFG) */

/* Interrupt Registers */
#if defined(C2__INTSTAT)
    #define C2_INTSTAT            (* (reg8 *) C2__INTSTAT)
    #define C2_SNAP               (* (reg8 *) C2__SNAP)
    
	#define C2_0_INTTYPE_REG 		(* (reg8 *) C2__0__INTTYPE)
#endif /* (C2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C2_H */


/* [] END OF FILE */
