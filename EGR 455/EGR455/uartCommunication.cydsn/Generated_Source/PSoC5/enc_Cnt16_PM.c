/*******************************************************************************
* File Name: enc_Cnt16_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "enc_Cnt16.h"

static enc_Cnt16_backupStruct enc_Cnt16_backup;


/*******************************************************************************
* Function Name: enc_Cnt16_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  enc_Cnt16_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void enc_Cnt16_SaveConfig(void) 
{
    #if (!enc_Cnt16_UsingFixedFunction)

        enc_Cnt16_backup.CounterUdb = enc_Cnt16_ReadCounter();

        #if(!enc_Cnt16_ControlRegRemoved)
            enc_Cnt16_backup.CounterControlRegister = enc_Cnt16_ReadControlRegister();
        #endif /* (!enc_Cnt16_ControlRegRemoved) */

    #endif /* (!enc_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: enc_Cnt16_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  enc_Cnt16_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void enc_Cnt16_RestoreConfig(void) 
{      
    #if (!enc_Cnt16_UsingFixedFunction)

       enc_Cnt16_WriteCounter(enc_Cnt16_backup.CounterUdb);

        #if(!enc_Cnt16_ControlRegRemoved)
            enc_Cnt16_WriteControlRegister(enc_Cnt16_backup.CounterControlRegister);
        #endif /* (!enc_Cnt16_ControlRegRemoved) */

    #endif /* (!enc_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: enc_Cnt16_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  enc_Cnt16_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void enc_Cnt16_Sleep(void) 
{
    #if(!enc_Cnt16_ControlRegRemoved)
        /* Save Counter's enable state */
        if(enc_Cnt16_CTRL_ENABLE == (enc_Cnt16_CONTROL & enc_Cnt16_CTRL_ENABLE))
        {
            /* Counter is enabled */
            enc_Cnt16_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            enc_Cnt16_backup.CounterEnableState = 0u;
        }
    #else
        enc_Cnt16_backup.CounterEnableState = 1u;
        if(enc_Cnt16_backup.CounterEnableState != 0u)
        {
            enc_Cnt16_backup.CounterEnableState = 0u;
        }
    #endif /* (!enc_Cnt16_ControlRegRemoved) */
    
    enc_Cnt16_Stop();
    enc_Cnt16_SaveConfig();
}


/*******************************************************************************
* Function Name: enc_Cnt16_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  enc_Cnt16_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void enc_Cnt16_Wakeup(void) 
{
    enc_Cnt16_RestoreConfig();
    #if(!enc_Cnt16_ControlRegRemoved)
        if(enc_Cnt16_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            enc_Cnt16_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!enc_Cnt16_ControlRegRemoved) */
    
}


/* [] END OF FILE */
