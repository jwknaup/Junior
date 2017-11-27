/*******************************************************************************
* File Name: motorB.h  
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

#if !defined(CY_PINS_motorB_ALIASES_H) /* Pins motorB_ALIASES_H */
#define CY_PINS_motorB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define motorB_0			(motorB__0__PC)
#define motorB_0_PS		(motorB__0__PS)
#define motorB_0_PC		(motorB__0__PC)
#define motorB_0_DR		(motorB__0__DR)
#define motorB_0_SHIFT	(motorB__0__SHIFT)
#define motorB_0_INTR	((uint16)((uint16)0x0003u << (motorB__0__SHIFT*2u)))

#define motorB_INTR_ALL	 ((uint16)(motorB_0_INTR))


#endif /* End Pins motorB_ALIASES_H */


/* [] END OF FILE */
