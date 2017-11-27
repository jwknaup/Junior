/*******************************************************************************
* File Name: clockBuzzer.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_clockBuzzer_H)
#define CY_CLOCK_clockBuzzer_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void clockBuzzer_StartEx(uint32 alignClkDiv);
#define clockBuzzer_Start() \
    clockBuzzer_StartEx(clockBuzzer__PA_DIV_ID)

#else

void clockBuzzer_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void clockBuzzer_Stop(void);

void clockBuzzer_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 clockBuzzer_GetDividerRegister(void);
uint8  clockBuzzer_GetFractionalDividerRegister(void);

#define clockBuzzer_Enable()                         clockBuzzer_Start()
#define clockBuzzer_Disable()                        clockBuzzer_Stop()
#define clockBuzzer_SetDividerRegister(clkDivider, reset)  \
    clockBuzzer_SetFractionalDividerRegister((clkDivider), 0u)
#define clockBuzzer_SetDivider(clkDivider)           clockBuzzer_SetDividerRegister((clkDivider), 1u)
#define clockBuzzer_SetDividerValue(clkDivider)      clockBuzzer_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define clockBuzzer_DIV_ID     clockBuzzer__DIV_ID

#define clockBuzzer_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define clockBuzzer_CTRL_REG   (*(reg32 *)clockBuzzer__CTRL_REGISTER)
#define clockBuzzer_DIV_REG    (*(reg32 *)clockBuzzer__DIV_REGISTER)

#define clockBuzzer_CMD_DIV_SHIFT          (0u)
#define clockBuzzer_CMD_PA_DIV_SHIFT       (8u)
#define clockBuzzer_CMD_DISABLE_SHIFT      (30u)
#define clockBuzzer_CMD_ENABLE_SHIFT       (31u)

#define clockBuzzer_CMD_DISABLE_MASK       ((uint32)((uint32)1u << clockBuzzer_CMD_DISABLE_SHIFT))
#define clockBuzzer_CMD_ENABLE_MASK        ((uint32)((uint32)1u << clockBuzzer_CMD_ENABLE_SHIFT))

#define clockBuzzer_DIV_FRAC_MASK  (0x000000F8u)
#define clockBuzzer_DIV_FRAC_SHIFT (3u)
#define clockBuzzer_DIV_INT_MASK   (0xFFFFFF00u)
#define clockBuzzer_DIV_INT_SHIFT  (8u)

#else 

#define clockBuzzer_DIV_REG        (*(reg32 *)clockBuzzer__REGISTER)
#define clockBuzzer_ENABLE_REG     clockBuzzer_DIV_REG
#define clockBuzzer_DIV_FRAC_MASK  clockBuzzer__FRAC_MASK
#define clockBuzzer_DIV_FRAC_SHIFT (16u)
#define clockBuzzer_DIV_INT_MASK   clockBuzzer__DIVIDER_MASK
#define clockBuzzer_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_clockBuzzer_H) */

/* [] END OF FILE */
