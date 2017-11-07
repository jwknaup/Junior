/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdlib.h>

void testFlex(){
    int analog1, analog2;
    char buffer[] = "Flex Sensor 1: 2016\n Flex Sensor 2: 2017";
    adc_Start();
    adc_StartConvert();
    uart_Start();
    for(int i=0;i<100;i++){
        adc_IsEndConversion(adc_WAIT_FOR_RESULT);
        analog1 = adc_GetResult16(0);
        analog2 = adc_GetResult16(1);
        sprintf(buffer, "Flex Sensor 1: %d\n Flex Sensor 2: %d", analog1, analog2);
        uart_PutString(buffer);
    }
}

void testMotor(){
    motorA_Write(0);
    motorB_Write(1);
    CyDelay(2000);
    motorA_Write(1);
    motorB_Write(0);
}

void testBuzzer(){
    pwmBuzzer_Start();
    pwmBuzzer_WriteCompare(50);
    CyDelay(3000);
    pwmBuzzer_WriteCompare(0);
}

void testSubsystems(){
    testFlex();
    testMotor();
    testBuzzer();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    testSubsystems();
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
