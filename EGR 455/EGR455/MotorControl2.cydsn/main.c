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
    int count1, count2, dCount, target1=500, target2=1000;
    int rot, deg;
    float cpr = 814.0, rpm;
    int compare;
    int time;
    enc_Start();
    lcd_Start();
    pwm_Start();
    enc_SetCounter(0);

    for(;;)
    {
        count1 = enc_GetCounter();
        time=0;
        while(time<5000){
            count1 = enc_GetCounter();
            if(count1 < target1){
                pwm_WriteCompare1(83);
                pwm_WriteCompare2(0);
            }
            else if(count1 > target1){
                pwm_WriteCompare1(0);
                pwm_WriteCompare2(83); 
            }
            else{
                pwm_WriteCompare1(0);
                pwm_WriteCompare2(0);
            }
            lcd_ClearDisplay();
            lcd_Position(0,0);
            lcd_PrintNumber(count1);
            CyDelay(10);
            time+=10;
        }
               time=0;
        while(time<5000){
            count1 = enc_GetCounter();
            if(count1 < target2){
                pwm_WriteCompare1(83);
                pwm_WriteCompare2(0);
            }
            else if(count1 > target2){
                pwm_WriteCompare1(0);
                pwm_WriteCompare2(83); 
            }
            else{
                pwm_WriteCompare1(0);
                pwm_WriteCompare2(0);
            }
            lcd_ClearDisplay();
            lcd_Position(0,0);
            lcd_PrintNumber(count1);
            CyDelay(10);
            time+=10;
        }

    }
}

/* [] END OF FILE */
