/*******************************************************************************
* File Name: flexSensorB.c  
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
#include "flexSensorB.h"

static flexSensorB_BACKUP_STRUCT  flexSensorB_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: flexSensorB_Sleep
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
*  \snippet flexSensorB_SUT.c usage_flexSensorB_Sleep_Wakeup
*******************************************************************************/
void flexSensorB_Sleep(void)
{
    #if defined(flexSensorB__PC)
        flexSensorB_backup.pcState = flexSensorB_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            flexSensorB_backup.usbState = flexSensorB_CR1_REG;
            flexSensorB_USB_POWER_REG |= flexSensorB_USBIO_ENTER_SLEEP;
            flexSensorB_CR1_REG &= flexSensorB_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(flexSensorB__SIO)
        flexSensorB_backup.sioState = flexSensorB_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        flexSensorB_SIO_REG &= (uint32)(~flexSensorB_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: flexSensorB_Wakeup
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
*  Refer to flexSensorB_Sleep() for an example usage.
*******************************************************************************/
void flexSensorB_Wakeup(void)
{
    #if defined(flexSensorB__PC)
        flexSensorB_PC = flexSensorB_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            flexSensorB_USB_POWER_REG &= flexSensorB_USBIO_EXIT_SLEEP_PH1;
            flexSensorB_CR1_REG = flexSensorB_backup.usbState;
            flexSensorB_USB_POWER_REG &= flexSensorB_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(flexSensorB__SIO)
        flexSensorB_SIO_REG = flexSensorB_backup.sioState;
    #endif
}


/* [] END OF FILE */
