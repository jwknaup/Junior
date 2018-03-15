/*******************************************************************************
* File Name: Col1.h  
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

#if !defined(CY_PINS_Col1_H) /* Pins Col1_H */
#define CY_PINS_Col1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Col1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Col1__PORT == 15 && ((Col1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Col1_Write(uint8 value);
void    Col1_SetDriveMode(uint8 mode);
uint8   Col1_ReadDataReg(void);
uint8   Col1_Read(void);
void    Col1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Col1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Col1_SetDriveMode() function.
     *  @{
     */
        #define Col1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Col1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Col1_DM_RES_UP          PIN_DM_RES_UP
        #define Col1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Col1_DM_OD_LO           PIN_DM_OD_LO
        #define Col1_DM_OD_HI           PIN_DM_OD_HI
        #define Col1_DM_STRONG          PIN_DM_STRONG
        #define Col1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Col1_MASK               Col1__MASK
#define Col1_SHIFT              Col1__SHIFT
#define Col1_WIDTH              1u

/* Interrupt constants */
#if defined(Col1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Col1_SetInterruptMode() function.
     *  @{
     */
        #define Col1_INTR_NONE      (uint16)(0x0000u)
        #define Col1_INTR_RISING    (uint16)(0x0001u)
        #define Col1_INTR_FALLING   (uint16)(0x0002u)
        #define Col1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Col1_INTR_MASK      (0x01u) 
#endif /* (Col1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Col1_PS                     (* (reg8 *) Col1__PS)
/* Data Register */
#define Col1_DR                     (* (reg8 *) Col1__DR)
/* Port Number */
#define Col1_PRT_NUM                (* (reg8 *) Col1__PRT) 
/* Connect to Analog Globals */                                                  
#define Col1_AG                     (* (reg8 *) Col1__AG)                       
/* Analog MUX bux enable */
#define Col1_AMUX                   (* (reg8 *) Col1__AMUX) 
/* Bidirectional Enable */                                                        
#define Col1_BIE                    (* (reg8 *) Col1__BIE)
/* Bit-mask for Aliased Register Access */
#define Col1_BIT_MASK               (* (reg8 *) Col1__BIT_MASK)
/* Bypass Enable */
#define Col1_BYP                    (* (reg8 *) Col1__BYP)
/* Port wide control signals */                                                   
#define Col1_CTL                    (* (reg8 *) Col1__CTL)
/* Drive Modes */
#define Col1_DM0                    (* (reg8 *) Col1__DM0) 
#define Col1_DM1                    (* (reg8 *) Col1__DM1)
#define Col1_DM2                    (* (reg8 *) Col1__DM2) 
/* Input Buffer Disable Override */
#define Col1_INP_DIS                (* (reg8 *) Col1__INP_DIS)
/* LCD Common or Segment Drive */
#define Col1_LCD_COM_SEG            (* (reg8 *) Col1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Col1_LCD_EN                 (* (reg8 *) Col1__LCD_EN)
/* Slew Rate Control */
#define Col1_SLW                    (* (reg8 *) Col1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Col1_PRTDSI__CAPS_SEL       (* (reg8 *) Col1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Col1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Col1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Col1_PRTDSI__OE_SEL0        (* (reg8 *) Col1__PRTDSI__OE_SEL0) 
#define Col1_PRTDSI__OE_SEL1        (* (reg8 *) Col1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Col1_PRTDSI__OUT_SEL0       (* (reg8 *) Col1__PRTDSI__OUT_SEL0) 
#define Col1_PRTDSI__OUT_SEL1       (* (reg8 *) Col1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Col1_PRTDSI__SYNC_OUT       (* (reg8 *) Col1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Col1__SIO_CFG)
    #define Col1_SIO_HYST_EN        (* (reg8 *) Col1__SIO_HYST_EN)
    #define Col1_SIO_REG_HIFREQ     (* (reg8 *) Col1__SIO_REG_HIFREQ)
    #define Col1_SIO_CFG            (* (reg8 *) Col1__SIO_CFG)
    #define Col1_SIO_DIFF           (* (reg8 *) Col1__SIO_DIFF)
#endif /* (Col1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Col1__INTSTAT)
    #define Col1_INTSTAT            (* (reg8 *) Col1__INTSTAT)
    #define Col1_SNAP               (* (reg8 *) Col1__SNAP)
    
	#define Col1_0_INTTYPE_REG 		(* (reg8 *) Col1__0__INTTYPE)
#endif /* (Col1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Col1_H */


/* [] END OF FILE */
