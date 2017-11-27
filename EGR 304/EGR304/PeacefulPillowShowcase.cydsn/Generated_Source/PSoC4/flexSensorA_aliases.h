/*******************************************************************************
* File Name: flexSensorA.h  
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

#if !defined(CY_PINS_flexSensorA_ALIASES_H) /* Pins flexSensorA_ALIASES_H */
#define CY_PINS_flexSensorA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define flexSensorA_0			(flexSensorA__0__PC)
#define flexSensorA_0_PS		(flexSensorA__0__PS)
#define flexSensorA_0_PC		(flexSensorA__0__PC)
#define flexSensorA_0_DR		(flexSensorA__0__DR)
#define flexSensorA_0_SHIFT	(flexSensorA__0__SHIFT)
#define flexSensorA_0_INTR	((uint16)((uint16)0x0003u << (flexSensorA__0__SHIFT*2u)))

#define flexSensorA_INTR_ALL	 ((uint16)(flexSensorA_0_INTR))


#endif /* End Pins flexSensorA_ALIASES_H */


/* [] END OF FILE */
