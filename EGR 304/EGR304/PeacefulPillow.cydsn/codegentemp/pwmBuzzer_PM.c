/*******************************************************************************
* File Name: pwmBuzzer_PM.c
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

#include "pwmBuzzer.h"

static pwmBuzzer_backupStruct pwmBuzzer_backup;


/*******************************************************************************
* Function Name: pwmBuzzer_SaveConfig
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
*  pwmBuzzer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void pwmBuzzer_SaveConfig(void) 
{

    #if(!pwmBuzzer_UsingFixedFunction)
        #if(!pwmBuzzer_PWMModeIsCenterAligned)
            pwmBuzzer_backup.PWMPeriod = pwmBuzzer_ReadPeriod();
        #endif /* (!pwmBuzzer_PWMModeIsCenterAligned) */
        pwmBuzzer_backup.PWMUdb = pwmBuzzer_ReadCounter();
        #if (pwmBuzzer_UseStatus)
            pwmBuzzer_backup.InterruptMaskValue = pwmBuzzer_STATUS_MASK;
        #endif /* (pwmBuzzer_UseStatus) */

        #if(pwmBuzzer_DeadBandMode == pwmBuzzer__B_PWM__DBM_256_CLOCKS || \
            pwmBuzzer_DeadBandMode == pwmBuzzer__B_PWM__DBM_2_4_CLOCKS)
            pwmBuzzer_backup.PWMdeadBandValue = pwmBuzzer_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(pwmBuzzer_KillModeMinTime)
             pwmBuzzer_backup.PWMKillCounterPeriod = pwmBuzzer_ReadKillTime();
        #endif /* (pwmBuzzer_KillModeMinTime) */

        #if(pwmBuzzer_UseControl)
            pwmBuzzer_backup.PWMControlRegister = pwmBuzzer_ReadControlRegister();
        #endif /* (pwmBuzzer_UseControl) */
    #endif  /* (!pwmBuzzer_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: pwmBuzzer_RestoreConfig
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
*  pwmBuzzer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void pwmBuzzer_RestoreConfig(void) 
{
        #if(!pwmBuzzer_UsingFixedFunction)
            #if(!pwmBuzzer_PWMModeIsCenterAligned)
                pwmBuzzer_WritePeriod(pwmBuzzer_backup.PWMPeriod);
            #endif /* (!pwmBuzzer_PWMModeIsCenterAligned) */

            pwmBuzzer_WriteCounter(pwmBuzzer_backup.PWMUdb);

            #if (pwmBuzzer_UseStatus)
                pwmBuzzer_STATUS_MASK = pwmBuzzer_backup.InterruptMaskValue;
            #endif /* (pwmBuzzer_UseStatus) */

            #if(pwmBuzzer_DeadBandMode == pwmBuzzer__B_PWM__DBM_256_CLOCKS || \
                pwmBuzzer_DeadBandMode == pwmBuzzer__B_PWM__DBM_2_4_CLOCKS)
                pwmBuzzer_WriteDeadTime(pwmBuzzer_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(pwmBuzzer_KillModeMinTime)
                pwmBuzzer_WriteKillTime(pwmBuzzer_backup.PWMKillCounterPeriod);
            #endif /* (pwmBuzzer_KillModeMinTime) */

            #if(pwmBuzzer_UseControl)
                pwmBuzzer_WriteControlRegister(pwmBuzzer_backup.PWMControlRegister);
            #endif /* (pwmBuzzer_UseControl) */
        #endif  /* (!pwmBuzzer_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: pwmBuzzer_Sleep
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
*  pwmBuzzer_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void pwmBuzzer_Sleep(void) 
{
    #if(pwmBuzzer_UseControl)
        if(pwmBuzzer_CTRL_ENABLE == (pwmBuzzer_CONTROL & pwmBuzzer_CTRL_ENABLE))
        {
            /*Component is enabled */
            pwmBuzzer_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            pwmBuzzer_backup.PWMEnableState = 0u;
        }
    #endif /* (pwmBuzzer_UseControl) */

    /* Stop component */
    pwmBuzzer_Stop();

    /* Save registers configuration */
    pwmBuzzer_SaveConfig();
}


/*******************************************************************************
* Function Name: pwmBuzzer_Wakeup
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
*  pwmBuzzer_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void pwmBuzzer_Wakeup(void) 
{
     /* Restore registers values */
    pwmBuzzer_RestoreConfig();

    if(pwmBuzzer_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        pwmBuzzer_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
