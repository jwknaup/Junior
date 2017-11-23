/*******************************************************************************
* File Name: motorPwm.c
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

#include "motorPwm.h"

/* Error message for removed <resource> through optimization */
#ifdef motorPwm_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* motorPwm_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 motorPwm_initVar = 0u;


/*******************************************************************************
* Function Name: motorPwm_Start
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
*  motorPwm_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void motorPwm_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(motorPwm_initVar == 0u)
    {
        motorPwm_Init();
        motorPwm_initVar = 1u;
    }
    motorPwm_Enable();

}


/*******************************************************************************
* Function Name: motorPwm_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  motorPwm_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void motorPwm_Init(void) 
{
    #if (motorPwm_UsingFixedFunction || motorPwm_UseControl)
        uint8 ctrl;
    #endif /* (motorPwm_UsingFixedFunction || motorPwm_UseControl) */

    #if(!motorPwm_UsingFixedFunction)
        #if(motorPwm_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 motorPwm_interruptState;
        #endif /* (motorPwm_UseStatus) */
    #endif /* (!motorPwm_UsingFixedFunction) */

    #if (motorPwm_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        motorPwm_CONTROL |= motorPwm_CFG0_MODE;
        #if (motorPwm_DeadBand2_4)
            motorPwm_CONTROL |= motorPwm_CFG0_DB;
        #endif /* (motorPwm_DeadBand2_4) */

        ctrl = motorPwm_CONTROL3 & ((uint8 )(~motorPwm_CTRL_CMPMODE1_MASK));
        motorPwm_CONTROL3 = ctrl | motorPwm_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        motorPwm_RT1 &= ((uint8)(~motorPwm_RT1_MASK));
        motorPwm_RT1 |= motorPwm_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        motorPwm_RT1 &= ((uint8)(~motorPwm_SYNCDSI_MASK));
        motorPwm_RT1 |= motorPwm_SYNCDSI_EN;

    #elif (motorPwm_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = motorPwm_CONTROL & ((uint8)(~motorPwm_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~motorPwm_CTRL_CMPMODE1_MASK));
        motorPwm_CONTROL = ctrl | motorPwm_DEFAULT_COMPARE2_MODE |
                                   motorPwm_DEFAULT_COMPARE1_MODE;
    #endif /* (motorPwm_UsingFixedFunction) */

    #if (!motorPwm_UsingFixedFunction)
        #if (motorPwm_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            motorPwm_AUX_CONTROLDP0 |= (motorPwm_AUX_CTRL_FIFO0_CLR);
        #else /* (motorPwm_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            motorPwm_AUX_CONTROLDP0 |= (motorPwm_AUX_CTRL_FIFO0_CLR);
            motorPwm_AUX_CONTROLDP1 |= (motorPwm_AUX_CTRL_FIFO0_CLR);
        #endif /* (motorPwm_Resolution == 8) */

        motorPwm_WriteCounter(motorPwm_INIT_PERIOD_VALUE);
    #endif /* (!motorPwm_UsingFixedFunction) */

    motorPwm_WritePeriod(motorPwm_INIT_PERIOD_VALUE);

        #if (motorPwm_UseOneCompareMode)
            motorPwm_WriteCompare(motorPwm_INIT_COMPARE_VALUE1);
        #else
            motorPwm_WriteCompare1(motorPwm_INIT_COMPARE_VALUE1);
            motorPwm_WriteCompare2(motorPwm_INIT_COMPARE_VALUE2);
        #endif /* (motorPwm_UseOneCompareMode) */

        #if (motorPwm_KillModeMinTime)
            motorPwm_WriteKillTime(motorPwm_MinimumKillTime);
        #endif /* (motorPwm_KillModeMinTime) */

        #if (motorPwm_DeadBandUsed)
            motorPwm_WriteDeadTime(motorPwm_INIT_DEAD_TIME);
        #endif /* (motorPwm_DeadBandUsed) */

    #if (motorPwm_UseStatus || motorPwm_UsingFixedFunction)
        motorPwm_SetInterruptMode(motorPwm_INIT_INTERRUPTS_MODE);
    #endif /* (motorPwm_UseStatus || motorPwm_UsingFixedFunction) */

    #if (motorPwm_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        motorPwm_GLOBAL_ENABLE |= motorPwm_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        motorPwm_CONTROL2 |= motorPwm_CTRL2_IRQ_SEL;
    #else
        #if(motorPwm_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            motorPwm_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            motorPwm_STATUS_AUX_CTRL |= motorPwm_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(motorPwm_interruptState);

            /* Clear the FIFO to enable the motorPwm_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            motorPwm_ClearFIFO();
        #endif /* (motorPwm_UseStatus) */
    #endif /* (motorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: motorPwm_Enable
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
void motorPwm_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (motorPwm_UsingFixedFunction)
        motorPwm_GLOBAL_ENABLE |= motorPwm_BLOCK_EN_MASK;
        motorPwm_GLOBAL_STBY_ENABLE |= motorPwm_BLOCK_STBY_EN_MASK;
    #endif /* (motorPwm_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (motorPwm_UseControl || motorPwm_UsingFixedFunction)
        motorPwm_CONTROL |= motorPwm_CTRL_ENABLE;
    #endif /* (motorPwm_UseControl || motorPwm_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: motorPwm_Stop
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
void motorPwm_Stop(void) 
{
    #if (motorPwm_UseControl || motorPwm_UsingFixedFunction)
        motorPwm_CONTROL &= ((uint8)(~motorPwm_CTRL_ENABLE));
    #endif /* (motorPwm_UseControl || motorPwm_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (motorPwm_UsingFixedFunction)
        motorPwm_GLOBAL_ENABLE &= ((uint8)(~motorPwm_BLOCK_EN_MASK));
        motorPwm_GLOBAL_STBY_ENABLE &= ((uint8)(~motorPwm_BLOCK_STBY_EN_MASK));
    #endif /* (motorPwm_UsingFixedFunction) */
}

#if (motorPwm_UseOneCompareMode)
    #if (motorPwm_CompareMode1SW)


        /*******************************************************************************
        * Function Name: motorPwm_SetCompareMode
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
        void motorPwm_SetCompareMode(uint8 comparemode) 
        {
            #if(motorPwm_UsingFixedFunction)

                #if(0 != motorPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << motorPwm_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != motorPwm_CTRL_CMPMODE1_SHIFT) */

                motorPwm_CONTROL3 &= ((uint8)(~motorPwm_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                motorPwm_CONTROL3 |= comparemodemasked;

            #elif (motorPwm_UseControl)

                #if(0 != motorPwm_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << motorPwm_CTRL_CMPMODE1_SHIFT)) &
                                                motorPwm_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & motorPwm_CTRL_CMPMODE1_MASK;
                #endif /* (0 != motorPwm_CTRL_CMPMODE1_SHIFT) */

                #if(0 != motorPwm_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << motorPwm_CTRL_CMPMODE2_SHIFT)) &
                                               motorPwm_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & motorPwm_CTRL_CMPMODE2_MASK;
                #endif /* (0 != motorPwm_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                motorPwm_CONTROL &= ((uint8)(~(motorPwm_CTRL_CMPMODE1_MASK |
                                            motorPwm_CTRL_CMPMODE2_MASK)));
                motorPwm_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (motorPwm_UsingFixedFunction) */
        }
    #endif /* motorPwm_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (motorPwm_CompareMode1SW)


        /*******************************************************************************
        * Function Name: motorPwm_SetCompareMode1
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
        void motorPwm_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != motorPwm_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << motorPwm_CTRL_CMPMODE1_SHIFT)) &
                                           motorPwm_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & motorPwm_CTRL_CMPMODE1_MASK;
            #endif /* (0 != motorPwm_CTRL_CMPMODE1_SHIFT) */

            #if (motorPwm_UseControl)
                motorPwm_CONTROL &= ((uint8)(~motorPwm_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                motorPwm_CONTROL |= comparemodemasked;
            #endif /* (motorPwm_UseControl) */
        }
    #endif /* motorPwm_CompareMode1SW */

#if (motorPwm_CompareMode2SW)


    /*******************************************************************************
    * Function Name: motorPwm_SetCompareMode2
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
    void motorPwm_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != motorPwm_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << motorPwm_CTRL_CMPMODE2_SHIFT)) &
                                                 motorPwm_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & motorPwm_CTRL_CMPMODE2_MASK;
        #endif /* (0 != motorPwm_CTRL_CMPMODE2_SHIFT) */

        #if (motorPwm_UseControl)
            motorPwm_CONTROL &= ((uint8)(~motorPwm_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            motorPwm_CONTROL |= comparemodemasked;
        #endif /* (motorPwm_UseControl) */
    }
    #endif /*motorPwm_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!motorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: motorPwm_WriteCounter
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
    void motorPwm_WriteCounter(uint8 counter) \
                                       
    {
        CY_SET_REG8(motorPwm_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: motorPwm_ReadCounter
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
    uint8 motorPwm_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(motorPwm_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG8(motorPwm_CAPTURE_LSB_PTR));
    }

    #if (motorPwm_UseStatus)


        /*******************************************************************************
        * Function Name: motorPwm_ClearFIFO
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
        void motorPwm_ClearFIFO(void) 
        {
            while(0u != (motorPwm_ReadStatusRegister() & motorPwm_STATUS_FIFONEMPTY))
            {
                (void)motorPwm_ReadCapture();
            }
        }

    #endif /* motorPwm_UseStatus */

#endif /* !motorPwm_UsingFixedFunction */


/*******************************************************************************
* Function Name: motorPwm_WritePeriod
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
void motorPwm_WritePeriod(uint8 period) 
{
    #if(motorPwm_UsingFixedFunction)
        CY_SET_REG16(motorPwm_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG8(motorPwm_PERIOD_LSB_PTR, period);
    #endif /* (motorPwm_UsingFixedFunction) */
}

#if (motorPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: motorPwm_WriteCompare
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
    void motorPwm_WriteCompare(uint8 compare) \
                                       
    {
        #if(motorPwm_UsingFixedFunction)
            CY_SET_REG16(motorPwm_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(motorPwm_COMPARE1_LSB_PTR, compare);
        #endif /* (motorPwm_UsingFixedFunction) */

        #if (motorPwm_PWMMode == motorPwm__B_PWM__DITHER)
            #if(motorPwm_UsingFixedFunction)
                CY_SET_REG16(motorPwm_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG8(motorPwm_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (motorPwm_UsingFixedFunction) */
        #endif /* (motorPwm_PWMMode == motorPwm__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: motorPwm_WriteCompare1
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
    void motorPwm_WriteCompare1(uint8 compare) \
                                        
    {
        #if(motorPwm_UsingFixedFunction)
            CY_SET_REG16(motorPwm_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(motorPwm_COMPARE1_LSB_PTR, compare);
        #endif /* (motorPwm_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: motorPwm_WriteCompare2
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
    void motorPwm_WriteCompare2(uint8 compare) \
                                        
    {
        #if(motorPwm_UsingFixedFunction)
            CY_SET_REG16(motorPwm_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG8(motorPwm_COMPARE2_LSB_PTR, compare);
        #endif /* (motorPwm_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (motorPwm_DeadBandUsed)


    /*******************************************************************************
    * Function Name: motorPwm_WriteDeadTime
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
    void motorPwm_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!motorPwm_DeadBand2_4)
            CY_SET_REG8(motorPwm_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            motorPwm_DEADBAND_COUNT &= ((uint8)(~motorPwm_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(motorPwm_DEADBAND_COUNT_SHIFT)
                motorPwm_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << motorPwm_DEADBAND_COUNT_SHIFT)) &
                                                    motorPwm_DEADBAND_COUNT_MASK;
            #else
                motorPwm_DEADBAND_COUNT |= deadtime & motorPwm_DEADBAND_COUNT_MASK;
            #endif /* (motorPwm_DEADBAND_COUNT_SHIFT) */

        #endif /* (!motorPwm_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: motorPwm_ReadDeadTime
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
    uint8 motorPwm_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!motorPwm_DeadBand2_4)
            return (CY_GET_REG8(motorPwm_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(motorPwm_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(motorPwm_DEADBAND_COUNT & motorPwm_DEADBAND_COUNT_MASK)) >>
                                                                           motorPwm_DEADBAND_COUNT_SHIFT));
            #else
                return (motorPwm_DEADBAND_COUNT & motorPwm_DEADBAND_COUNT_MASK);
            #endif /* (motorPwm_DEADBAND_COUNT_SHIFT) */
        #endif /* (!motorPwm_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (motorPwm_UseStatus || motorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: motorPwm_SetInterruptMode
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
    void motorPwm_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(motorPwm_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: motorPwm_ReadStatusRegister
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
    uint8 motorPwm_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(motorPwm_STATUS_PTR));
    }

#endif /* (motorPwm_UseStatus || motorPwm_UsingFixedFunction) */


#if (motorPwm_UseControl)


    /*******************************************************************************
    * Function Name: motorPwm_ReadControlRegister
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
    uint8 motorPwm_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(motorPwm_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: motorPwm_WriteControlRegister
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
    void motorPwm_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(motorPwm_CONTROL_PTR, control);
    }

#endif /* (motorPwm_UseControl) */


#if (!motorPwm_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: motorPwm_ReadCapture
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
    uint8 motorPwm_ReadCapture(void) 
    {
        return (CY_GET_REG8(motorPwm_CAPTURE_LSB_PTR));
    }

#endif /* (!motorPwm_UsingFixedFunction) */


#if (motorPwm_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: motorPwm_ReadCompare
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
    uint8 motorPwm_ReadCompare(void) 
    {
        #if(motorPwm_UsingFixedFunction)
            return ((uint8)CY_GET_REG16(motorPwm_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG8(motorPwm_COMPARE1_LSB_PTR));
        #endif /* (motorPwm_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: motorPwm_ReadCompare1
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
    uint8 motorPwm_ReadCompare1(void) 
    {
        return (CY_GET_REG8(motorPwm_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: motorPwm_ReadCompare2
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
    uint8 motorPwm_ReadCompare2(void) 
    {
        return (CY_GET_REG8(motorPwm_COMPARE2_LSB_PTR));
    }

#endif /* (motorPwm_UseOneCompareMode) */


/*******************************************************************************
* Function Name: motorPwm_ReadPeriod
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
uint8 motorPwm_ReadPeriod(void) 
{
    #if(motorPwm_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(motorPwm_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(motorPwm_PERIOD_LSB_PTR));
    #endif /* (motorPwm_UsingFixedFunction) */
}

#if ( motorPwm_KillModeMinTime)


    /*******************************************************************************
    * Function Name: motorPwm_WriteKillTime
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
    void motorPwm_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(motorPwm_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: motorPwm_ReadKillTime
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
    uint8 motorPwm_ReadKillTime(void) 
    {
        return (CY_GET_REG8(motorPwm_KILLMODEMINTIME_PTR));
    }

#endif /* ( motorPwm_KillModeMinTime) */

/* [] END OF FILE */
