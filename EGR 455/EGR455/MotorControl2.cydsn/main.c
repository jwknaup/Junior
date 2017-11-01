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
#include "stdlib.h"
#include "math.h"

int main(void)
{
    int count, count2, dCount, target1=1000, target2=2000;
    int rot, deg;
    float cpr = 814.0, rpm;
    int compare;
    int time;
    int error, P;
    float kP=3.0;
    enc_Start();    
    lcd_Start();
    pwm_Start();
    enc_SetCounter(0);
    uart_Start();
    uint8 receive;

    while(1){
        receive = uart_GetChar();
        if(receive){
            lcd_ClearDisplay();
            lcd_Position(0,0);
            lcd_PrintNumber(receive);
            for(uint8 i=1;i<=10;i++){
                uart_PutChar(i);
                CyDelay(200);
            }
        }
    }
    for(;;)
    {
        count = enc_GetCounter();
        time=0;
        while(time<5000){
            count = enc_GetCounter();
            error = target1 - count;
            P = kP*abs(error);
            if(P>100)
                P=100;
            if(error>0){                
                pwm_WriteCompare1(P);
                pwm_WriteCompare2(0);
            }
            else{
                pwm_WriteCompare1(0);
                pwm_WriteCompare2(P);
            }
            lcd_ClearDisplay();
            lcd_Position(0,0);
            lcd_PrintNumber(count);
            CyDelay(10);
            time+=10;
        }
        time=0;
        while(time<5000){
            count = enc_GetCounter();
            error = target2 - count;
            P = kP*abs(error);
            if(P>100)
                P=100;
            if(error>0){                
                pwm_WriteCompare1(P);
                pwm_WriteCompare2(0);
            }
            else{
                pwm_WriteCompare1(0);
                pwm_WriteCompare2(P);
            }
            lcd_ClearDisplay();
            lcd_Position(0,0);
            lcd_PrintNumber(count);
            CyDelay(10);
            time+=10;
        }

    }
}

/* [] END OF FILE */
