/*******************************************************************************
* File Name: Button_output.h  
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

#if !defined(CY_PINS_Button_output_H) /* Pins Button_output_H */
#define CY_PINS_Button_output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Button_output_aliases.h"


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
} Button_output_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Button_output_Read(void);
void    Button_output_Write(uint8 value);
uint8   Button_output_ReadDataReg(void);
#if defined(Button_output__PC) || (CY_PSOC4_4200L) 
    void    Button_output_SetDriveMode(uint8 mode);
#endif
void    Button_output_SetInterruptMode(uint16 position, uint16 mode);
uint8   Button_output_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Button_output_Sleep(void); 
void Button_output_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Button_output__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Button_output_DRIVE_MODE_BITS        (3)
    #define Button_output_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Button_output_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Button_output_SetDriveMode() function.
         *  @{
         */
        #define Button_output_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Button_output_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Button_output_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Button_output_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Button_output_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Button_output_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Button_output_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Button_output_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Button_output_MASK               Button_output__MASK
#define Button_output_SHIFT              Button_output__SHIFT
#define Button_output_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Button_output_SetInterruptMode() function.
     *  @{
     */
        #define Button_output_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Button_output_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Button_output_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Button_output_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Button_output__SIO)
    #define Button_output_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Button_output__PC) && (CY_PSOC4_4200L)
    #define Button_output_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Button_output_USBIO_DISABLE              ((uint32)(~Button_output_USBIO_ENABLE))
    #define Button_output_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Button_output_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Button_output_USBIO_ENTER_SLEEP          ((uint32)((1u << Button_output_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Button_output_USBIO_SUSPEND_DEL_SHIFT)))
    #define Button_output_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Button_output_USBIO_SUSPEND_SHIFT)))
    #define Button_output_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Button_output_USBIO_SUSPEND_DEL_SHIFT)))
    #define Button_output_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Button_output__PC)
    /* Port Configuration */
    #define Button_output_PC                 (* (reg32 *) Button_output__PC)
#endif
/* Pin State */
#define Button_output_PS                     (* (reg32 *) Button_output__PS)
/* Data Register */
#define Button_output_DR                     (* (reg32 *) Button_output__DR)
/* Input Buffer Disable Override */
#define Button_output_INP_DIS                (* (reg32 *) Button_output__PC2)

/* Interrupt configuration Registers */
#define Button_output_INTCFG                 (* (reg32 *) Button_output__INTCFG)
#define Button_output_INTSTAT                (* (reg32 *) Button_output__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Button_output_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Button_output__SIO)
    #define Button_output_SIO_REG            (* (reg32 *) Button_output__SIO)
#endif /* (Button_output__SIO_CFG) */

/* USBIO registers */
#if !defined(Button_output__PC) && (CY_PSOC4_4200L)
    #define Button_output_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Button_output_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Button_output_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Button_output_DRIVE_MODE_SHIFT       (0x00u)
#define Button_output_DRIVE_MODE_MASK        (0x07u << Button_output_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Button_output_H */


/* [] END OF FILE */
