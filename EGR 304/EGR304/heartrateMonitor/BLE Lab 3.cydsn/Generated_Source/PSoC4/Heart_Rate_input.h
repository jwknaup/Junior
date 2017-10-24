/*******************************************************************************
* File Name: Heart_Rate_input.h  
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

#if !defined(CY_PINS_Heart_Rate_input_H) /* Pins Heart_Rate_input_H */
#define CY_PINS_Heart_Rate_input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Heart_Rate_input_aliases.h"


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
} Heart_Rate_input_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Heart_Rate_input_Read(void);
void    Heart_Rate_input_Write(uint8 value);
uint8   Heart_Rate_input_ReadDataReg(void);
#if defined(Heart_Rate_input__PC) || (CY_PSOC4_4200L) 
    void    Heart_Rate_input_SetDriveMode(uint8 mode);
#endif
void    Heart_Rate_input_SetInterruptMode(uint16 position, uint16 mode);
uint8   Heart_Rate_input_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Heart_Rate_input_Sleep(void); 
void Heart_Rate_input_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Heart_Rate_input__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Heart_Rate_input_DRIVE_MODE_BITS        (3)
    #define Heart_Rate_input_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Heart_Rate_input_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Heart_Rate_input_SetDriveMode() function.
         *  @{
         */
        #define Heart_Rate_input_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Heart_Rate_input_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Heart_Rate_input_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Heart_Rate_input_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Heart_Rate_input_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Heart_Rate_input_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Heart_Rate_input_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Heart_Rate_input_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Heart_Rate_input_MASK               Heart_Rate_input__MASK
#define Heart_Rate_input_SHIFT              Heart_Rate_input__SHIFT
#define Heart_Rate_input_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Heart_Rate_input_SetInterruptMode() function.
     *  @{
     */
        #define Heart_Rate_input_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Heart_Rate_input_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Heart_Rate_input_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Heart_Rate_input_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Heart_Rate_input__SIO)
    #define Heart_Rate_input_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Heart_Rate_input__PC) && (CY_PSOC4_4200L)
    #define Heart_Rate_input_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Heart_Rate_input_USBIO_DISABLE              ((uint32)(~Heart_Rate_input_USBIO_ENABLE))
    #define Heart_Rate_input_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Heart_Rate_input_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Heart_Rate_input_USBIO_ENTER_SLEEP          ((uint32)((1u << Heart_Rate_input_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Heart_Rate_input_USBIO_SUSPEND_DEL_SHIFT)))
    #define Heart_Rate_input_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Heart_Rate_input_USBIO_SUSPEND_SHIFT)))
    #define Heart_Rate_input_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Heart_Rate_input_USBIO_SUSPEND_DEL_SHIFT)))
    #define Heart_Rate_input_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Heart_Rate_input__PC)
    /* Port Configuration */
    #define Heart_Rate_input_PC                 (* (reg32 *) Heart_Rate_input__PC)
#endif
/* Pin State */
#define Heart_Rate_input_PS                     (* (reg32 *) Heart_Rate_input__PS)
/* Data Register */
#define Heart_Rate_input_DR                     (* (reg32 *) Heart_Rate_input__DR)
/* Input Buffer Disable Override */
#define Heart_Rate_input_INP_DIS                (* (reg32 *) Heart_Rate_input__PC2)

/* Interrupt configuration Registers */
#define Heart_Rate_input_INTCFG                 (* (reg32 *) Heart_Rate_input__INTCFG)
#define Heart_Rate_input_INTSTAT                (* (reg32 *) Heart_Rate_input__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Heart_Rate_input_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Heart_Rate_input__SIO)
    #define Heart_Rate_input_SIO_REG            (* (reg32 *) Heart_Rate_input__SIO)
#endif /* (Heart_Rate_input__SIO_CFG) */

/* USBIO registers */
#if !defined(Heart_Rate_input__PC) && (CY_PSOC4_4200L)
    #define Heart_Rate_input_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Heart_Rate_input_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Heart_Rate_input_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Heart_Rate_input_DRIVE_MODE_SHIFT       (0x00u)
#define Heart_Rate_input_DRIVE_MODE_MASK        (0x07u << Heart_Rate_input_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Heart_Rate_input_H */


/* [] END OF FILE */
