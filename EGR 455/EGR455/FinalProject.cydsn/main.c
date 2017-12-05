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
#include "math.h"
//#include "stdio.h"
#include "stdlib.h"

#define rad2deg 180.0/3.14159

int theta1(float angle){
    int max_comp = 6400, min_comp = 1700, max_angle=180, min_angle=0;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}
int theta2(float angle){
    int max_comp = 6850, min_comp = 2300, max_angle=90, min_angle=-90;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}

uint8 receive;
int main(void)
{
    
    lcd_Start();
    lcd_ClearDisplay();
    lcd_Position(0,0);
    
    uart_Start();
        
    servoPwm_Start();
    motorPwm_Start();
    enc_Start();    
    
    receive = uart_GetChar();
    while(!receive)
        receive = uart_GetChar();
    lcd_PrintNumber(receive);
    float x=receive;
    receive = uart_GetChar();
    while(!receive)
        receive = uart_GetChar();
    lcd_PrintNumber(receive);
    float y=receive;
    
    int count, error, target;
    
    //float x = 4.0;//5:9
    //float y = 8.0;
    
    float a2 = 6.0, a4=6.0;
    float r1 = sqrt(x*x+y*y); //eq 1
    float phi1 = acos((a4*a4-a2*a2-r1*r1)/(-2.0*a2*r1)); //eq 2
    float phi2 = atan(y/x); //eq 3
    float T1 = phi2-phi1;
    float phi3 = acos((r1*r1-a2*a2-a4*a4)/(-2.0*a2*a4)); //eq 5
    float T2 = 3.14159-phi3;
    //T1=1, T2=0;
    
    enc_SetCounter(0);

  
    servoPwm_WriteCompare1(theta1(T1*rad2deg)); //servo 1 full clockwise
    servoPwm_WriteCompare2(theta2(T2*rad2deg)); //servo 2 full clockwise
    CyDelay(2000);
    
    target = -1700;
    count = enc_GetCounter();
    error = abs(target - count);
    int t=0;
    while(error > 50 && t < 1200){
        motorPwm_WriteCompare1(0);
        motorPwm_WriteCompare2(100);
        count = enc_GetCounter();
        error = abs(target - count);
        lcd_ClearDisplay();
        lcd_Position(0,0);
        lcd_PrintNumber(count);
        t+=10;
        CyDelay(10);
    }
    motorPwm_WriteCompare1(0);
    motorPwm_WriteCompare2(0);
    
    mag_Write(1);
    CyDelay(500);
    target = 0;
    count = enc_GetCounter();
    error = abs(target - count);
    while(error > 10){
        motorPwm_WriteCompare1(70);
        motorPwm_WriteCompare2(0);
        count = enc_GetCounter();
        error = abs(target - count);
        lcd_PrintNumber(error);
    }
    motorPwm_WriteCompare1(0);
    motorPwm_WriteCompare2(0);

    for(;;)
    {
        servoPwm_WriteCompare1(theta1(0*rad2deg)); //servo 1 full clockwise
        servoPwm_WriteCompare2(theta2(0*rad2deg)); //servo 2 full clockwise
        CyDelay(1000);
       mag_Write(0);
//        servoPwm_WriteCompare1(theta1(180)); //servo 1 full ccw
//        CyDelay(2000);
//      
//        CyDelay(2000);
//        servoPwm_WriteCompare2(theta2(90)); //servo 2 full ccw
//        CyDelay(2000);
    }
}

/* [] END OF FILE */
