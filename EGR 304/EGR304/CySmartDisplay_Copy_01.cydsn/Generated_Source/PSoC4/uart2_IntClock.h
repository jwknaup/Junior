/*******************************************************************************
* File Name: uart2_IntClock.h
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

#if !defined(CY_CLOCK_uart2_IntClock_H)
#define CY_CLOCK_uart2_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void uart2_IntClock_StartEx(uint32 alignClkDiv);
#define uart2_IntClock_Start() \
    uart2_IntClock_StartEx(uart2_IntClock__PA_DIV_ID)

#else

void uart2_IntClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void uart2_IntClock_Stop(void);

void uart2_IntClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 uart2_IntClock_GetDividerRegister(void);
uint8  uart2_IntClock_GetFractionalDividerRegister(void);

#define uart2_IntClock_Enable()                         uart2_IntClock_Start()
#define uart2_IntClock_Disable()                        uart2_IntClock_Stop()
#define uart2_IntClock_SetDividerRegister(clkDivider, reset)  \
    uart2_IntClock_SetFractionalDividerRegister((clkDivider), 0u)
#define uart2_IntClock_SetDivider(clkDivider)           uart2_IntClock_SetDividerRegister((clkDivider), 1u)
#define uart2_IntClock_SetDividerValue(clkDivider)      uart2_IntClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define uart2_IntClock_DIV_ID     uart2_IntClock__DIV_ID

#define uart2_IntClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define uart2_IntClock_CTRL_REG   (*(reg32 *)uart2_IntClock__CTRL_REGISTER)
#define uart2_IntClock_DIV_REG    (*(reg32 *)uart2_IntClock__DIV_REGISTER)

#define uart2_IntClock_CMD_DIV_SHIFT          (0u)
#define uart2_IntClock_CMD_PA_DIV_SHIFT       (8u)
#define uart2_IntClock_CMD_DISABLE_SHIFT      (30u)
#define uart2_IntClock_CMD_ENABLE_SHIFT       (31u)

#define uart2_IntClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << uart2_IntClock_CMD_DISABLE_SHIFT))
#define uart2_IntClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << uart2_IntClock_CMD_ENABLE_SHIFT))

#define uart2_IntClock_DIV_FRAC_MASK  (0x000000F8u)
#define uart2_IntClock_DIV_FRAC_SHIFT (3u)
#define uart2_IntClock_DIV_INT_MASK   (0xFFFFFF00u)
#define uart2_IntClock_DIV_INT_SHIFT  (8u)

#else 

#define uart2_IntClock_DIV_REG        (*(reg32 *)uart2_IntClock__REGISTER)
#define uart2_IntClock_ENABLE_REG     uart2_IntClock_DIV_REG
#define uart2_IntClock_DIV_FRAC_MASK  uart2_IntClock__FRAC_MASK
#define uart2_IntClock_DIV_FRAC_SHIFT (16u)
#define uart2_IntClock_DIV_INT_MASK   uart2_IntClock__DIVIDER_MASK
#define uart2_IntClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_uart2_IntClock_H) */

/* [] END OF FILE */
