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

int main(void)
{
    int count;
    int rot, deg;
    enc_Start();
    lcd_Start();
    adc_Start();
    adc_StartConvert();

    for(;;)
    {
        adc_IsEndConversion(adc_WAIT_FOR_RESULT);
        rot = adc_GetResult16(0);
        deg = rot*270/4095;
        
        count = enc_GetCounter();
        
        lcd_ClearDisplay();
        lcd_Position(1,0);
        lcd_PrintNumber(deg);
            
        if(switch1_Read()){
            lcd_Position(0,0);
            lcd_PrintString("ON");
        }
        else{
            lcd_Position(0,0);
            lcd_PrintString("off");
        }
        CyDelay(50);
    }
}

/* [] END OF FILE */
