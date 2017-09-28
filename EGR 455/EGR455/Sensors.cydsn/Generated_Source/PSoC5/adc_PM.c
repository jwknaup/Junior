/*******************************************************************************
* File Name: adc_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "adc.h"
#include "adc_SAR.h"
#if(adc_CLOCK_SOURCE == adc_CLOCK_INTERNAL)
    #include "adc_IntClock.h"
#endif   /* adc_CLOCK_SOURCE == adc_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: adc_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void adc_Sleep(void)
{
    adc_SAR_Stop();
    adc_SAR_Sleep();
    adc_Disable();

    #if(adc_CLOCK_SOURCE == adc_CLOCK_INTERNAL)
        adc_IntClock_Stop();
    #endif   /* adc_CLOCK_SOURCE == adc_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: adc_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void adc_Wakeup(void)
{
    adc_SAR_Wakeup();
    adc_SAR_Enable();

    #if(adc_CLOCK_SOURCE == adc_CLOCK_INTERNAL)
        adc_IntClock_Start();
    #endif   /* adc_CLOCK_SOURCE == adc_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    adc_Enable();

    #if(adc_SAMPLE_MODE == adc_SAMPLE_MODE_FREE_RUNNING)
        adc_SAR_StartConvert();
    #endif /* (adc_SAMPLE_MODE == adc_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(adc_STATUS_PTR);
}


/*******************************************************************************
* Function Name: adc_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void adc_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: adc_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void adc_RestoreConfig(void)
{

}


/* [] END OF FILE */
