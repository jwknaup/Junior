/*******************************************************************************
* File Name: servoPwm.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_servoPwm_H)
#define CY_PWM_servoPwm_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 servoPwm_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define servoPwm_Resolution                     (16u)
#define servoPwm_UsingFixedFunction             (0u)
#define servoPwm_DeadBandMode                   (0u)
#define servoPwm_KillModeMinTime                (0u)
#define servoPwm_KillMode                       (0u)
#define servoPwm_PWMMode                        (1u)
#define servoPwm_PWMModeIsCenterAligned         (0u)
#define servoPwm_DeadBandUsed                   (0u)
#define servoPwm_DeadBand2_4                    (0u)

#if !defined(servoPwm_PWMUDB_genblk8_stsreg__REMOVED)
    #define servoPwm_UseStatus                  (1u)
#else
    #define servoPwm_UseStatus                  (0u)
#endif /* !defined(servoPwm_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(servoPwm_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define servoPwm_UseControl                 (1u)
#else
    #define servoPwm_UseControl                 (0u)
#endif /* !defined(servoPwm_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define servoPwm_UseOneCompareMode              (0u)
#define servoPwm_MinimumKillTime                (1u)
#define servoPwm_EnableMode                     (0u)

#define servoPwm_CompareMode1SW                 (0u)
#define servoPwm_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define servoPwm__B_PWM__DISABLED 0
#define servoPwm__B_PWM__ASYNCHRONOUS 1
#define servoPwm__B_PWM__SINGLECYCLE 2
#define servoPwm__B_PWM__LATCHED 3
#define servoPwm__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define servoPwm__B_PWM__DBMDISABLED 0
#define servoPwm__B_PWM__DBM_2_4_CLOCKS 1
#define servoPwm__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define servoPwm__B_PWM__ONE_OUTPUT 0
#define servoPwm__B_PWM__TWO_OUTPUTS 1
#define servoPwm__B_PWM__DUAL_EDGE 2
#define servoPwm__B_PWM__CENTER_ALIGN 3
#define servoPwm__B_PWM__DITHER 5
#define servoPwm__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define servoPwm__B_PWM__LESS_THAN 1
#define servoPwm__B_PWM__LESS_THAN_OR_EQUAL 2
#define servoPwm__B_PWM__GREATER_THAN 3
#define servoPwm__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define servoPwm__B_PWM__EQUAL 0
#define servoPwm__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!servoPwm_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!servoPwm_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!servoPwm_PWMModeIsCenterAligned) */
        #if (servoPwm_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (servoPwm_UseStatus) */

        /* Backup for Deadband parameters */
        #if(servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_256_CLOCKS || \
            servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(servoPwm_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (servoPwm_KillModeMinTime) */

        /* Backup control register */
        #if(servoPwm_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (servoPwm_UseControl) */

    #endif /* (!servoPwm_UsingFixedFunction) */

}servoPwm_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    servoPwm_Start(void) ;
void    servoPwm_Stop(void) ;

#if (servoPwm_UseStatus || servoPwm_UsingFixedFunction)
    void  servoPwm_SetInterruptMode(uint8 interruptMode) ;
    uint8 servoPwm_ReadStatusRegister(void) ;
#endif /* (servoPwm_UseStatus || servoPwm_UsingFixedFunction) */

#define servoPwm_GetInterruptSource() servoPwm_ReadStatusRegister()

#if (servoPwm_UseControl)
    uint8 servoPwm_ReadControlRegister(void) ;
    void  servoPwm_WriteControlRegister(uint8 control)
          ;
#endif /* (servoPwm_UseControl) */

#if (servoPwm_UseOneCompareMode)
   #if (servoPwm_CompareMode1SW)
       void    servoPwm_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (servoPwm_CompareMode1SW) */
#else
    #if (servoPwm_CompareMode1SW)
        void    servoPwm_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (servoPwm_CompareMode1SW) */
    #if (servoPwm_CompareMode2SW)
        void    servoPwm_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (servoPwm_CompareMode2SW) */
#endif /* (servoPwm_UseOneCompareMode) */

#if (!servoPwm_UsingFixedFunction)
    uint16   servoPwm_ReadCounter(void) ;
    uint16 servoPwm_ReadCapture(void) ;

    #if (servoPwm_UseStatus)
            void servoPwm_ClearFIFO(void) ;
    #endif /* (servoPwm_UseStatus) */

    void    servoPwm_WriteCounter(uint16 counter)
            ;
#endif /* (!servoPwm_UsingFixedFunction) */

void    servoPwm_WritePeriod(uint16 period)
        ;
uint16 servoPwm_ReadPeriod(void) ;

#if (servoPwm_UseOneCompareMode)
    void    servoPwm_WriteCompare(uint16 compare)
            ;
    uint16 servoPwm_ReadCompare(void) ;
#else
    void    servoPwm_WriteCompare1(uint16 compare)
            ;
    uint16 servoPwm_ReadCompare1(void) ;
    void    servoPwm_WriteCompare2(uint16 compare)
            ;
    uint16 servoPwm_ReadCompare2(void) ;
#endif /* (servoPwm_UseOneCompareMode) */


#if (servoPwm_DeadBandUsed)
    void    servoPwm_WriteDeadTime(uint8 deadtime) ;
    uint8   servoPwm_ReadDeadTime(void) ;
#endif /* (servoPwm_DeadBandUsed) */

#if ( servoPwm_KillModeMinTime)
    void servoPwm_WriteKillTime(uint8 killtime) ;
    uint8 servoPwm_ReadKillTime(void) ;
#endif /* ( servoPwm_KillModeMinTime) */

void servoPwm_Init(void) ;
void servoPwm_Enable(void) ;
void servoPwm_Sleep(void) ;
void servoPwm_Wakeup(void) ;
void servoPwm_SaveConfig(void) ;
void servoPwm_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define servoPwm_INIT_PERIOD_VALUE          (60000u)
#define servoPwm_INIT_COMPARE_VALUE1        (0u)
#define servoPwm_INIT_COMPARE_VALUE2        (0u)
#define servoPwm_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    servoPwm_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    servoPwm_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    servoPwm_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    servoPwm_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define servoPwm_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  servoPwm_CTRL_CMPMODE2_SHIFT)
#define servoPwm_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  servoPwm_CTRL_CMPMODE1_SHIFT)
#define servoPwm_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (servoPwm_UsingFixedFunction)
   #define servoPwm_PERIOD_LSB              (*(reg16 *) servoPwm_PWMHW__PER0)
   #define servoPwm_PERIOD_LSB_PTR          ( (reg16 *) servoPwm_PWMHW__PER0)
   #define servoPwm_COMPARE1_LSB            (*(reg16 *) servoPwm_PWMHW__CNT_CMP0)
   #define servoPwm_COMPARE1_LSB_PTR        ( (reg16 *) servoPwm_PWMHW__CNT_CMP0)
   #define servoPwm_COMPARE2_LSB            (0x00u)
   #define servoPwm_COMPARE2_LSB_PTR        (0x00u)
   #define servoPwm_COUNTER_LSB             (*(reg16 *) servoPwm_PWMHW__CNT_CMP0)
   #define servoPwm_COUNTER_LSB_PTR         ( (reg16 *) servoPwm_PWMHW__CNT_CMP0)
   #define servoPwm_CAPTURE_LSB             (*(reg16 *) servoPwm_PWMHW__CAP0)
   #define servoPwm_CAPTURE_LSB_PTR         ( (reg16 *) servoPwm_PWMHW__CAP0)
   #define servoPwm_RT1                     (*(reg8 *)  servoPwm_PWMHW__RT1)
   #define servoPwm_RT1_PTR                 ( (reg8 *)  servoPwm_PWMHW__RT1)

#else
   #if (servoPwm_Resolution == 8u) /* 8bit - PWM */

       #if(servoPwm_PWMModeIsCenterAligned)
           #define servoPwm_PERIOD_LSB      (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define servoPwm_PERIOD_LSB_PTR  ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define servoPwm_PERIOD_LSB      (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define servoPwm_PERIOD_LSB_PTR  ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (servoPwm_PWMModeIsCenterAligned) */

       #define servoPwm_COMPARE1_LSB        (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define servoPwm_COMPARE1_LSB_PTR    ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define servoPwm_COMPARE2_LSB        (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define servoPwm_COMPARE2_LSB_PTR    ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define servoPwm_COUNTERCAP_LSB      (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define servoPwm_COUNTERCAP_LSB_PTR  ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define servoPwm_COUNTER_LSB         (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define servoPwm_COUNTER_LSB_PTR     ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define servoPwm_CAPTURE_LSB         (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define servoPwm_CAPTURE_LSB_PTR     ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(servoPwm_PWMModeIsCenterAligned)
               #define servoPwm_PERIOD_LSB      (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define servoPwm_PERIOD_LSB_PTR  ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define servoPwm_PERIOD_LSB      (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define servoPwm_PERIOD_LSB_PTR  ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (servoPwm_PWMModeIsCenterAligned) */

            #define servoPwm_COMPARE1_LSB       (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define servoPwm_COMPARE1_LSB_PTR   ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define servoPwm_COMPARE2_LSB       (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define servoPwm_COMPARE2_LSB_PTR   ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define servoPwm_COUNTERCAP_LSB     (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define servoPwm_COUNTERCAP_LSB_PTR ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define servoPwm_COUNTER_LSB        (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define servoPwm_COUNTER_LSB_PTR    ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define servoPwm_CAPTURE_LSB        (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define servoPwm_CAPTURE_LSB_PTR    ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(servoPwm_PWMModeIsCenterAligned)
               #define servoPwm_PERIOD_LSB      (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define servoPwm_PERIOD_LSB_PTR  ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define servoPwm_PERIOD_LSB      (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define servoPwm_PERIOD_LSB_PTR  ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (servoPwm_PWMModeIsCenterAligned) */

            #define servoPwm_COMPARE1_LSB       (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define servoPwm_COMPARE1_LSB_PTR   ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define servoPwm_COMPARE2_LSB       (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define servoPwm_COMPARE2_LSB_PTR   ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define servoPwm_COUNTERCAP_LSB     (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define servoPwm_COUNTERCAP_LSB_PTR ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define servoPwm_COUNTER_LSB        (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define servoPwm_COUNTER_LSB_PTR    ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define servoPwm_CAPTURE_LSB        (*(reg16 *) servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define servoPwm_CAPTURE_LSB_PTR    ((reg16 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define servoPwm_AUX_CONTROLDP1          (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define servoPwm_AUX_CONTROLDP1_PTR      ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (servoPwm_Resolution == 8) */

   #define servoPwm_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define servoPwm_AUX_CONTROLDP0          (*(reg8 *)  servoPwm_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define servoPwm_AUX_CONTROLDP0_PTR      ((reg8 *)   servoPwm_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (servoPwm_UsingFixedFunction) */

#if(servoPwm_KillModeMinTime )
    #define servoPwm_KILLMODEMINTIME        (*(reg8 *)  servoPwm_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define servoPwm_KILLMODEMINTIME_PTR    ((reg8 *)   servoPwm_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (servoPwm_KillModeMinTime ) */

#if(servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_256_CLOCKS)
    #define servoPwm_DEADBAND_COUNT         (*(reg8 *)  servoPwm_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define servoPwm_DEADBAND_COUNT_PTR     ((reg8 *)   servoPwm_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define servoPwm_DEADBAND_LSB_PTR       ((reg8 *)   servoPwm_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define servoPwm_DEADBAND_LSB           (*(reg8 *)  servoPwm_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (servoPwm_UsingFixedFunction)
        #define servoPwm_DEADBAND_COUNT         (*(reg8 *)  servoPwm_PWMHW__CFG0)
        #define servoPwm_DEADBAND_COUNT_PTR     ((reg8 *)   servoPwm_PWMHW__CFG0)
        #define servoPwm_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << servoPwm_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define servoPwm_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define servoPwm_DEADBAND_COUNT         (*(reg8 *)  servoPwm_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define servoPwm_DEADBAND_COUNT_PTR     ((reg8 *)   servoPwm_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define servoPwm_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << servoPwm_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define servoPwm_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (servoPwm_UsingFixedFunction) */
#endif /* (servoPwm_DeadBandMode == servoPwm__B_PWM__DBM_256_CLOCKS) */



#if (servoPwm_UsingFixedFunction)
    #define servoPwm_STATUS                 (*(reg8 *) servoPwm_PWMHW__SR0)
    #define servoPwm_STATUS_PTR             ((reg8 *) servoPwm_PWMHW__SR0)
    #define servoPwm_STATUS_MASK            (*(reg8 *) servoPwm_PWMHW__SR0)
    #define servoPwm_STATUS_MASK_PTR        ((reg8 *) servoPwm_PWMHW__SR0)
    #define servoPwm_CONTROL                (*(reg8 *) servoPwm_PWMHW__CFG0)
    #define servoPwm_CONTROL_PTR            ((reg8 *) servoPwm_PWMHW__CFG0)
    #define servoPwm_CONTROL2               (*(reg8 *) servoPwm_PWMHW__CFG1)
    #define servoPwm_CONTROL3               (*(reg8 *) servoPwm_PWMHW__CFG2)
    #define servoPwm_GLOBAL_ENABLE          (*(reg8 *) servoPwm_PWMHW__PM_ACT_CFG)
    #define servoPwm_GLOBAL_ENABLE_PTR      ( (reg8 *) servoPwm_PWMHW__PM_ACT_CFG)
    #define servoPwm_GLOBAL_STBY_ENABLE     (*(reg8 *) servoPwm_PWMHW__PM_STBY_CFG)
    #define servoPwm_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) servoPwm_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define servoPwm_BLOCK_EN_MASK          (servoPwm_PWMHW__PM_ACT_MSK)
    #define servoPwm_BLOCK_STBY_EN_MASK     (servoPwm_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define servoPwm_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define servoPwm_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define servoPwm_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define servoPwm_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define servoPwm_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define servoPwm_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define servoPwm_CTRL_ENABLE            (uint8)((uint8)0x01u << servoPwm_CTRL_ENABLE_SHIFT)
    #define servoPwm_CTRL_RESET             (uint8)((uint8)0x01u << servoPwm_CTRL_RESET_SHIFT)
    #define servoPwm_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << servoPwm_CTRL_CMPMODE2_SHIFT)
    #define servoPwm_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << servoPwm_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define servoPwm_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define servoPwm_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << servoPwm_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define servoPwm_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define servoPwm_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define servoPwm_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define servoPwm_STATUS_TC_INT_EN_MASK_SHIFT            (servoPwm_STATUS_TC_SHIFT - 4u)
    #define servoPwm_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define servoPwm_STATUS_CMP1_INT_EN_MASK_SHIFT          (servoPwm_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define servoPwm_STATUS_TC              (uint8)((uint8)0x01u << servoPwm_STATUS_TC_SHIFT)
    #define servoPwm_STATUS_CMP1            (uint8)((uint8)0x01u << servoPwm_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define servoPwm_STATUS_TC_INT_EN_MASK              (uint8)((uint8)servoPwm_STATUS_TC >> 4u)
    #define servoPwm_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)servoPwm_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define servoPwm_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define servoPwm_RT1_MASK              (uint8)((uint8)0x03u << servoPwm_RT1_SHIFT)
    #define servoPwm_SYNC                  (uint8)((uint8)0x03u << servoPwm_RT1_SHIFT)
    #define servoPwm_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define servoPwm_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << servoPwm_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define servoPwm_SYNCDSI_EN            (uint8)((uint8)0x0Fu << servoPwm_SYNCDSI_SHIFT)


#else
    #define servoPwm_STATUS                (*(reg8 *)   servoPwm_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define servoPwm_STATUS_PTR            ((reg8 *)    servoPwm_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define servoPwm_STATUS_MASK           (*(reg8 *)   servoPwm_PWMUDB_genblk8_stsreg__MASK_REG)
    #define servoPwm_STATUS_MASK_PTR       ((reg8 *)    servoPwm_PWMUDB_genblk8_stsreg__MASK_REG)
    #define servoPwm_STATUS_AUX_CTRL       (*(reg8 *)   servoPwm_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define servoPwm_CONTROL               (*(reg8 *)   servoPwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define servoPwm_CONTROL_PTR           ((reg8 *)    servoPwm_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define servoPwm_CTRL_ENABLE_SHIFT      (0x07u)
    #define servoPwm_CTRL_RESET_SHIFT       (0x06u)
    #define servoPwm_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define servoPwm_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define servoPwm_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define servoPwm_CTRL_ENABLE            (uint8)((uint8)0x01u << servoPwm_CTRL_ENABLE_SHIFT)
    #define servoPwm_CTRL_RESET             (uint8)((uint8)0x01u << servoPwm_CTRL_RESET_SHIFT)
    #define servoPwm_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << servoPwm_CTRL_CMPMODE2_SHIFT)
    #define servoPwm_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << servoPwm_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define servoPwm_STATUS_KILL_SHIFT          (0x05u)
    #define servoPwm_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define servoPwm_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define servoPwm_STATUS_TC_SHIFT            (0x02u)
    #define servoPwm_STATUS_CMP2_SHIFT          (0x01u)
    #define servoPwm_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define servoPwm_STATUS_KILL_INT_EN_MASK_SHIFT          (servoPwm_STATUS_KILL_SHIFT)
    #define servoPwm_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (servoPwm_STATUS_FIFONEMPTY_SHIFT)
    #define servoPwm_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (servoPwm_STATUS_FIFOFULL_SHIFT)
    #define servoPwm_STATUS_TC_INT_EN_MASK_SHIFT            (servoPwm_STATUS_TC_SHIFT)
    #define servoPwm_STATUS_CMP2_INT_EN_MASK_SHIFT          (servoPwm_STATUS_CMP2_SHIFT)
    #define servoPwm_STATUS_CMP1_INT_EN_MASK_SHIFT          (servoPwm_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define servoPwm_STATUS_KILL            (uint8)((uint8)0x00u << servoPwm_STATUS_KILL_SHIFT )
    #define servoPwm_STATUS_FIFOFULL        (uint8)((uint8)0x01u << servoPwm_STATUS_FIFOFULL_SHIFT)
    #define servoPwm_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << servoPwm_STATUS_FIFONEMPTY_SHIFT)
    #define servoPwm_STATUS_TC              (uint8)((uint8)0x01u << servoPwm_STATUS_TC_SHIFT)
    #define servoPwm_STATUS_CMP2            (uint8)((uint8)0x01u << servoPwm_STATUS_CMP2_SHIFT)
    #define servoPwm_STATUS_CMP1            (uint8)((uint8)0x01u << servoPwm_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define servoPwm_STATUS_KILL_INT_EN_MASK            (servoPwm_STATUS_KILL)
    #define servoPwm_STATUS_FIFOFULL_INT_EN_MASK        (servoPwm_STATUS_FIFOFULL)
    #define servoPwm_STATUS_FIFONEMPTY_INT_EN_MASK      (servoPwm_STATUS_FIFONEMPTY)
    #define servoPwm_STATUS_TC_INT_EN_MASK              (servoPwm_STATUS_TC)
    #define servoPwm_STATUS_CMP2_INT_EN_MASK            (servoPwm_STATUS_CMP2)
    #define servoPwm_STATUS_CMP1_INT_EN_MASK            (servoPwm_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define servoPwm_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define servoPwm_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define servoPwm_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define servoPwm_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define servoPwm_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* servoPwm_UsingFixedFunction */

#endif  /* CY_PWM_servoPwm_H */


/* [] END OF FILE */
