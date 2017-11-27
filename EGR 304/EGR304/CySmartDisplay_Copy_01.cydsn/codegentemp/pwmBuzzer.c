/*******************************************************************************
* File Name: pwmBuzzer.c
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

#include "pwmBuzzer.h"

/* Error message for removed <resource> through optimization */
#ifdef pwmBuzzer_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* pwmBuzzer_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 pwmBuzzer_initVar = 0u;


/*******************************************************************************
* Function Name: pwmBuzzer_Start
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
*  pwmBuzzer_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void pwmBuzzer_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(pwmBuzzer_initVar == 0u)
    {
        pwmBuzzer_Init();
        pwmBuzzer_initVar = 1u;
    }
    pwmBuzzer_Enable();

}


/*******************************************************************************
* Function Name: pwmBuzzer_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  pwmBuzzer_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwmBuzzer_Init(void) 
{
    #if (pwmBuzzer_UsingFixedFunction || pwmBuzzer_UseControl)
        uint8 ctrl;
    #endif /* (pwmBuzzer_UsingFixedFunction || pwmBuzzer_UseControl) */

    #if(!pwmBuzzer_UsingFixedFunction)
        #if(pwmBuzzer_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 pwmBuzzer_interruptState;
        #endif /* (pwmBuzzer_UseStatus) */
    #endif /* (!pwmBuzzer_UsingFixedFunction) */

    #if (pwmBuzzer_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        pwmBuzzer_CONTROL |= pwmBuzzer_CFG0_MODE;
        #if (pwmBuzzer_DeadBand2_4)
            pwmBuzzer_CONTROL |= pwmBuzzer_CFG0_DB;
        #endif /* (pwmBuzzer_DeadBand2_4) */

        ctrl = pwmBuzzer_CONTROL3 & ((uint8 )(~pwmBuzzer_CTRL_CMPMODE1_MASK));
        pwmBuzzer_CONTROL3 = ctrl | pwmBuzzer_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        pwmBuzzer_RT1 &= ((uint8)(~pwmBuzzer_RT1_MASK));
        pwmBuzzer_RT1 |= pwmBuzzer_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        pwmBuzzer_RT1 &= ((uint8)(~pwmBuzzer_SYNCDSI_MASK));
        pwmBuzzer_RT1 |= pwmBuzzer_SYNCDSI_EN;

    #elif (pwmBuzzer_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = pwmBuzzer_CONTROL & ((uint8)(~pwmBuzzer_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~pwmBuzzer_CTRL_CMPMODE1_MASK));
        pwmBuzzer_CONTROL = ctrl | pwmBuzzer_DEFAULT_COMPARE2_MODE |
                                   pwmBuzzer_DEFAULT_COMPARE1_MODE;
    #endif /* (pwmBuzzer_UsingFixedFunction) */

    #if (!pwmBuzzer_UsingFixedFunction)
        #if (pwmBuzzer_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            pwmBuzzer_AUX_CONTROLDP0 |= (pwmBuzzer_AUX_CTRL_FIFO0_CLR);
        #else /* (pwmBuzzer_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            pwmBuzzer_AUX_CONTROLDP0 |= (pwmBuzzer_AUX_CTRL_FIFO0_CLR);
            pwmBuzzer_AUX_CONTROLDP1 |= (pwmBuzzer_AUX_CTRL_FIFO0_CLR);
        #endif /* (pwmBuzzer_Resolution == 8) */

        pwmBuzzer_WriteCounter(pwmBuzzer_INIT_PERIOD_VALUE);
    #endif /* (!pwmBuzzer_UsingFixedFunction) */

    pwmBuzzer_WritePeriod(pwmBuzzer_INIT_PERIOD_VALUE);

        #if (pwmBuzzer_UseOneCompareMode)
            pwmBuzzer_WriteCompare(pwmBuzzer_INIT_COMPARE_VALUE1);
        #else
            pwmBuzzer_WriteCompare1(pwmBuzzer_INIT_COMPARE_VALUE1);
            pwmBuzzer_WriteCompare2(pwmBuzzer_INIT_COMPARE_VALUE2);
        #endif /* (pwmBuzzer_UseOneCompareMode) */

        #if (pwmBuzzer_KillModeMinTime)
            pwmBuzzer_WriteKillTime(pwmBuzzer_MinimumKillTime);
        #endif /* (pwmBuzzer_KillModeMinTime) */

        #if (pwmBuzzer_DeadBandUsed)
            pwmBuzzer_WriteDeadTime(pwmBuzzer_INIT_DEAD_TIME);
        #endif /* (pwmBuzzer_DeadBandUsed) */

    #if (pwmBuzzer_UseStatus || pwmBuzzer_UsingFixedFunction)
        pwmBuzzer_SetInterruptMode(pwmBuzzer_INIT_INTERRUPTS_MODE);
    #endif /* (pwmBuzzer_UseStatus || pwmBuzzer_UsingFixedFunction) */

    #if (pwmBuzzer_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        pwmBuzzer_GLOBAL_ENABLE |= pwmBuzzer_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        pwmBuzzer_CONTROL2 |= pwmBuzzer_CTRL2_IRQ_SEL;
    #else
        #if(pwmBuzzer_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            pwmBuzzer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            pwmBuzzer_STATUS_AUX_CTRL |= pwmBuzzer_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(pwmBuzzer_interruptState);

            /* Clear the FIFO to enable the pwmBuzzer_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            pwmBuzzer_ClearFIFO();
        #endif /* (pwmBuzzer_UseStatus) */
    #endif /* (pwmBuzzer_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: pwmBuzzer_Enable
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
void pwmBuzzer_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (pwmBuzzer_UsingFixedFunction)
        pwmBuzzer_GLOBAL_ENABLE |= pwmBuzzer_BLOCK_EN_MASK;
        pwmBuzzer_GLOBAL_STBY_ENABLE |= pwmBuzzer_BLOCK_STBY_EN_MASK;
    #endif /* (pwmBuzzer_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (pwmBuzzer_UseControl || pwmBuzzer_UsingFixedFunction)
        pwmBuzzer_CONTROL |= pwmBuzzer_CTRL_ENABLE;
    #endif /* (pwmBuzzer_UseControl || pwmBuzzer_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: pwmBuzzer_Stop
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
void pwmBuzzer_Stop(void) 
{
    #if (pwmBuzzer_UseControl || pwmBuzzer_UsingFixedFunction)
        pwmBuzzer_CONTROL &= ((uint8)(~pwmBuzzer_CTRL_ENABLE));
    #endif /* (pwmBuzzer_UseControl || pwmBuzzer_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (pwmBuzzer_UsingFixedFunction)
        pwmBuzzer_GLOBAL_ENABLE &= ((uint8)(~pwmBuzzer_BLOCK_EN_MASK));
        pwmBuzzer_GLOBAL_STBY_ENABLE &= ((uint8)(~pwmBuzzer_BLOCK_STBY_EN_MASK));
    #endif /* (pwmBuzzer_UsingFixedFunction) */
}

#if (pwmBuzzer_UseOneCompareMode)
    #if (pwmBuzzer_CompareMode1SW)


        /*******************************************************************************
        * Function Name: pwmBuzzer_SetCompareMode
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
        void pwmBuzzer_SetCompareMode(uint8 comparemode) 
        {
            #if(pwmBuzzer_UsingFixedFunction)

                #if(0 != pwmBuzzer_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << pwmBuzzer_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != pwmBuzzer_CTRL_CMPMODE1_SHIFT) */

                pwmBuzzer_CONTROL3 &= ((uint8)(~pwmBuzzer_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                pwmBuzzer_CONTROL3 |= comparemodemasked;

            #elif (pwmBuzzer_UseControl)

                #if(0 != pwmBuzzer_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << pwmBuzzer_CTRL_CMPMODE1_SHIFT)) &
                                                pwmBuzzer_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & pwmBuzzer_CTRL_CMPMODE1_MASK;
                #endif /* (0 != pwmBuzzer_CTRL_CMPMODE1_SHIFT) */

                #if(0 != pwmBuzzer_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << pwmBuzzer_CTRL_CMPMODE2_SHIFT)) &
                                               pwmBuzzer_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & pwmBuzzer_CTRL_CMPMODE2_MASK;
                #endif /* (0 != pwmBuzzer_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                pwmBuzzer_CONTROL &= ((uint8)(~(pwmBuzzer_CTRL_CMPMODE1_MASK |
                                            pwmBuzzer_CTRL_CMPMODE2_MASK)));
                pwmBuzzer_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (pwmBuzzer_UsingFixedFunction) */
        }
    #endif /* pwmBuzzer_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (pwmBuzzer_CompareMode1SW)


        /*******************************************************************************
        * Function Name: pwmBuzzer_SetCompareMode1
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
        void pwmBuzzer_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != pwmBuzzer_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << pwmBuzzer_CTRL_CMPMODE1_SHIFT)) &
                                           pwmBuzzer_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & pwmBuzzer_CTRL_CMPMODE1_MASK;
            #endif /* (0 != pwmBuzzer_CTRL_CMPMODE1_SHIFT) */

            #if (pwmBuzzer_UseControl)
                pwmBuzzer_CONTROL &= ((uint8)(~pwmBuzzer_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                pwmBuzzer_CONTROL |= comparemodemasked;
            #endif /* (pwmBuzzer_UseControl) */
        }
    #endif /* pwmBuzzer_CompareMode1SW */

#if (pwmBuzzer_CompareMode2SW)


    /*******************************************************************************
    * Function Name: pwmBuzzer_SetCompareMode2
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
    void pwmBuzzer_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != pwmBuzzer_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << pwmBuzzer_CTRL_CMPMODE2_SHIFT)) &
                                                 pwmBuzzer_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & pwmBuzzer_CTRL_CMPMODE2_MASK;
        #endif /* (0 != pwmBuzzer_CTRL_CMPMODE2_SHIFT) */

        #if (pwmBuzzer_UseControl)
            pwmBuzzer_CONTROL &= ((uint8)(~pwmBuzzer_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            pwmBuzzer_CONTROL |= comparemodemasked;
        #endif /* (pwmBuzzer_UseControl) */
    }
    #endif /*pwmBuzzer_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!pwmBuzzer_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: pwmBuzzer_WriteCounter
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
    void pwmBuzzer_WriteCounter(uint8 counter) \
                                       
    {
        CY_SET_REG8(pwmBuzzer_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadCounter
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
    uint8 pwmBuzzer_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(pwmBuzzer_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG8(pwmBuzzer_CAPTURE_LSB_PTR));
    }

    #if (pwmBuzzer_UseStatus)


        /*******************************************************************************
        * Function Name: pwmBuzzer_ClearFIFO
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
        void pwmBuzzer_ClearFIFO(void) 
        {
            while(0u != (pwmBuzzer_ReadStatusRegister() & pwmBuzzer_STATUS_FIFONEMPTY))
            {
                (void)pwmBuzzer_ReadCapture();
            }
        }

    #endif /* pwmBuzzer_UseStatus */

#endif /* !pwmBuzzer_UsingFixedFunction */


/*******************************************************************************
* Function Name: pwmBuzzer_WritePeriod
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
void pwmBuzzer_WritePeriod(uint8 period) 
{
    #if(pwmBuzzer_UsingFixedFunction)
        CY_SET_REG16(pwmBuzzer_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG8(pwmBuzzer_PERIOD_LSB_PTR, period);
    #endif /* (pwmBuzzer_UsingFixedFunction) */
}

#if (pwmBuzzer_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: pwmBuzzer_WriteCompare
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
    void pwmBuzzer_WriteCompare(uint8 compare) \
                                       
    {
        #if(pwmBuzzer_UsingFixedFunction)
            CY_SET_REG16(pwmBuzzer_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(pwmBuzzer_COMPARE1_LSB_PTR, compare);
        #endif /* (pwmBuzzer_UsingFixedFunction) */

        #if (pwmBuzzer_PWMMode == pwmBuzzer__B_PWM__DITHER)
            #if(pwmBuzzer_UsingFixedFunction)
                CY_SET_REG16(pwmBuzzer_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG8(pwmBuzzer_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (pwmBuzzer_UsingFixedFunction) */
        #endif /* (pwmBuzzer_PWMMode == pwmBuzzer__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: pwmBuzzer_WriteCompare1
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
    void pwmBuzzer_WriteCompare1(uint8 compare) \
                                        
    {
        #if(pwmBuzzer_UsingFixedFunction)
            CY_SET_REG16(pwmBuzzer_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(pwmBuzzer_COMPARE1_LSB_PTR, compare);
        #endif /* (pwmBuzzer_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: pwmBuzzer_WriteCompare2
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
    void pwmBuzzer_WriteCompare2(uint8 compare) \
                                        
    {
        #if(pwmBuzzer_UsingFixedFunction)
            CY_SET_REG16(pwmBuzzer_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG8(pwmBuzzer_COMPARE2_LSB_PTR, compare);
        #endif /* (pwmBuzzer_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (pwmBuzzer_DeadBandUsed)


    /*******************************************************************************
    * Function Name: pwmBuzzer_WriteDeadTime
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
    void pwmBuzzer_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!pwmBuzzer_DeadBand2_4)
            CY_SET_REG8(pwmBuzzer_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            pwmBuzzer_DEADBAND_COUNT &= ((uint8)(~pwmBuzzer_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(pwmBuzzer_DEADBAND_COUNT_SHIFT)
                pwmBuzzer_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << pwmBuzzer_DEADBAND_COUNT_SHIFT)) &
                                                    pwmBuzzer_DEADBAND_COUNT_MASK;
            #else
                pwmBuzzer_DEADBAND_COUNT |= deadtime & pwmBuzzer_DEADBAND_COUNT_MASK;
            #endif /* (pwmBuzzer_DEADBAND_COUNT_SHIFT) */

        #endif /* (!pwmBuzzer_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadDeadTime
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
    uint8 pwmBuzzer_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!pwmBuzzer_DeadBand2_4)
            return (CY_GET_REG8(pwmBuzzer_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(pwmBuzzer_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(pwmBuzzer_DEADBAND_COUNT & pwmBuzzer_DEADBAND_COUNT_MASK)) >>
                                                                           pwmBuzzer_DEADBAND_COUNT_SHIFT));
            #else
                return (pwmBuzzer_DEADBAND_COUNT & pwmBuzzer_DEADBAND_COUNT_MASK);
            #endif /* (pwmBuzzer_DEADBAND_COUNT_SHIFT) */
        #endif /* (!pwmBuzzer_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (pwmBuzzer_UseStatus || pwmBuzzer_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: pwmBuzzer_SetInterruptMode
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
    void pwmBuzzer_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(pwmBuzzer_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadStatusRegister
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
    uint8 pwmBuzzer_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(pwmBuzzer_STATUS_PTR));
    }

#endif /* (pwmBuzzer_UseStatus || pwmBuzzer_UsingFixedFunction) */


#if (pwmBuzzer_UseControl)


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadControlRegister
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
    uint8 pwmBuzzer_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(pwmBuzzer_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: pwmBuzzer_WriteControlRegister
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
    void pwmBuzzer_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(pwmBuzzer_CONTROL_PTR, control);
    }

#endif /* (pwmBuzzer_UseControl) */


#if (!pwmBuzzer_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadCapture
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
    uint8 pwmBuzzer_ReadCapture(void) 
    {
        return (CY_GET_REG8(pwmBuzzer_CAPTURE_LSB_PTR));
    }

#endif /* (!pwmBuzzer_UsingFixedFunction) */


#if (pwmBuzzer_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadCompare
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
    uint8 pwmBuzzer_ReadCompare(void) 
    {
        #if(pwmBuzzer_UsingFixedFunction)
            return ((uint8)CY_GET_REG16(pwmBuzzer_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG8(pwmBuzzer_COMPARE1_LSB_PTR));
        #endif /* (pwmBuzzer_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadCompare1
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
    uint8 pwmBuzzer_ReadCompare1(void) 
    {
        return (CY_GET_REG8(pwmBuzzer_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadCompare2
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
    uint8 pwmBuzzer_ReadCompare2(void) 
    {
        return (CY_GET_REG8(pwmBuzzer_COMPARE2_LSB_PTR));
    }

#endif /* (pwmBuzzer_UseOneCompareMode) */


/*******************************************************************************
* Function Name: pwmBuzzer_ReadPeriod
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
uint8 pwmBuzzer_ReadPeriod(void) 
{
    #if(pwmBuzzer_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(pwmBuzzer_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(pwmBuzzer_PERIOD_LSB_PTR));
    #endif /* (pwmBuzzer_UsingFixedFunction) */
}

#if ( pwmBuzzer_KillModeMinTime)


    /*******************************************************************************
    * Function Name: pwmBuzzer_WriteKillTime
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
    void pwmBuzzer_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(pwmBuzzer_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: pwmBuzzer_ReadKillTime
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
    uint8 pwmBuzzer_ReadKillTime(void) 
    {
        return (CY_GET_REG8(pwmBuzzer_KILLMODEMINTIME_PTR));
    }

#endif /* ( pwmBuzzer_KillModeMinTime) */

/* [] END OF FILE */
