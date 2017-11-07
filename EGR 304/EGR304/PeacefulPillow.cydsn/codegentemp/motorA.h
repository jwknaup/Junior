/*******************************************************************************
* File Name: motorA.h  
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

#if !defined(CY_PINS_motorA_H) /* Pins motorA_H */
#define CY_PINS_motorA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "motorA_aliases.h"


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
} motorA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   motorA_Read(void);
void    motorA_Write(uint8 value);
uint8   motorA_ReadDataReg(void);
#if defined(motorA__PC) || (CY_PSOC4_4200L) 
    void    motorA_SetDriveMode(uint8 mode);
#endif
void    motorA_SetInterruptMode(uint16 position, uint16 mode);
uint8   motorA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void motorA_Sleep(void); 
void motorA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(motorA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define motorA_DRIVE_MODE_BITS        (3)
    #define motorA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - motorA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the motorA_SetDriveMode() function.
         *  @{
         */
        #define motorA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define motorA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define motorA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define motorA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define motorA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define motorA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define motorA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define motorA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define motorA_MASK               motorA__MASK
#define motorA_SHIFT              motorA__SHIFT
#define motorA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in motorA_SetInterruptMode() function.
     *  @{
     */
        #define motorA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define motorA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define motorA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define motorA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(motorA__SIO)
    #define motorA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(motorA__PC) && (CY_PSOC4_4200L)
    #define motorA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define motorA_USBIO_DISABLE              ((uint32)(~motorA_USBIO_ENABLE))
    #define motorA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define motorA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define motorA_USBIO_ENTER_SLEEP          ((uint32)((1u << motorA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << motorA_USBIO_SUSPEND_DEL_SHIFT)))
    #define motorA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << motorA_USBIO_SUSPEND_SHIFT)))
    #define motorA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << motorA_USBIO_SUSPEND_DEL_SHIFT)))
    #define motorA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(motorA__PC)
    /* Port Configuration */
    #define motorA_PC                 (* (reg32 *) motorA__PC)
#endif
/* Pin State */
#define motorA_PS                     (* (reg32 *) motorA__PS)
/* Data Register */
#define motorA_DR                     (* (reg32 *) motorA__DR)
/* Input Buffer Disable Override */
#define motorA_INP_DIS                (* (reg32 *) motorA__PC2)

/* Interrupt configuration Registers */
#define motorA_INTCFG                 (* (reg32 *) motorA__INTCFG)
#define motorA_INTSTAT                (* (reg32 *) motorA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define motorA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(motorA__SIO)
    #define motorA_SIO_REG            (* (reg32 *) motorA__SIO)
#endif /* (motorA__SIO_CFG) */

/* USBIO registers */
#if !defined(motorA__PC) && (CY_PSOC4_4200L)
    #define motorA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define motorA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define motorA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define motorA_DRIVE_MODE_SHIFT       (0x00u)
#define motorA_DRIVE_MODE_MASK        (0x07u << motorA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins motorA_H */


/* [] END OF FILE */
