#include <device.h>
#include <LED_RGB.h>
#include <stdio.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16 ADCResult;
    LED_RGB_Start();
    char buffer[32];
    
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    
    ADC_Start(); /* Replace this line with the ADC Start code */
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    UART_1_Start();
    for(;;)
    {
        /* Place your application code here. */
        ADCResult = ADC_GetResult16(0); /* Replace this line with the ADC Get Result API */
        LED_RGB_SetColorRGB(ADCResult * (65500 / 2048), 0, 0);
        sprintf(buffer, "%d \n", ADCResult);
        UART_1_PutString(buffer);
        CyDelay(10);
    }
    return 1;
}

/* [] END OF FILE */
