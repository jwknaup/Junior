/*******************************************************************************
* File Name: uart2_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "uart2.h"


/***************************************
* Local data allocation
***************************************/

static uart2_BACKUP_STRUCT  uart2_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: uart2_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component nonretention control register.
*  Does not save the FIFO which is a set of nonretention registers.
*  This function is called by the uart2_Sleep() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  uart2_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void uart2_SaveConfig(void)
{
    #if(uart2_CONTROL_REG_REMOVED == 0u)
        uart2_backup.cr = uart2_CONTROL_REG;
    #endif /* End uart2_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: uart2_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the nonretention control register except FIFO.
*  Does not restore the FIFO which is a set of nonretention registers.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  uart2_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
* Notes:
*  If this function is called without calling uart2_SaveConfig() 
*  first, the data loaded may be incorrect.
*
*******************************************************************************/
void uart2_RestoreConfig(void)
{
    #if(uart2_CONTROL_REG_REMOVED == 0u)
        uart2_CONTROL_REG = uart2_backup.cr;
    #endif /* End uart2_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: uart2_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. 
*  The uart2_Sleep() API saves the current component state. Then it
*  calls the uart2_Stop() function and calls 
*  uart2_SaveConfig() to save the hardware configuration.
*  Call the uart2_Sleep() function before calling the CyPmSleep() 
*  or the CyPmHibernate() function. 
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  uart2_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void uart2_Sleep(void)
{
    #if(uart2_RX_ENABLED || uart2_HD_ENABLED)
        if((uart2_RXSTATUS_ACTL_REG  & uart2_INT_ENABLE) != 0u)
        {
            uart2_backup.enableState = 1u;
        }
        else
        {
            uart2_backup.enableState = 0u;
        }
    #else
        if((uart2_TXSTATUS_ACTL_REG  & uart2_INT_ENABLE) !=0u)
        {
            uart2_backup.enableState = 1u;
        }
        else
        {
            uart2_backup.enableState = 0u;
        }
    #endif /* End uart2_RX_ENABLED || uart2_HD_ENABLED*/

    uart2_Stop();
    uart2_SaveConfig();
}


/*******************************************************************************
* Function Name: uart2_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when 
*  uart2_Sleep() was called. The uart2_Wakeup() function
*  calls the uart2_RestoreConfig() function to restore the 
*  configuration. If the component was enabled before the 
*  uart2_Sleep() function was called, the uart2_Wakeup()
*  function will also re-enable the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  uart2_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void uart2_Wakeup(void)
{
    uart2_RestoreConfig();
    #if( (uart2_RX_ENABLED) || (uart2_HD_ENABLED) )
        uart2_ClearRxBuffer();
    #endif /* End (uart2_RX_ENABLED) || (uart2_HD_ENABLED) */
    #if(uart2_TX_ENABLED || uart2_HD_ENABLED)
        uart2_ClearTxBuffer();
    #endif /* End uart2_TX_ENABLED || uart2_HD_ENABLED */

    if(uart2_backup.enableState != 0u)
    {
        uart2_Enable();
    }
}


/* [] END OF FILE */
