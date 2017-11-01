/*******************************************************************************
* File Name: enc_INT.c
* Version 3.0
*
* Description:
*  This file contains the Interrupt Service Routine (ISR) for the Quadrature
*  Decoder component.
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
#include "enc_PVT.h"
#include "cyapicallbacks.h"

volatile int32 enc_count32SoftPart = 0;


/*******************************************************************************
* FUNCTION NAME: void enc_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for Quadrature Decoder Component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  enc_count32SoftPart - modified to update hi 16 bit for current
*  value of the 32-bit counter, when Counter size equal 32-bit.
*  enc_swStatus - modified with the updated values of STATUS
*  register.
*
*******************************************************************************/
CY_ISR( enc_ISR )
{
   uint8 enc_swStatus;

   enc_swStatus = enc_STATUS_REG;

    #ifdef enc_ISR_ENTRY_CALLBACK
        enc_ISR_EntryCallback();
    #endif /* enc_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START enc_ISR_START` */

    /* `#END` */

    if (0u != (enc_swStatus & enc_COUNTER_OVERFLOW))
    {
        enc_count32SoftPart += (int32) enc_COUNTER_MAX_VALUE;
    }
    else if (0u != (enc_swStatus & enc_COUNTER_UNDERFLOW))
    {
        enc_count32SoftPart -= (int32) enc_COUNTER_INIT_VALUE;
    }
    else
    {
        /* Nothing to do here */
    }
    
    if (0u != (enc_swStatus & enc_COUNTER_RESET))
    {
        enc_count32SoftPart = 0;
    }
    
    /* User code required at end of ISR */
    /* `#START enc_ISR_END` */

    /* `#END` */

    #ifdef enc_ISR_EXIT_CALLBACK
        enc_ISR_ExitCallback();
    #endif /* enc_ISR_EXIT_CALLBACK */
}


/* [] END OF FILE */
