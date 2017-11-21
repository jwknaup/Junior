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

#include "main.h"

char buffer[180];

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
        sprintf(buffer, "Flex Sensor 1: %d Flex Sensor 2: %d\n", analog1, analog2);
        uart_PutString(buffer);
        CyDelay(100);
    }
}

void testMotor(){
    motorA_Write(0);
    motorB_Write(1);
    CyDelay(2000);
    motorA_Write(1);
    motorB_Write(0);
    CyDelay(2000);
    motorA_Write(0);
}

void testBuzzer(){
    pwmBuzzer_WriteCompare(50);
    CyDelay(3000);
    pwmBuzzer_WriteCompare(0);
    CyDelay(3000);
}


void DisplayMessage(char *message, uint8 length)
{
    uint8 i;
    
    //Timer_CLK_Stop();
    
    stpncpy(buffer, message, length);
    for (i = length; i<180; i++)
    {
        buffer[i] = 0;
    }
    
    //Timer_CLK_Start();
}

void testBle(){
    /* Start BLE component */
    
    //sprintf(buffer, "output %d", 5);
    
    //DisplayMessage(buffer, 16);

    CyBle_Start(StackEventHandler);
        /* Register the Heart Rate Service event handler callback. The function
     * to be registered is HrsEventHandler().
     */
	//CyBle_HrsRegisterAttrCallback(HrsEventHandler);
    while(1){
        //SendHeartRateOverBLE();
        CyBle_ProcessEvents();
    }
}

void initializeSubsystems(){
    pwmBuzzer_Start();
    pwmBuzzer_WriteCompare(0);
    adc_Start();
    adc_StartConvert();
    uart_Start();
}

int flexGet(int num){
    adc_IsEndConversion(adc_WAIT_FOR_RESULT);
    return adc_GetResult16(num);
}
void buzzerSet(int compare){
    pwmBuzzer_WriteCompare(compare);
}
    

void testSubsystems(){
    //testFlex();
    testMotor();
    testBuzzer();
}

int main(void)
{
    //testSubsystems();
    //testFlex();
        
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Start the BLE component and register StackEventHandler function */
    //CyBle_Start(StackEventHandler);
    /* Register IAS event handler function */
    //CyBle_IasRegisterAttrCallback(IasEventHandler);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    testBle();
    
    
    initializeSubsystems();
    testFlex();
    for(;;)
    {
        testSubsystems();
    }
}
