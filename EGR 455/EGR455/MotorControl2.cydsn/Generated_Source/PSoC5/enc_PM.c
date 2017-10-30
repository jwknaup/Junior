/*******************************************************************************
* File Name: enc_PM.c
* Version 3.0
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "enc.h"

static enc_BACKUP_STRUCT enc_backup = {0u};


/*******************************************************************************
* Function Name: enc_SaveConfig
********************************************************************************
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void enc_SaveConfig(void) 
{
    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
        enc_Cnt8_SaveConfig();
    #else 
        /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) || 
         * (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
         */
        enc_Cnt16_SaveConfig();
    #endif /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: enc_RestoreConfig
********************************************************************************
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void enc_RestoreConfig(void) 
{
    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
        enc_Cnt8_RestoreConfig();
    #else 
        /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) || 
         * (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT) 
         */
        enc_Cnt16_RestoreConfig();
    #endif /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: enc_Sleep
********************************************************************************
* 
* Summary:
*  Prepare Quadrature Decoder Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  enc_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void enc_Sleep(void) 
{
    if (0u != (enc_SR_AUX_CONTROL & enc_INTERRUPTS_ENABLE))
    {
        enc_backup.enableState = 1u;
    }
    else /* The Quadrature Decoder Component is disabled */
    {
        enc_backup.enableState = 0u;
    }

    enc_Stop();
    enc_SaveConfig();
}


/*******************************************************************************
* Function Name: enc_Wakeup
********************************************************************************
*
* Summary:
*  Prepare Quadrature Decoder Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  enc_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void enc_Wakeup(void) 
{
    enc_RestoreConfig();

    if (enc_backup.enableState != 0u)
    {
        #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
            enc_Cnt8_Enable();
        #else 
            /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) || 
            *  (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT) 
            */
            enc_Cnt16_Enable();
        #endif /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT) */

        /* Enable component's operation */
        enc_Enable();
    } /* Do nothing if component's block was disabled before */
}


/* [] END OF FILE */

