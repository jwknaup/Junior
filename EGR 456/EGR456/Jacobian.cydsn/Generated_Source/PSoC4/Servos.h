/*******************************************************************************
* File Name: Servos.h
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

#if !defined(CY_PWM_Servos_H)
#define CY_PWM_Servos_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Servos_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Servos_Resolution                     (16u)
#define Servos_UsingFixedFunction             (0u)
#define Servos_DeadBandMode                   (0u)
#define Servos_KillModeMinTime                (0u)
#define Servos_KillMode                       (0u)
#define Servos_PWMMode                        (1u)
#define Servos_PWMModeIsCenterAligned         (0u)
#define Servos_DeadBandUsed                   (0u)
#define Servos_DeadBand2_4                    (0u)

#if !defined(Servos_PWMUDB_genblk8_stsreg__REMOVED)
    #define Servos_UseStatus                  (1u)
#else
    #define Servos_UseStatus                  (0u)
#endif /* !defined(Servos_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(Servos_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define Servos_UseControl                 (1u)
#else
    #define Servos_UseControl                 (0u)
#endif /* !defined(Servos_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define Servos_UseOneCompareMode              (0u)
#define Servos_MinimumKillTime                (1u)
#define Servos_EnableMode                     (0u)

#define Servos_CompareMode1SW                 (0u)
#define Servos_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Servos__B_PWM__DISABLED 0
#define Servos__B_PWM__ASYNCHRONOUS 1
#define Servos__B_PWM__SINGLECYCLE 2
#define Servos__B_PWM__LATCHED 3
#define Servos__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Servos__B_PWM__DBMDISABLED 0
#define Servos__B_PWM__DBM_2_4_CLOCKS 1
#define Servos__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Servos__B_PWM__ONE_OUTPUT 0
#define Servos__B_PWM__TWO_OUTPUTS 1
#define Servos__B_PWM__DUAL_EDGE 2
#define Servos__B_PWM__CENTER_ALIGN 3
#define Servos__B_PWM__DITHER 5
#define Servos__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Servos__B_PWM__LESS_THAN 1
#define Servos__B_PWM__LESS_THAN_OR_EQUAL 2
#define Servos__B_PWM__GREATER_THAN 3
#define Servos__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Servos__B_PWM__EQUAL 0
#define Servos__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!Servos_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!Servos_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!Servos_PWMModeIsCenterAligned) */
        #if (Servos_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (Servos_UseStatus) */

        /* Backup for Deadband parameters */
        #if(Servos_DeadBandMode == Servos__B_PWM__DBM_256_CLOCKS || \
            Servos_DeadBandMode == Servos__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(Servos_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (Servos_KillModeMinTime) */

        /* Backup control register */
        #if(Servos_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Servos_UseControl) */

    #endif /* (!Servos_UsingFixedFunction) */

}Servos_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    Servos_Start(void) ;
void    Servos_Stop(void) ;

#if (Servos_UseStatus || Servos_UsingFixedFunction)
    void  Servos_SetInterruptMode(uint8 interruptMode) ;
    uint8 Servos_ReadStatusRegister(void) ;
#endif /* (Servos_UseStatus || Servos_UsingFixedFunction) */

#define Servos_GetInterruptSource() Servos_ReadStatusRegister()

#if (Servos_UseControl)
    uint8 Servos_ReadControlRegister(void) ;
    void  Servos_WriteControlRegister(uint8 control)
          ;
#endif /* (Servos_UseControl) */

#if (Servos_UseOneCompareMode)
   #if (Servos_CompareMode1SW)
       void    Servos_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (Servos_CompareMode1SW) */
#else
    #if (Servos_CompareMode1SW)
        void    Servos_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (Servos_CompareMode1SW) */
    #if (Servos_CompareMode2SW)
        void    Servos_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (Servos_CompareMode2SW) */
#endif /* (Servos_UseOneCompareMode) */

#if (!Servos_UsingFixedFunction)
    uint16   Servos_ReadCounter(void) ;
    uint16 Servos_ReadCapture(void) ;

    #if (Servos_UseStatus)
            void Servos_ClearFIFO(void) ;
    #endif /* (Servos_UseStatus) */

    void    Servos_WriteCounter(uint16 counter)
            ;
#endif /* (!Servos_UsingFixedFunction) */

void    Servos_WritePeriod(uint16 period)
        ;
uint16 Servos_ReadPeriod(void) ;

#if (Servos_UseOneCompareMode)
    void    Servos_WriteCompare(uint16 compare)
            ;
    uint16 Servos_ReadCompare(void) ;
#else
    void    Servos_WriteCompare1(uint16 compare)
            ;
    uint16 Servos_ReadCompare1(void) ;
    void    Servos_WriteCompare2(uint16 compare)
            ;
    uint16 Servos_ReadCompare2(void) ;
#endif /* (Servos_UseOneCompareMode) */


#if (Servos_DeadBandUsed)
    void    Servos_WriteDeadTime(uint8 deadtime) ;
    uint8   Servos_ReadDeadTime(void) ;
#endif /* (Servos_DeadBandUsed) */

#if ( Servos_KillModeMinTime)
    void Servos_WriteKillTime(uint8 killtime) ;
    uint8 Servos_ReadKillTime(void) ;
#endif /* ( Servos_KillModeMinTime) */

void Servos_Init(void) ;
void Servos_Enable(void) ;
void Servos_Sleep(void) ;
void Servos_Wakeup(void) ;
void Servos_SaveConfig(void) ;
void Servos_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Servos_INIT_PERIOD_VALUE          (60000u)
#define Servos_INIT_COMPARE_VALUE1        (0u)
#define Servos_INIT_COMPARE_VALUE2        (0u)
#define Servos_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    Servos_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Servos_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Servos_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Servos_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Servos_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  Servos_CTRL_CMPMODE2_SHIFT)
#define Servos_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  Servos_CTRL_CMPMODE1_SHIFT)
#define Servos_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (Servos_UsingFixedFunction)
   #define Servos_PERIOD_LSB              (*(reg16 *) Servos_PWMHW__PER0)
   #define Servos_PERIOD_LSB_PTR          ( (reg16 *) Servos_PWMHW__PER0)
   #define Servos_COMPARE1_LSB            (*(reg16 *) Servos_PWMHW__CNT_CMP0)
   #define Servos_COMPARE1_LSB_PTR        ( (reg16 *) Servos_PWMHW__CNT_CMP0)
   #define Servos_COMPARE2_LSB            (0x00u)
   #define Servos_COMPARE2_LSB_PTR        (0x00u)
   #define Servos_COUNTER_LSB             (*(reg16 *) Servos_PWMHW__CNT_CMP0)
   #define Servos_COUNTER_LSB_PTR         ( (reg16 *) Servos_PWMHW__CNT_CMP0)
   #define Servos_CAPTURE_LSB             (*(reg16 *) Servos_PWMHW__CAP0)
   #define Servos_CAPTURE_LSB_PTR         ( (reg16 *) Servos_PWMHW__CAP0)
   #define Servos_RT1                     (*(reg8 *)  Servos_PWMHW__RT1)
   #define Servos_RT1_PTR                 ( (reg8 *)  Servos_PWMHW__RT1)

#else
   #if (Servos_Resolution == 8u) /* 8bit - PWM */

       #if(Servos_PWMModeIsCenterAligned)
           #define Servos_PERIOD_LSB      (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define Servos_PERIOD_LSB_PTR  ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define Servos_PERIOD_LSB      (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define Servos_PERIOD_LSB_PTR  ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (Servos_PWMModeIsCenterAligned) */

       #define Servos_COMPARE1_LSB        (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define Servos_COMPARE1_LSB_PTR    ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define Servos_COMPARE2_LSB        (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define Servos_COMPARE2_LSB_PTR    ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define Servos_COUNTERCAP_LSB      (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define Servos_COUNTERCAP_LSB_PTR  ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define Servos_COUNTER_LSB         (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define Servos_COUNTER_LSB_PTR     ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define Servos_CAPTURE_LSB         (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define Servos_CAPTURE_LSB_PTR     ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(Servos_PWMModeIsCenterAligned)
               #define Servos_PERIOD_LSB      (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define Servos_PERIOD_LSB_PTR  ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define Servos_PERIOD_LSB      (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define Servos_PERIOD_LSB_PTR  ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (Servos_PWMModeIsCenterAligned) */

            #define Servos_COMPARE1_LSB       (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define Servos_COMPARE1_LSB_PTR   ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define Servos_COMPARE2_LSB       (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define Servos_COMPARE2_LSB_PTR   ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define Servos_COUNTERCAP_LSB     (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define Servos_COUNTERCAP_LSB_PTR ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define Servos_COUNTER_LSB        (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define Servos_COUNTER_LSB_PTR    ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define Servos_CAPTURE_LSB        (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define Servos_CAPTURE_LSB_PTR    ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(Servos_PWMModeIsCenterAligned)
               #define Servos_PERIOD_LSB      (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define Servos_PERIOD_LSB_PTR  ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define Servos_PERIOD_LSB      (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define Servos_PERIOD_LSB_PTR  ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (Servos_PWMModeIsCenterAligned) */

            #define Servos_COMPARE1_LSB       (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define Servos_COMPARE1_LSB_PTR   ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define Servos_COMPARE2_LSB       (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define Servos_COMPARE2_LSB_PTR   ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define Servos_COUNTERCAP_LSB     (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define Servos_COUNTERCAP_LSB_PTR ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define Servos_COUNTER_LSB        (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define Servos_COUNTER_LSB_PTR    ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define Servos_CAPTURE_LSB        (*(reg16 *) Servos_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define Servos_CAPTURE_LSB_PTR    ((reg16 *)  Servos_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define Servos_AUX_CONTROLDP1          (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define Servos_AUX_CONTROLDP1_PTR      ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Servos_Resolution == 8) */

   #define Servos_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define Servos_AUX_CONTROLDP0          (*(reg8 *)  Servos_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define Servos_AUX_CONTROLDP0_PTR      ((reg8 *)   Servos_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Servos_UsingFixedFunction) */

#if(Servos_KillModeMinTime )
    #define Servos_KILLMODEMINTIME        (*(reg8 *)  Servos_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Servos_KILLMODEMINTIME_PTR    ((reg8 *)   Servos_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Servos_KillModeMinTime ) */

#if(Servos_DeadBandMode == Servos__B_PWM__DBM_256_CLOCKS)
    #define Servos_DEADBAND_COUNT         (*(reg8 *)  Servos_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Servos_DEADBAND_COUNT_PTR     ((reg8 *)   Servos_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Servos_DEADBAND_LSB_PTR       ((reg8 *)   Servos_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Servos_DEADBAND_LSB           (*(reg8 *)  Servos_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Servos_DeadBandMode == Servos__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Servos_UsingFixedFunction)
        #define Servos_DEADBAND_COUNT         (*(reg8 *)  Servos_PWMHW__CFG0)
        #define Servos_DEADBAND_COUNT_PTR     ((reg8 *)   Servos_PWMHW__CFG0)
        #define Servos_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Servos_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Servos_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Servos_DEADBAND_COUNT         (*(reg8 *)  Servos_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Servos_DEADBAND_COUNT_PTR     ((reg8 *)   Servos_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Servos_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Servos_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define Servos_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (Servos_UsingFixedFunction) */
#endif /* (Servos_DeadBandMode == Servos__B_PWM__DBM_256_CLOCKS) */



#if (Servos_UsingFixedFunction)
    #define Servos_STATUS                 (*(reg8 *) Servos_PWMHW__SR0)
    #define Servos_STATUS_PTR             ((reg8 *) Servos_PWMHW__SR0)
    #define Servos_STATUS_MASK            (*(reg8 *) Servos_PWMHW__SR0)
    #define Servos_STATUS_MASK_PTR        ((reg8 *) Servos_PWMHW__SR0)
    #define Servos_CONTROL                (*(reg8 *) Servos_PWMHW__CFG0)
    #define Servos_CONTROL_PTR            ((reg8 *) Servos_PWMHW__CFG0)
    #define Servos_CONTROL2               (*(reg8 *) Servos_PWMHW__CFG1)
    #define Servos_CONTROL3               (*(reg8 *) Servos_PWMHW__CFG2)
    #define Servos_GLOBAL_ENABLE          (*(reg8 *) Servos_PWMHW__PM_ACT_CFG)
    #define Servos_GLOBAL_ENABLE_PTR      ( (reg8 *) Servos_PWMHW__PM_ACT_CFG)
    #define Servos_GLOBAL_STBY_ENABLE     (*(reg8 *) Servos_PWMHW__PM_STBY_CFG)
    #define Servos_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) Servos_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Servos_BLOCK_EN_MASK          (Servos_PWMHW__PM_ACT_MSK)
    #define Servos_BLOCK_STBY_EN_MASK     (Servos_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define Servos_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define Servos_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define Servos_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define Servos_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define Servos_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define Servos_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define Servos_CTRL_ENABLE            (uint8)((uint8)0x01u << Servos_CTRL_ENABLE_SHIFT)
    #define Servos_CTRL_RESET             (uint8)((uint8)0x01u << Servos_CTRL_RESET_SHIFT)
    #define Servos_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Servos_CTRL_CMPMODE2_SHIFT)
    #define Servos_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Servos_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Servos_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define Servos_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Servos_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define Servos_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define Servos_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define Servos_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define Servos_STATUS_TC_INT_EN_MASK_SHIFT            (Servos_STATUS_TC_SHIFT - 4u)
    #define Servos_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define Servos_STATUS_CMP1_INT_EN_MASK_SHIFT          (Servos_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define Servos_STATUS_TC              (uint8)((uint8)0x01u << Servos_STATUS_TC_SHIFT)
    #define Servos_STATUS_CMP1            (uint8)((uint8)0x01u << Servos_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define Servos_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Servos_STATUS_TC >> 4u)
    #define Servos_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Servos_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define Servos_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define Servos_RT1_MASK              (uint8)((uint8)0x03u << Servos_RT1_SHIFT)
    #define Servos_SYNC                  (uint8)((uint8)0x03u << Servos_RT1_SHIFT)
    #define Servos_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define Servos_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Servos_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define Servos_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Servos_SYNCDSI_SHIFT)


#else
    #define Servos_STATUS                (*(reg8 *)   Servos_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Servos_STATUS_PTR            ((reg8 *)    Servos_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Servos_STATUS_MASK           (*(reg8 *)   Servos_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Servos_STATUS_MASK_PTR       ((reg8 *)    Servos_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Servos_STATUS_AUX_CTRL       (*(reg8 *)   Servos_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define Servos_CONTROL               (*(reg8 *)   Servos_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define Servos_CONTROL_PTR           ((reg8 *)    Servos_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define Servos_CTRL_ENABLE_SHIFT      (0x07u)
    #define Servos_CTRL_RESET_SHIFT       (0x06u)
    #define Servos_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define Servos_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define Servos_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define Servos_CTRL_ENABLE            (uint8)((uint8)0x01u << Servos_CTRL_ENABLE_SHIFT)
    #define Servos_CTRL_RESET             (uint8)((uint8)0x01u << Servos_CTRL_RESET_SHIFT)
    #define Servos_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Servos_CTRL_CMPMODE2_SHIFT)
    #define Servos_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Servos_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define Servos_STATUS_KILL_SHIFT          (0x05u)
    #define Servos_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define Servos_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define Servos_STATUS_TC_SHIFT            (0x02u)
    #define Servos_STATUS_CMP2_SHIFT          (0x01u)
    #define Servos_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Servos_STATUS_KILL_INT_EN_MASK_SHIFT          (Servos_STATUS_KILL_SHIFT)
    #define Servos_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (Servos_STATUS_FIFONEMPTY_SHIFT)
    #define Servos_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (Servos_STATUS_FIFOFULL_SHIFT)
    #define Servos_STATUS_TC_INT_EN_MASK_SHIFT            (Servos_STATUS_TC_SHIFT)
    #define Servos_STATUS_CMP2_INT_EN_MASK_SHIFT          (Servos_STATUS_CMP2_SHIFT)
    #define Servos_STATUS_CMP1_INT_EN_MASK_SHIFT          (Servos_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define Servos_STATUS_KILL            (uint8)((uint8)0x00u << Servos_STATUS_KILL_SHIFT )
    #define Servos_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Servos_STATUS_FIFOFULL_SHIFT)
    #define Servos_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Servos_STATUS_FIFONEMPTY_SHIFT)
    #define Servos_STATUS_TC              (uint8)((uint8)0x01u << Servos_STATUS_TC_SHIFT)
    #define Servos_STATUS_CMP2            (uint8)((uint8)0x01u << Servos_STATUS_CMP2_SHIFT)
    #define Servos_STATUS_CMP1            (uint8)((uint8)0x01u << Servos_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Servos_STATUS_KILL_INT_EN_MASK            (Servos_STATUS_KILL)
    #define Servos_STATUS_FIFOFULL_INT_EN_MASK        (Servos_STATUS_FIFOFULL)
    #define Servos_STATUS_FIFONEMPTY_INT_EN_MASK      (Servos_STATUS_FIFONEMPTY)
    #define Servos_STATUS_TC_INT_EN_MASK              (Servos_STATUS_TC)
    #define Servos_STATUS_CMP2_INT_EN_MASK            (Servos_STATUS_CMP2)
    #define Servos_STATUS_CMP1_INT_EN_MASK            (Servos_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define Servos_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define Servos_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define Servos_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define Servos_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define Servos_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* Servos_UsingFixedFunction */

#endif  /* CY_PWM_Servos_H */


/* [] END OF FILE */
