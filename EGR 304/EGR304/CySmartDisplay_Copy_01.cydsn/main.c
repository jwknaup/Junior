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
#include <main.h>

char buffer[180]; 

void DisplayMessage(char *message, uint8 length)
{
    uint8 i;
    
    //Timer_CLK_Stop();
    //pos = 0;
    
    stpncpy(buffer, message, length);
    for (i = length; i<180; i++)
    {
        buffer[i] = 0;
    }
    
    //Timer_CLK_Start();
}
void testFlex(){
    int analog1, analog2;
    char buffer[] = "Flex Sensor 1: 2016\n Flex Sensor 2: 2017";
    adc_Start();
    adc_StartConvert();
    UART_Start();
    for(int i=0;i<100;i++){
        adc_IsEndConversion(adc_WAIT_FOR_RESULT);
        analog1 = adc_GetResult16(0);
        analog2 = adc_GetResult16(1);
        sprintf(buffer, "Flex Sensor 1: %d Flex Sensor 2: %d\n", analog1, analog2);
        //print
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
    uart2_Start();
    CyBle_Start(StackEventHandler);
}

int flexGet(int num){
    adc_IsEndConversion(adc_WAIT_FOR_RESULT);
    return adc_GetResult16(num);
}
void buzzerSet(int compare){
    pwmBuzzer_WriteCompare(compare);
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //StandardDisplayInit();
    
    CyGlobalIntEnable;
    char text[32];
    int flexA, flexB;
    
    initializeSubsystems();
    
    while(1)
    {   
        flexA = flexGet(0)-500;
        flexB = flexGet(1)-650;
        sprintf(text, "left: %d, right: %d", flexA, flexB);
        uart2_PutString(text);
        uart2_PutChar('\n');
        DisplayMessage(text, sizeof(text));
        
        if(flexA<500 && flexB<500){
            pwmBuzzer_WriteCompare(50);
            motorA_Write(1);
            motorB_Write(1);
        }
        else if(flexA < 500){
            motorA_Write(1);
            motorB_Write(0);
            pwmBuzzer_WriteCompare(0);
        }
        else if(flexB < 500){
            motorB_Write(1);
            motorA_Write(0);
            pwmBuzzer_WriteCompare(0);
        }
        else{
            motorB_Write(0);
            motorA_Write(0);
            pwmBuzzer_WriteCompare(0);
        }
        
        
        for(int i=0; i< 100100; i++){
            CyBle_ProcessEvents();
        }
    }
        
}

/* [] END OF FILE */
