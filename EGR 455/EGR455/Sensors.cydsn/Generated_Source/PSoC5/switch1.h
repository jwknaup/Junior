/*******************************************************************************
* File Name: switch1.h  
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

#if !defined(CY_PINS_switch1_H) /* Pins switch1_H */
#define CY_PINS_switch1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "switch1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 switch1__PORT == 15 && ((switch1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    switch1_Write(uint8 value);
void    switch1_SetDriveMode(uint8 mode);
uint8   switch1_ReadDataReg(void);
uint8   switch1_Read(void);
void    switch1_SetInterruptMode(uint16 position, uint16 mode);
uint8   switch1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the switch1_SetDriveMode() function.
     *  @{
     */
        #define switch1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define switch1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define switch1_DM_RES_UP          PIN_DM_RES_UP
        #define switch1_DM_RES_DWN         PIN_DM_RES_DWN
        #define switch1_DM_OD_LO           PIN_DM_OD_LO
        #define switch1_DM_OD_HI           PIN_DM_OD_HI
        #define switch1_DM_STRONG          PIN_DM_STRONG
        #define switch1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define switch1_MASK               switch1__MASK
#define switch1_SHIFT              switch1__SHIFT
#define switch1_WIDTH              1u

/* Interrupt constants */
#if defined(switch1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in switch1_SetInterruptMode() function.
     *  @{
     */
        #define switch1_INTR_NONE      (uint16)(0x0000u)
        #define switch1_INTR_RISING    (uint16)(0x0001u)
        #define switch1_INTR_FALLING   (uint16)(0x0002u)
        #define switch1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define switch1_INTR_MASK      (0x01u) 
#endif /* (switch1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define switch1_PS                     (* (reg8 *) switch1__PS)
/* Data Register */
#define switch1_DR                     (* (reg8 *) switch1__DR)
/* Port Number */
#define switch1_PRT_NUM                (* (reg8 *) switch1__PRT) 
/* Connect to Analog Globals */                                                  
#define switch1_AG                     (* (reg8 *) switch1__AG)                       
/* Analog MUX bux enable */
#define switch1_AMUX                   (* (reg8 *) switch1__AMUX) 
/* Bidirectional Enable */                                                        
#define switch1_BIE                    (* (reg8 *) switch1__BIE)
/* Bit-mask for Aliased Register Access */
#define switch1_BIT_MASK               (* (reg8 *) switch1__BIT_MASK)
/* Bypass Enable */
#define switch1_BYP                    (* (reg8 *) switch1__BYP)
/* Port wide control signals */                                                   
#define switch1_CTL                    (* (reg8 *) switch1__CTL)
/* Drive Modes */
#define switch1_DM0                    (* (reg8 *) switch1__DM0) 
#define switch1_DM1                    (* (reg8 *) switch1__DM1)
#define switch1_DM2                    (* (reg8 *) switch1__DM2) 
/* Input Buffer Disable Override */
#define switch1_INP_DIS                (* (reg8 *) switch1__INP_DIS)
/* LCD Common or Segment Drive */
#define switch1_LCD_COM_SEG            (* (reg8 *) switch1__LCD_COM_SEG)
/* Enable Segment LCD */
#define switch1_LCD_EN                 (* (reg8 *) switch1__LCD_EN)
/* Slew Rate Control */
#define switch1_SLW                    (* (reg8 *) switch1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define switch1_PRTDSI__CAPS_SEL       (* (reg8 *) switch1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define switch1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) switch1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define switch1_PRTDSI__OE_SEL0        (* (reg8 *) switch1__PRTDSI__OE_SEL0) 
#define switch1_PRTDSI__OE_SEL1        (* (reg8 *) switch1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define switch1_PRTDSI__OUT_SEL0       (* (reg8 *) switch1__PRTDSI__OUT_SEL0) 
#define switch1_PRTDSI__OUT_SEL1       (* (reg8 *) switch1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define switch1_PRTDSI__SYNC_OUT       (* (reg8 *) switch1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(switch1__SIO_CFG)
    #define switch1_SIO_HYST_EN        (* (reg8 *) switch1__SIO_HYST_EN)
    #define switch1_SIO_REG_HIFREQ     (* (reg8 *) switch1__SIO_REG_HIFREQ)
    #define switch1_SIO_CFG            (* (reg8 *) switch1__SIO_CFG)
    #define switch1_SIO_DIFF           (* (reg8 *) switch1__SIO_DIFF)
#endif /* (switch1__SIO_CFG) */

/* Interrupt Registers */
#if defined(switch1__INTSTAT)
    #define switch1_INTSTAT            (* (reg8 *) switch1__INTSTAT)
    #define switch1_SNAP               (* (reg8 *) switch1__SNAP)
    
	#define switch1_0_INTTYPE_REG 		(* (reg8 *) switch1__0__INTTYPE)
#endif /* (switch1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_switch1_H */


/* [] END OF FILE */
