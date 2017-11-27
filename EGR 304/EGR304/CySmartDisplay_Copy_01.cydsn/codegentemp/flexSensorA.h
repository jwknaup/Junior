/*******************************************************************************
* File Name: flexSensorA.h  
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

#if !defined(CY_PINS_flexSensorA_H) /* Pins flexSensorA_H */
#define CY_PINS_flexSensorA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "flexSensorA_aliases.h"


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
} flexSensorA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   flexSensorA_Read(void);
void    flexSensorA_Write(uint8 value);
uint8   flexSensorA_ReadDataReg(void);
#if defined(flexSensorA__PC) || (CY_PSOC4_4200L) 
    void    flexSensorA_SetDriveMode(uint8 mode);
#endif
void    flexSensorA_SetInterruptMode(uint16 position, uint16 mode);
uint8   flexSensorA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void flexSensorA_Sleep(void); 
void flexSensorA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(flexSensorA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define flexSensorA_DRIVE_MODE_BITS        (3)
    #define flexSensorA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - flexSensorA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the flexSensorA_SetDriveMode() function.
         *  @{
         */
        #define flexSensorA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define flexSensorA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define flexSensorA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define flexSensorA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define flexSensorA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define flexSensorA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define flexSensorA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define flexSensorA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define flexSensorA_MASK               flexSensorA__MASK
#define flexSensorA_SHIFT              flexSensorA__SHIFT
#define flexSensorA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in flexSensorA_SetInterruptMode() function.
     *  @{
     */
        #define flexSensorA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define flexSensorA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define flexSensorA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define flexSensorA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(flexSensorA__SIO)
    #define flexSensorA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(flexSensorA__PC) && (CY_PSOC4_4200L)
    #define flexSensorA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define flexSensorA_USBIO_DISABLE              ((uint32)(~flexSensorA_USBIO_ENABLE))
    #define flexSensorA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define flexSensorA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define flexSensorA_USBIO_ENTER_SLEEP          ((uint32)((1u << flexSensorA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << flexSensorA_USBIO_SUSPEND_DEL_SHIFT)))
    #define flexSensorA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << flexSensorA_USBIO_SUSPEND_SHIFT)))
    #define flexSensorA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << flexSensorA_USBIO_SUSPEND_DEL_SHIFT)))
    #define flexSensorA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(flexSensorA__PC)
    /* Port Configuration */
    #define flexSensorA_PC                 (* (reg32 *) flexSensorA__PC)
#endif
/* Pin State */
#define flexSensorA_PS                     (* (reg32 *) flexSensorA__PS)
/* Data Register */
#define flexSensorA_DR                     (* (reg32 *) flexSensorA__DR)
/* Input Buffer Disable Override */
#define flexSensorA_INP_DIS                (* (reg32 *) flexSensorA__PC2)

/* Interrupt configuration Registers */
#define flexSensorA_INTCFG                 (* (reg32 *) flexSensorA__INTCFG)
#define flexSensorA_INTSTAT                (* (reg32 *) flexSensorA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define flexSensorA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(flexSensorA__SIO)
    #define flexSensorA_SIO_REG            (* (reg32 *) flexSensorA__SIO)
#endif /* (flexSensorA__SIO_CFG) */

/* USBIO registers */
#if !defined(flexSensorA__PC) && (CY_PSOC4_4200L)
    #define flexSensorA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define flexSensorA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define flexSensorA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define flexSensorA_DRIVE_MODE_SHIFT       (0x00u)
#define flexSensorA_DRIVE_MODE_MASK        (0x07u << flexSensorA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins flexSensorA_H */


/* [] END OF FILE */
