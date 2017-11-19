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
void StackEventHandler(uint32 event, void* eventParam);
void IasEventHandler(uint32 event, void* eventParam);
void HandleAlertLEDs(uint8 status);

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
        
    //CyGlobalIntEnable; /* Enable global interrupts. */
    /* Start the BLE component and register StackEventHandler function */
    //CyBle_Start(StackEventHandler);
    /* Register IAS event handler function */
    //CyBle_IasRegisterAttrCallback(IasEventHandler);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    initializeSubsystems();
    testFlex();
    for(;;)
    {
        testSubsystems();
    }
}

//void StackEventHandler(uint32 event, void *eventParam)
//{
//    switch(event)
//    {
//        /* Mandatory events to be handled by Find Me Target design */
//        case CYBLE_EVT_STACK_ON:
//        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
//            /* Start the BLE fast advertisement. */
//            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
//            break;
//        
//        default:
//    	    break;
//    }
//}
//void IasEventHandler(uint32 event, void *eventParam)
//{
//    uint8 alertLevel;
//    CyBle_GattcWriteCharacteristicValue(
//    /* Alert Level Characteristic write event */
//    if(event == CYBLE_EVT_IASS_WRITE_CHAR_CMD)
//    {
//        /* Extract Alert Level value from the GATT DB using the 
//		 * CYBLE_IAS_ALERT_LEVEL as a parameter to CyBle_IassGetCharacteristicValue
//		 * routine. Store the Alert Level Characteristic value in "alertLevel"
//		 * variable */
//        
//        
//        /*Based on alert Level level recieved, Drive LED*/
//        HandleAlertLEDs(alertLevel);
//    }
//}


/* [] END OF FILE */
