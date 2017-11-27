/*******************************************************************************
* File Name: motorB.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_motorB_H) /* Pins motorB_H */
#define CY_PINS_motorB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "motorB_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} motorB_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   motorB_Read(void);
void    motorB_Write(uint8 value);
uint8   motorB_ReadDataReg(void);
#if defined(motorB__PC) || (CY_PSOC4_4200L) 
    void    motorB_SetDriveMode(uint8 mode);
#endif
void    motorB_SetInterruptMode(uint16 position, uint16 mode);
uint8   motorB_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void motorB_Sleep(void); 
void motorB_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(motorB__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define motorB_DRIVE_MODE_BITS        (3)
    #define motorB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - motorB_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the motorB_SetDriveMode() function.
         *  @{
         */
        #define motorB_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define motorB_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define motorB_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define motorB_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define motorB_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define motorB_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define motorB_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define motorB_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define motorB_MASK               motorB__MASK
#define motorB_SHIFT              motorB__SHIFT
#define motorB_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in motorB_SetInterruptMode() function.
     *  @{
     */
        #define motorB_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define motorB_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define motorB_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define motorB_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(motorB__SIO)
    #define motorB_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(motorB__PC) && (CY_PSOC4_4200L)
    #define motorB_USBIO_ENABLE               ((uint32)0x80000000u)
    #define motorB_USBIO_DISABLE              ((uint32)(~motorB_USBIO_ENABLE))
    #define motorB_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define motorB_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define motorB_USBIO_ENTER_SLEEP          ((uint32)((1u << motorB_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << motorB_USBIO_SUSPEND_DEL_SHIFT)))
    #define motorB_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << motorB_USBIO_SUSPEND_SHIFT)))
    #define motorB_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << motorB_USBIO_SUSPEND_DEL_SHIFT)))
    #define motorB_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(motorB__PC)
    /* Port Configuration */
    #define motorB_PC                 (* (reg32 *) motorB__PC)
#endif
/* Pin State */
#define motorB_PS                     (* (reg32 *) motorB__PS)
/* Data Register */
#define motorB_DR                     (* (reg32 *) motorB__DR)
/* Input Buffer Disable Override */
#define motorB_INP_DIS                (* (reg32 *) motorB__PC2)

/* Interrupt configuration Registers */
#define motorB_INTCFG                 (* (reg32 *) motorB__INTCFG)
#define motorB_INTSTAT                (* (reg32 *) motorB__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define motorB_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(motorB__SIO)
    #define motorB_SIO_REG            (* (reg32 *) motorB__SIO)
#endif /* (motorB__SIO_CFG) */

/* USBIO registers */
#if !defined(motorB__PC) && (CY_PSOC4_4200L)
    #define motorB_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define motorB_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define motorB_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define motorB_DRIVE_MODE_SHIFT       (0x00u)
#define motorB_DRIVE_MODE_MASK        (0x07u << motorB_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins motorB_H */


/* [] END OF FILE */
