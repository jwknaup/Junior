/*******************************************************************************
* File Name: servoPwm.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "servoPwm.h"

/* Error message for removed <resource> through optimization */
#ifdef servoPwm_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* servoPwm_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 servoPwm_initVar = 0u;


/*******************************************************************************
* Function Name: servoPwm_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  servoPwm_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void servoPwm_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(servoPwm_initVar == 0u)
    {
        servoPwm_Init();
        servoPwm_initVar = 1u;
    }
    servoPwm_Enable();

}


/*******************************************************************************
* Function Name: servoPwm_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  servoPwm_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void servoPwm_Init(void) 
{
    #if (servoPwm_UsingFixedFunction || servoPwm_UseControl)
        uint8 ctrl;
    #endif /* (servoPwm_UsingFixedFunction || servoPwm_UseControl) */

    #if(!servoPwm_UsingFixedFunction)
        #if(servoPwm_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 servoPwm_interruptState;
        #endif /* (servoPwm_UseStatus) */
    #endif /* (!servoPwm_UsingFixedFunction) */

    #if (servoPwm_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        servoPwm_CONTROL |= servoPwm_CFG0_MODE;
        #if (servoPwm_DeadBand2_4)
            servoPwm_CONTROL |= servoPwm_CFG0_DB;
        #endif /* (servoPwm_DeadBand2_4) */

        ctrl = servoPwm_CONTROL3 & ((uint8 )(~servoPwm_CTRL_CMPMODE1_MASK));
        servoPwm_CONTROL3 = ctrl | servoPwm_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        servoPwm_RT1 &= ((uint8)(~servoPwm_RT1_MASK));
        servoPwm_RT1 |= servoPwm_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        servoPwm_RT1 &= ((uint8)(~servoPwm_SYNCDSI_MASK));
        servoPwm_RT1 |= servoPwm_SYNCDSI_EN;

    #elif (servoPwm_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = servoPwm_CONTROL & ((uint8)(~servoPwm_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~servoPwm_CTRL_CMPMODE1_MASK));
        servoPwm_CONTROL = ctrl | servoPwm_DEFAULT_COMPARE2_MODE |
                                   servoPwm_DEFAULT_COMPARE1_MODE;
    #endif /* (servoPwm_UsingFixedFunction) */

    #if (!servoPwm_UsingFixedFunction)
        #if (servoPwm_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            servoPwm_AUX_CONTROLDP0 |= (servoPwm_AUX_CTRL_FIFO0_CLR);
        #else /* (servoPwm_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            servoPwm_AUX_CONTROLDP0 |= (servoPwm_AUX_CTRL_FIFO0_CLR);
            servoPwm_AUX_CONTROLDP1 |= (servoPwm_AUX_CTRL_FIFO0_CLR);
        #endif /* (servoPwm_Resolution == 8) */

        servoPwm_WriteCounter(servoPwm_INIT_PERIOD_VALUE);
    #endif /* (!servoPwm_UsingFixedFunction) */

    servoPwm_WritePeriod(servoPwm_INIT_PERIOD_VALUE);

        #if (servoPwm_UseOneCompareMode)
            servoPwm_WriteCompare(servoPwm_INIT_COMPARE_VALUE1);
        #else
            servoPwm_WriteCompare1(servoPwm_INIT_COMPARE_VALUE1);
            servoPwm_WriteCompare2(servoPwm_INIT_COMPARE_VALUE2);
        #endif /* (servoPwm_UseOneCompareMode) */

        #if (servoPwm_KillModeMinTime)
            servoPwm_WriteKillTime(servoPwm_MinimumKillTime);
        #endif /* (servoPwm_KillModeMinTime) */

        #if (servoPwm_DeadBandUsed)
            servoPwm_WriteDeadTime(servoPwm_INIT_DEAD_TIME);
        #endif /* (servoPwm_DeadBandUsed) */

    #if (servoPwm_UseStatus || servoPwm_UsingFixedFunction)
        servoPwm_SetInterruptMode(servoPwm_INIT_INTERRUPTS_MODE);
    #endif /* (servoPwm_UseStatus || servoPwm_UsingFixedFunction) */

    #if (servoPwm_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        servoPwm_GLOBAL_ENABLE |= servoPwm_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        servoPwm_CONTROL2 |= servoPwm_CTRL2_IRQ_SEL;
    #else
        #if(servoPwm_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            servoPwm_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            servoPwm_STATUS_AUX_CTRL |= servoPwm_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(servoPwm_interruptState);

            /* Clear the FIFO to enable the servoPwm_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            servoPwm_ClearFIFO();
        #endif /* (servoPwm_UseStatus) */
    #endif /* (servoPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: servoPwm_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void servoPwm_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (servoPwm_UsingFixedFunction)
        servoPwm_GLOBAL_ENABLE |= servoPwm_BLOCK_EN_MASK;
        servoPwm_GLOBAL_STBY_ENABLE |= servoPwm_BLOCK_STBY_EN_MASK;
    #endif /* (servoPwm_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (servoPwm_UseControl || servoPwm_UsingFixedFunction)
        servoPwm_CONTROL |= servoPwm_CTRL_ENABLE;
    #endif /* (servoPwm_UseControl || servoPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: servoPwm_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void servoPwm_Stop(void) 
{
    #if (servoPwm_UseControl || servoPwm_UsingFixedFunction)
        servoPwm_CONTROL &= ((uint8)(~servoPwm_CTRL_ENABLE));
    #endif /* (servoPwm_UseControl || servoPwm_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (servoPwm_UsingFixedFunction)
        servoPwm_GLOBAL_ENABLE &= ((uint8)(~servoPwm_BLOCK_EN_MASK));
        servoPwm_GLOBAL_STBY_ENABLE &= ((uint8)(~servoPwm_BLOCK_STBY_EN_MASK));
    #endif /* (servoPwm_UsingFixedFunction) */
}

#if (servoPwm_UseOneCompareMode)
    #if (servoPwm_CompareMode1SW)


        /*******************************************************************************
        * Function Name: servoPwm_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void servoPwm_SetCompareMode(uint8 comparemode) 
        {
            #if(servoPwm_UsingFixedFunction)

                #if(0 != servoPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << servoPwm_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != servoPwm_CTRL_CMPMODE1_SHIFT) */

                servoPwm_CONTROL3 &= ((uint8)(~servoPwm_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                servoPwm_CONTROL3 |= comparemodemasked;

            #elif (servoPwm_UseControl)

                #if(0 != servoPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << servoPwm_CTRL_CMPMODE1_SHIFT)) &
                                                servoPwm_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & servoPwm_CTRL_CMPMODE1_MASK;
                #endif /* (0 != servoPwm_CTRL_CMPMODE1_SHIFT) */

                #if(0 != servoPwm_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << servoPwm_CTRL_CMPMODE2_SHIFT)) &
                                               servoPwm_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & servoPwm_CTRL_CMPMODE2_MASK;
                #endif /* (0 != servoPwm_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                servoPwm_CONTROL &= ((uint8)(~(servoPwm_CTRL_CMPMODE1_MASK |
                                            servoPwm_CTRL_CMPMODE2_MASK)));
                servoPwm_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (servoPwm_UsingFixedFunction) */
        }
    #endif /* servoPwm_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (servoPwm_CompareMode1SW)


        /*******************************************************************************
        * Function Name: servoPwm_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void servoPwm_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != servoPwm_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << servoPwm_CTRL_CMPMODE1_SHIFT)) &
                                           servoPwm_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & servoPwm_CTRL_CMPMODE1_MASK;
            #endif /* (0 != servoPwm_CTRL_CMPMODE1_SHIFT) */

            #if (servoPwm_UseControl)
                servoPwm_CONTROL &= ((uint8)(~servoPwm_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                servoPwm_CONTROL |= comparemodemasked;
            #endif /* (servoPwm_UseControl) */
        }
    #endif /* servoPwm_CompareMode1SW */

#if (servoPwm_CompareMode2SW)


    /*******************************************************************************
    * Function Name: servoPwm_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void servoPwm_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != servoPwm_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << servoPwm_CTRL_CMPMODE2_SHIFT)) &
                                                 servoPwm_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & servoPwm_CTRL_CMPMODE2_MASK;
        #endif /* (0 != servoPwm_CTRL_CMPMODE2_SHIFT) */

        #if (servoPwm_UseControl)
            servoPwm_CONTROL &= ((uint8)(~servoPwm_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            servoPwm_CONTROL |= comparemodemasked;
        #endif /* (servoPwm_UseControl) */
    }
    #endif /*servoPwm_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!servoPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: servoPwm_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void servoPwm_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(servoPwm_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: servoPwm_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 servoPwm_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(servoPwm_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(servoPwm_CAPTURE_LSB_PTR));
    }

    #if (servoPwm_UseStatus)


        /*******************************************************************************
        * Function Name: servoPwm_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void servoPwm_ClearFIFO(void) 
        {
            while(0u != (servoPwm_ReadStatusRegister() & servoPwm_STATUS_FIFONEMPTY))
            {
                (void)servoPwm_ReadCapture();
            }
        }

    #endif /* servoPwm_UseStatus */

#endif /* !servoPwm_UsingFixedFunction */


/*******************************************************************************
* Function Name: servoPwm_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void servoPwm_WritePeriod(uint16 period) 
{
    #if(servoPwm_UsingFixedFunction)
        CY_SET_REG16(servoPwm_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(servoPwm_PERIOD_LSB_PTR, period);
    #endif /* (servoPwm_UsingFixedFunction) */
}

#if (servoPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: servoPwm_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void servoPwm_WriteCompare(uint16 compare) \
                                       
    {
        #if(servoPwm_UsingFixedFunction)
            CY_SET_REG16(servoPwm_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(servoPwm_COMPARE1_LSB_PTR, compare);
        #endif /* (servoPwm_UsingFixedFunction) */

        #if (servoPwm_PWMMode == servoPwm__B_PWM__DITHER)
            #if(servoPwm_UsingFixedFunction)
                CY_SET_REG16(servoPwm_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(servoPwm_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (servoPwm_UsingFixedFunction) */
        #endif /* (servoPwm_PWMMode == servoPwm__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: servoPwm_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void servoPwm_WriteCompare1(uint16 compare) \
                                        
    {
        #if(servoPwm_UsingFixedFunction)
            CY_SET_REG16(servoPwm_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(servoPwm_COMPARE1_LSB_PTR, compare);
        #endif /* (servoPwm_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: servoPwm_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void servoPwm_WriteCompare2(uint16 compare) \
                                        
    {
        #if(servoPwm_UsingFixedFunction)
            CY_SET_REG16(servoPwm_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(servoPwm_COMPARE2_LSB_PTR, compare);
        #endif /* (servoPwm_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (servoPwm_DeadBandUsed)


    /*******************************************************************************
    * Function Name: servoPwm_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void servoPwm_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!servoPwm_DeadBand2_4)
            CY_SET_REG8(servoPwm_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            servoPwm_DEADBAND_COUNT &= ((uint8)(~servoPwm_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(servoPwm_DEADBAND_COUNT_SHIFT)
                servoPwm_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << servoPwm_DEADBAND_COUNT_SHIFT)) &
                                                    servoPwm_DEADBAND_COUNT_MASK;
            #else
                servoPwm_DEADBAND_COUNT |= deadtime & servoPwm_DEADBAND_COUNT_MASK;
            #endif /* (servoPwm_DEADBAND_COUNT_SHIFT) */

        #endif /* (!servoPwm_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: servoPwm_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 servoPwm_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!servoPwm_DeadBand2_4)
            return (CY_GET_REG8(servoPwm_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(servoPwm_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(servoPwm_DEADBAND_COUNT & servoPwm_DEADBAND_COUNT_MASK)) >>
                                                                           servoPwm_DEADBAND_COUNT_SHIFT));
            #else
                return (servoPwm_DEADBAND_COUNT & servoPwm_DEADBAND_COUNT_MASK);
            #endif /* (servoPwm_DEADBAND_COUNT_SHIFT) */
        #endif /* (!servoPwm_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (servoPwm_UseStatus || servoPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: servoPwm_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void servoPwm_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(servoPwm_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: servoPwm_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 servoPwm_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(servoPwm_STATUS_PTR));
    }

#endif /* (servoPwm_UseStatus || servoPwm_UsingFixedFunction) */


#if (servoPwm_UseControl)


    /*******************************************************************************
    * Function Name: servoPwm_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 servoPwm_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(servoPwm_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: servoPwm_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void servoPwm_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(servoPwm_CONTROL_PTR, control);
    }

#endif /* (servoPwm_UseControl) */


#if (!servoPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: servoPwm_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 servoPwm_ReadCapture(void) 
    {
        return (CY_GET_REG16(servoPwm_CAPTURE_LSB_PTR));
    }

#endif /* (!servoPwm_UsingFixedFunction) */


#if (servoPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: servoPwm_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 servoPwm_ReadCompare(void) 
    {
        #if(servoPwm_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(servoPwm_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(servoPwm_COMPARE1_LSB_PTR));
        #endif /* (servoPwm_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: servoPwm_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 servoPwm_ReadCompare1(void) 
    {
        return (CY_GET_REG16(servoPwm_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: servoPwm_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 servoPwm_ReadCompare2(void) 
    {
        return (CY_GET_REG16(servoPwm_COMPARE2_LSB_PTR));
    }

#endif /* (servoPwm_UseOneCompareMode) */


/*******************************************************************************
* Function Name: servoPwm_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 servoPwm_ReadPeriod(void) 
{
    #if(servoPwm_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(servoPwm_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(servoPwm_PERIOD_LSB_PTR));
    #endif /* (servoPwm_UsingFixedFunction) */
}

#if ( servoPwm_KillModeMinTime)


    /*******************************************************************************
    * Function Name: servoPwm_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void servoPwm_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(servoPwm_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: servoPwm_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 servoPwm_ReadKillTime(void) 
    {
        return (CY_GET_REG8(servoPwm_KILLMODEMINTIME_PTR));
    }

#endif /* ( servoPwm_KillModeMinTime) */

/* [] END OF FILE */
