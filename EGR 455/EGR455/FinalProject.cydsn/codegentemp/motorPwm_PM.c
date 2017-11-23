/*******************************************************************************
* File Name: motorPwm_PM.c
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

#include "motorPwm.h"

static motorPwm_backupStruct motorPwm_backup;


/*******************************************************************************
* Function Name: motorPwm_SaveConfig
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
*  motorPwm_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void motorPwm_SaveConfig(void) 
{

    #if(!motorPwm_UsingFixedFunction)
        #if(!motorPwm_PWMModeIsCenterAligned)
            motorPwm_backup.PWMPeriod = motorPwm_ReadPeriod();
        #endif /* (!motorPwm_PWMModeIsCenterAligned) */
        motorPwm_backup.PWMUdb = motorPwm_ReadCounter();
        #if (motorPwm_UseStatus)
            motorPwm_backup.InterruptMaskValue = motorPwm_STATUS_MASK;
        #endif /* (motorPwm_UseStatus) */

        #if(motorPwm_DeadBandMode == motorPwm__B_PWM__DBM_256_CLOCKS || \
            motorPwm_DeadBandMode == motorPwm__B_PWM__DBM_2_4_CLOCKS)
            motorPwm_backup.PWMdeadBandValue = motorPwm_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(motorPwm_KillModeMinTime)
             motorPwm_backup.PWMKillCounterPeriod = motorPwm_ReadKillTime();
        #endif /* (motorPwm_KillModeMinTime) */

        #if(motorPwm_UseControl)
            motorPwm_backup.PWMControlRegister = motorPwm_ReadControlRegister();
        #endif /* (motorPwm_UseControl) */
    #endif  /* (!motorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: motorPwm_RestoreConfig
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
*  motorPwm_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void motorPwm_RestoreConfig(void) 
{
        #if(!motorPwm_UsingFixedFunction)
            #if(!motorPwm_PWMModeIsCenterAligned)
                motorPwm_WritePeriod(motorPwm_backup.PWMPeriod);
            #endif /* (!motorPwm_PWMModeIsCenterAligned) */

            motorPwm_WriteCounter(motorPwm_backup.PWMUdb);

            #if (motorPwm_UseStatus)
                motorPwm_STATUS_MASK = motorPwm_backup.InterruptMaskValue;
            #endif /* (motorPwm_UseStatus) */

            #if(motorPwm_DeadBandMode == motorPwm__B_PWM__DBM_256_CLOCKS || \
                motorPwm_DeadBandMode == motorPwm__B_PWM__DBM_2_4_CLOCKS)
                motorPwm_WriteDeadTime(motorPwm_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(motorPwm_KillModeMinTime)
                motorPwm_WriteKillTime(motorPwm_backup.PWMKillCounterPeriod);
            #endif /* (motorPwm_KillModeMinTime) */

            #if(motorPwm_UseControl)
                motorPwm_WriteControlRegister(motorPwm_backup.PWMControlRegister);
            #endif /* (motorPwm_UseControl) */
        #endif  /* (!motorPwm_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: motorPwm_Sleep
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
*  motorPwm_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void motorPwm_Sleep(void) 
{
    #if(motorPwm_UseControl)
        if(motorPwm_CTRL_ENABLE == (motorPwm_CONTROL & motorPwm_CTRL_ENABLE))
        {
            /*Component is enabled */
            motorPwm_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            motorPwm_backup.PWMEnableState = 0u;
        }
    #endif /* (motorPwm_UseControl) */

    /* Stop component */
    motorPwm_Stop();

    /* Save registers configuration */
    motorPwm_SaveConfig();
}


/*******************************************************************************
* Function Name: motorPwm_Wakeup
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
*  motorPwm_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void motorPwm_Wakeup(void) 
{
     /* Restore registers values */
    motorPwm_RestoreConfig();

    if(motorPwm_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        motorPwm_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
