/*******************************************************************************
* File Name: servoPwm_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "servoPwm.h"

static servoPwm_backupStruct servoPwm_backup;


/*******************************************************************************
* Function Name: servoPwm_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  servoPwm_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void servoPwm_SaveConfig(void) 
{

    #if(!servoPwm_UsingFixedFunction)
        #if(!servoPwm_PWMModeIsCenterAligned)
            servoPwm_backup.PWMPeriod = servoPwm_ReadPeriod();
        #endif /* (!servoPwm_PWMModeIsCenterAligned) */
        servoPwm_backup.PWMUdb = servoPwm_ReadCounter();
        #if (servoPwm_UseStatus)
            servoPwm_backup.InterruptMaskValue = servoPwm_STATUS_MASK;
        #endif /* (servoPwm_UseStatus) */

        #if(servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_256_CLOCKS || \
            servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_2_4_CLOCKS)
            servoPwm_backup.PWMdeadBandValue = servoPwm_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(servoPwm_KillModeMinTime)
             servoPwm_backup.PWMKillCounterPeriod = servoPwm_ReadKillTime();
        #endif /* (servoPwm_KillModeMinTime) */

        #if(servoPwm_UseControl)
            servoPwm_backup.PWMControlRegister = servoPwm_ReadControlRegister();
        #endif /* (servoPwm_UseControl) */
    #endif  /* (!servoPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: servoPwm_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  servoPwm_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void servoPwm_RestoreConfig(void) 
{
        #if(!servoPwm_UsingFixedFunction)
            #if(!servoPwm_PWMModeIsCenterAligned)
                servoPwm_WritePeriod(servoPwm_backup.PWMPeriod);
            #endif /* (!servoPwm_PWMModeIsCenterAligned) */

            servoPwm_WriteCounter(servoPwm_backup.PWMUdb);

            #if (servoPwm_UseStatus)
                servoPwm_STATUS_MASK = servoPwm_backup.InterruptMaskValue;
            #endif /* (servoPwm_UseStatus) */

            #if(servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_256_CLOCKS || \
                servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_2_4_CLOCKS)
                servoPwm_WriteDeadTime(servoPwm_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(servoPwm_KillModeMinTime)
                servoPwm_WriteKillTime(servoPwm_backup.PWMKillCounterPeriod);
            #endif /* (servoPwm_KillModeMinTime) */

            #if(servoPwm_UseControl)
                servoPwm_WriteControlRegister(servoPwm_backup.PWMControlRegister);
            #endif /* (servoPwm_UseControl) */
        #endif  /* (!servoPwm_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: servoPwm_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  servoPwm_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void servoPwm_Sleep(void) 
{
    #if(servoPwm_UseControl)
        if(servoPwm_CTRL_ENABLE == (servoPwm_CONTROL & servoPwm_CTRL_ENABLE))
        {
            /*Component is enabled */
            servoPwm_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            servoPwm_backup.PWMEnableState = 0u;
        }
    #endif /* (servoPwm_UseControl) */

    /* Stop component */
    servoPwm_Stop();

    /* Save registers configuration */
    servoPwm_SaveConfig();
}


/*******************************************************************************
* Function Name: servoPwm_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  servoPwm_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void servoPwm_Wakeup(void) 
{
     /* Restore registers values */
    servoPwm_RestoreConfig();

    if(servoPwm_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        servoPwm_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
