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
    int count1, count2, dCount;
    int rot, deg;
    float cpr = 814.0, rpm;
    int compare;
    enc_Start();
    lcd_Start();
    adc_Start();
    adc_StartConvert();
    pwm_Start();

    for(;;)
    {
        pwm_WriteCompare1(100);
        pwm_WriteCompare2(0);
        
        CyDelay(2000);
        
        pwm_WriteCompare1(0);
        pwm_WriteCompare2(100);
//        compare = 0;
//        while(compare <= 100){
//            enc_SetCounter(0);
//            pwm_WriteCompare(compare);
//            CyDelay(1000);
//        //motor_Write(0);
//        //CyDelay(1000);
//        
//        
//        //adc_IsEndConversion(adc_WAIT_FOR_RESULT);
////        rot = adc_GetResult16(0);
////        deg = rot*270/4095;
//        
//            count1 = enc_GetCounter();
//            CyDelay(1000);
//            count2 = enc_GetCounter();
//            pwm_WriteCompare(100);
//            dCount = count2-count1;
//            rpm = dCount*60.0/cpr;
//        
//            lcd_ClearDisplay();
//            lcd_Position(0,0);
//            lcd_PrintNumber(compare);
//            lcd_Position(1,0);
//            lcd_PrintNumber(rpm);
//            CyDelay(2000);
//            compare+=10;
//        }
//            
//        CyDelay(50);
    }
}

/* [] END OF FILE */
