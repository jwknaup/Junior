/*******************************************************************************
* File Name: flexSensorB.h  
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

#if !defined(CY_PINS_flexSensorB_ALIASES_H) /* Pins flexSensorB_ALIASES_H */
#define CY_PINS_flexSensorB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define flexSensorB_0			(flexSensorB__0__PC)
#define flexSensorB_0_PS		(flexSensorB__0__PS)
#define flexSensorB_0_PC		(flexSensorB__0__PC)
#define flexSensorB_0_DR		(flexSensorB__0__DR)
#define flexSensorB_0_SHIFT	(flexSensorB__0__SHIFT)
#define flexSensorB_0_INTR	((uint16)((uint16)0x0003u << (flexSensorB__0__SHIFT*2u)))

#define flexSensorB_INTR_ALL	 ((uint16)(flexSensorB_0_INTR))


#endif /* End Pins flexSensorB_ALIASES_H */


/* [] END OF FILE */
