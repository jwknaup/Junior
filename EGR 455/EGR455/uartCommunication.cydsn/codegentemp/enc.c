/*******************************************************************************
* File Name: enc.c  
* Version 3.0
*
* Description:
*  This file provides the source code to the API for the Quadrature Decoder
*  component.
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

#if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
    #include "enc_PVT.h"
#endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */

uint8 enc_initVar = 0u;


/*******************************************************************************
* Function Name: enc_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default QuadDec configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void enc_Init(void) 
{
    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
        /* Disable Interrupt. */
        CyIntDisable(enc_ISR_NUMBER);
        /* Set the ISR to point to the enc_isr Interrupt. */
        (void) CyIntSetVector(enc_ISR_NUMBER, & enc_ISR);
        /* Set the priority. */
        CyIntSetPriority(enc_ISR_NUMBER, enc_ISR_PRIORITY);
    #endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: enc_Enable
********************************************************************************
*
* Summary:
*  This function enable interrupts from Component and also enable Component's
*  ISR in case of 32-bit counter.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void enc_Enable(void) 
{
    uint8 enableInterrupts;

    enc_SetInterruptMask(enc_INIT_INT_MASK);

    /* Clear pending interrupts. */
    (void) enc_GetEvents();
    
    enableInterrupts = CyEnterCriticalSection();

    /* Enable interrupts from Statusi register */
    enc_SR_AUX_CONTROL |= enc_INTERRUPTS_ENABLE;

    CyExitCriticalSection(enableInterrupts);        

    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
        /* Enable Component interrupts */
        CyIntEnable(enc_ISR_NUMBER);
    #endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: enc_Start
********************************************************************************
*
* Summary:
*  Initializes UDBs and other relevant hardware.
*  Resets counter, enables or disables all relevant interrupts.
*  Starts monitoring the inputs and counting.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  enc_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void enc_Start(void) 
{
    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
        enc_Cnt8_Start();
        enc_Cnt8_WriteCounter(enc_COUNTER_INIT_VALUE);
    #else
        /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) || 
        *  (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT) 
        */
        enc_Cnt16_Start();
        enc_Cnt16_WriteCounter(enc_COUNTER_INIT_VALUE);
    #endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT */
    
    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)        
       enc_count32SoftPart = 0;
    #endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */

    if (enc_initVar == 0u)
    {
        enc_Init();
        enc_initVar = 1u;
    }

    enc_Enable();
}


/*******************************************************************************
* Function Name: enc_Stop
********************************************************************************
*
* Summary:
*  Turns off UDBs and other relevant hardware.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void enc_Stop(void) 
{
    uint8 enableInterrupts;

    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
        enc_Cnt8_Stop();
    #else 
        /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) ||
        *  (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
        */
        enc_Cnt16_Stop();    /* counter disable */
    #endif /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT) */
 
    enableInterrupts = CyEnterCriticalSection();

    /* Disable interrupts interrupts from Statusi register */
    enc_SR_AUX_CONTROL &= (uint8) (~enc_INTERRUPTS_ENABLE);

    CyExitCriticalSection(enableInterrupts);

    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
        CyIntDisable(enc_ISR_NUMBER);    /* interrupt disable */
    #endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: enc_GetCounter
********************************************************************************
*
* Summary:
*  Reports the current value of the counter.
*
* Parameters:
*  None.
*
* Return:
*  The counter value. Return type is signed and per the counter size setting.
*  A positive value indicates clockwise movement (B before A).
*
* Global variables:
*  enc_count32SoftPart - used to get hi 16 bit for current value
*  of the 32-bit counter, when Counter size equal 32-bit.
*
*******************************************************************************/
int32 enc_GetCounter(void) 
{
    int32 count;
    uint16 tmpCnt;

    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
        int16 hwCount;

        CyIntDisable(enc_ISR_NUMBER);

        tmpCnt = enc_Cnt16_ReadCounter();
        hwCount = (int16) ((int32) tmpCnt - (int32) enc_COUNTER_INIT_VALUE);
        count = enc_count32SoftPart + hwCount;

        CyIntEnable(enc_ISR_NUMBER);
    #else 
        /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT) || 
        *  (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT)
        */
        #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
            tmpCnt = enc_Cnt8_ReadCounter();
        #else /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) */
            tmpCnt = enc_Cnt16_ReadCounter();
        #endif  /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT */

        count = (int32) ((int32) tmpCnt -
                (int32) enc_COUNTER_INIT_VALUE);

    #endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */ 

    return (count);
}


/*******************************************************************************
* Function Name: enc_SetCounter
********************************************************************************
*
* Summary:
*  Sets the current value of the counter.
*
* Parameters:
*  value:  The new value. Parameter type is signed and per the counter size
*  setting.
*
* Return:
*  None.
*
* Global variables:
*  enc_count32SoftPart - modified to set hi 16 bit for current
*  value of the 32-bit counter, when Counter size equal 32-bit.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void enc_SetCounter(int32 value) 
{
    #if ((enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT) || \
         (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT))
        uint16 count;
        
        if (value >= 0)
        {
            count = (uint16) value + enc_COUNTER_INIT_VALUE;
        }
        else
        {
            count = enc_COUNTER_INIT_VALUE - (uint16)(-value);
        }
        #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT)
            enc_Cnt8_WriteCounter(count);
        #else /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT) */
            enc_Cnt16_WriteCounter(count);
        #endif  /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT */
    #else /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT) */
        CyIntDisable(enc_ISR_NUMBER);

        enc_Cnt16_WriteCounter(enc_COUNTER_INIT_VALUE);
        enc_count32SoftPart = value;

        CyIntEnable(enc_ISR_NUMBER);
    #endif  /* (enc_COUNTER_SIZE == enc_COUNTER_SIZE_8_BIT) ||
             * (enc_COUNTER_SIZE == enc_COUNTER_SIZE_16_BIT)
             */
}


/*******************************************************************************
* Function Name: enc_GetEvents
********************************************************************************
* 
* Summary:
*   Reports the current status of events. This function clears the bits of the 
*   status register.
*
* Parameters:
*  None.
*
* Return:
*  The events, as bits in an unsigned 8-bit value:
*    Bit      Description
*     0        Counter overflow.
*     1        Counter underflow.
*     2        Counter reset due to index, if index input is used.
*     3        Invalid A, B inputs state transition.
*
*******************************************************************************/
uint8 enc_GetEvents(void) 
{
    return (enc_STATUS_REG & enc_INIT_INT_MASK);
}


/*******************************************************************************
* Function Name: enc_SetInterruptMask
********************************************************************************
*
* Summary:
*  Enables / disables interrupts due to the events.
*  For the 32-bit counter, the overflow, underflow and reset interrupts cannot
*  be disabled, these bits are ignored.
*
* Parameters:
*  mask: Enable / disable bits in an 8-bit value, where 1 enables the interrupt.
*
* Return:
*  None.
*
*******************************************************************************/
void enc_SetInterruptMask(uint8 mask) 
{
    #if (enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT)
        /* Underflow, Overflow and Reset interrupts for 32-bit Counter are always enable */
        mask |= (enc_COUNTER_OVERFLOW | enc_COUNTER_UNDERFLOW |
                 enc_COUNTER_RESET);
    #endif /* enc_COUNTER_SIZE == enc_COUNTER_SIZE_32_BIT */

    enc_STATUS_MASK = mask;
}


/*******************************************************************************
* Function Name: enc_GetInterruptMask
********************************************************************************
*
* Summary:
*  Reports the current interrupt mask settings.
*
* Parameters:
*  None.
*
* Return:
*  Enable / disable bits in an 8-bit value, where 1 enables the interrupt.
*  For the 32-bit counter, the overflow, underflow and reset enable bits are
*  always set.
*
*******************************************************************************/
uint8 enc_GetInterruptMask(void) 
{
    return (enc_STATUS_MASK & enc_INIT_INT_MASK);
}


/* [] END OF FILE */
