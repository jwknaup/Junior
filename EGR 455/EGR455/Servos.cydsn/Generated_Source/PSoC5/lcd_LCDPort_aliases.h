/*******************************************************************************
* File Name: lcd_LCDPort.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_lcd_LCDPort_ALIASES_H) /* Pins lcd_LCDPort_ALIASES_H */
#define CY_PINS_lcd_LCDPort_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define lcd_LCDPort_0			(lcd_LCDPort__0__PC)
#define lcd_LCDPort_0_INTR	((uint16)((uint16)0x0001u << lcd_LCDPort__0__SHIFT))

#define lcd_LCDPort_1			(lcd_LCDPort__1__PC)
#define lcd_LCDPort_1_INTR	((uint16)((uint16)0x0001u << lcd_LCDPort__1__SHIFT))

#define lcd_LCDPort_2			(lcd_LCDPort__2__PC)
#define lcd_LCDPort_2_INTR	((uint16)((uint16)0x0001u << lcd_LCDPort__2__SHIFT))

#define lcd_LCDPort_3			(lcd_LCDPort__3__PC)
#define lcd_LCDPort_3_INTR	((uint16)((uint16)0x0001u << lcd_LCDPort__3__SHIFT))

#define lcd_LCDPort_4			(lcd_LCDPort__4__PC)
#define lcd_LCDPort_4_INTR	((uint16)((uint16)0x0001u << lcd_LCDPort__4__SHIFT))

#define lcd_LCDPort_5			(lcd_LCDPort__5__PC)
#define lcd_LCDPort_5_INTR	((uint16)((uint16)0x0001u << lcd_LCDPort__5__SHIFT))

#define lcd_LCDPort_6			(lcd_LCDPort__6__PC)
#define lcd_LCDPort_6_INTR	((uint16)((uint16)0x0001u << lcd_LCDPort__6__SHIFT))

#define lcd_LCDPort_INTR_ALL	 ((uint16)(lcd_LCDPort_0_INTR| lcd_LCDPort_1_INTR| lcd_LCDPort_2_INTR| lcd_LCDPort_3_INTR| lcd_LCDPort_4_INTR| lcd_LCDPort_5_INTR| lcd_LCDPort_6_INTR))

#endif /* End Pins lcd_LCDPort_ALIASES_H */


/* [] END OF FILE */
