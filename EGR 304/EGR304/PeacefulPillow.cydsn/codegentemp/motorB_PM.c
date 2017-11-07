/*******************************************************************************
* File Name: motorB.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "motorB.h"

static motorB_BACKUP_STRUCT  motorB_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: motorB_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet motorB_SUT.c usage_motorB_Sleep_Wakeup
*******************************************************************************/
void motorB_Sleep(void)
{
    #if defined(motorB__PC)
        motorB_backup.pcState = motorB_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            motorB_backup.usbState = motorB_CR1_REG;
            motorB_USB_POWER_REG |= motorB_USBIO_ENTER_SLEEP;
            motorB_CR1_REG &= motorB_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(motorB__SIO)
        motorB_backup.sioState = motorB_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        motorB_SIO_REG &= (uint32)(~motorB_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: motorB_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to motorB_Sleep() for an example usage.
*******************************************************************************/
void motorB_Wakeup(void)
{
    #if defined(motorB__PC)
        motorB_PC = motorB_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            motorB_USB_POWER_REG &= motorB_USBIO_EXIT_SLEEP_PH1;
            motorB_CR1_REG = motorB_backup.usbState;
            motorB_USB_POWER_REG &= motorB_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(motorB__SIO)
        motorB_SIO_REG = motorB_backup.sioState;
    #endif
}


/* [] END OF FILE */
