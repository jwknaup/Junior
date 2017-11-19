/*******************************************************************************
* File Name: pwm1_PM.c
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

#include "pwm1.h"

static pwm1_backupStruct pwm1_backup;


/*******************************************************************************
* Function Name: pwm1_SaveConfig
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
*  pwm1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void pwm1_SaveConfig(void) 
{

    #if(!pwm1_UsingFixedFunction)
        #if(!pwm1_PWMModeIsCenterAligned)
            pwm1_backup.PWMPeriod = pwm1_ReadPeriod();
        #endif /* (!pwm1_PWMModeIsCenterAligned) */
        pwm1_backup.PWMUdb = pwm1_ReadCounter();
        #if (pwm1_UseStatus)
            pwm1_backup.InterruptMaskValue = pwm1_STATUS_MASK;
        #endif /* (pwm1_UseStatus) */

        #if(pwm1_DeadBandMode == pwm1__B_PWM__DBM_256_CLOCKS || \
            pwm1_DeadBandMode == pwm1__B_PWM__DBM_2_4_CLOCKS)
            pwm1_backup.PWMdeadBandValue = pwm1_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(pwm1_KillModeMinTime)
             pwm1_backup.PWMKillCounterPeriod = pwm1_ReadKillTime();
        #endif /* (pwm1_KillModeMinTime) */

        #if(pwm1_UseControl)
            pwm1_backup.PWMControlRegister = pwm1_ReadControlRegister();
        #endif /* (pwm1_UseControl) */
    #endif  /* (!pwm1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: pwm1_RestoreConfig
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
*  pwm1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void pwm1_RestoreConfig(void) 
{
        #if(!pwm1_UsingFixedFunction)
            #if(!pwm1_PWMModeIsCenterAligned)
                pwm1_WritePeriod(pwm1_backup.PWMPeriod);
            #endif /* (!pwm1_PWMModeIsCenterAligned) */

            pwm1_WriteCounter(pwm1_backup.PWMUdb);

            #if (pwm1_UseStatus)
                pwm1_STATUS_MASK = pwm1_backup.InterruptMaskValue;
            #endif /* (pwm1_UseStatus) */

            #if(pwm1_DeadBandMode == pwm1__B_PWM__DBM_256_CLOCKS || \
                pwm1_DeadBandMode == pwm1__B_PWM__DBM_2_4_CLOCKS)
                pwm1_WriteDeadTime(pwm1_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(pwm1_KillModeMinTime)
                pwm1_WriteKillTime(pwm1_backup.PWMKillCounterPeriod);
            #endif /* (pwm1_KillModeMinTime) */

            #if(pwm1_UseControl)
                pwm1_WriteControlRegister(pwm1_backup.PWMControlRegister);
            #endif /* (pwm1_UseControl) */
        #endif  /* (!pwm1_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: pwm1_Sleep
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
*  pwm1_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void pwm1_Sleep(void) 
{
    #if(pwm1_UseControl)
        if(pwm1_CTRL_ENABLE == (pwm1_CONTROL & pwm1_CTRL_ENABLE))
        {
            /*Component is enabled */
            pwm1_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            pwm1_backup.PWMEnableState = 0u;
        }
    #endif /* (pwm1_UseControl) */

    /* Stop component */
    pwm1_Stop();

    /* Save registers configuration */
    pwm1_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm1_Wakeup
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
*  pwm1_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void pwm1_Wakeup(void) 
{
     /* Restore registers values */
    pwm1_RestoreConfig();

    if(pwm1_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        pwm1_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
