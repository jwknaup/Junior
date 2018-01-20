/*******************************************************************************
* File Name: Servos_PM.c
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

#include "Servos.h"

static Servos_backupStruct Servos_backup;


/*******************************************************************************
* Function Name: Servos_SaveConfig
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
*  Servos_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Servos_SaveConfig(void) 
{

    #if(!Servos_UsingFixedFunction)
        #if(!Servos_PWMModeIsCenterAligned)
            Servos_backup.PWMPeriod = Servos_ReadPeriod();
        #endif /* (!Servos_PWMModeIsCenterAligned) */
        Servos_backup.PWMUdb = Servos_ReadCounter();
        #if (Servos_UseStatus)
            Servos_backup.InterruptMaskValue = Servos_STATUS_MASK;
        #endif /* (Servos_UseStatus) */

        #if(Servos_DeadBandMode == Servos__B_PWM__DBM_256_CLOCKS || \
            Servos_DeadBandMode == Servos__B_PWM__DBM_2_4_CLOCKS)
            Servos_backup.PWMdeadBandValue = Servos_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Servos_KillModeMinTime)
             Servos_backup.PWMKillCounterPeriod = Servos_ReadKillTime();
        #endif /* (Servos_KillModeMinTime) */

        #if(Servos_UseControl)
            Servos_backup.PWMControlRegister = Servos_ReadControlRegister();
        #endif /* (Servos_UseControl) */
    #endif  /* (!Servos_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Servos_RestoreConfig
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
*  Servos_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Servos_RestoreConfig(void) 
{
        #if(!Servos_UsingFixedFunction)
            #if(!Servos_PWMModeIsCenterAligned)
                Servos_WritePeriod(Servos_backup.PWMPeriod);
            #endif /* (!Servos_PWMModeIsCenterAligned) */

            Servos_WriteCounter(Servos_backup.PWMUdb);

            #if (Servos_UseStatus)
                Servos_STATUS_MASK = Servos_backup.InterruptMaskValue;
            #endif /* (Servos_UseStatus) */

            #if(Servos_DeadBandMode == Servos__B_PWM__DBM_256_CLOCKS || \
                Servos_DeadBandMode == Servos__B_PWM__DBM_2_4_CLOCKS)
                Servos_WriteDeadTime(Servos_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Servos_KillModeMinTime)
                Servos_WriteKillTime(Servos_backup.PWMKillCounterPeriod);
            #endif /* (Servos_KillModeMinTime) */

            #if(Servos_UseControl)
                Servos_WriteControlRegister(Servos_backup.PWMControlRegister);
            #endif /* (Servos_UseControl) */
        #endif  /* (!Servos_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Servos_Sleep
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
*  Servos_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Servos_Sleep(void) 
{
    #if(Servos_UseControl)
        if(Servos_CTRL_ENABLE == (Servos_CONTROL & Servos_CTRL_ENABLE))
        {
            /*Component is enabled */
            Servos_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Servos_backup.PWMEnableState = 0u;
        }
    #endif /* (Servos_UseControl) */

    /* Stop component */
    Servos_Stop();

    /* Save registers configuration */
    Servos_SaveConfig();
}


/*******************************************************************************
* Function Name: Servos_Wakeup
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
*  Servos_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Servos_Wakeup(void) 
{
     /* Restore registers values */
    Servos_RestoreConfig();

    if(Servos_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Servos_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
