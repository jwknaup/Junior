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

#define rad2deg 180.0/3.14159

int theta1(float angle){
    int max_comp = 6450, min_comp = 1600, max_angle=180, min_angle=0;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}
int theta2(float angle){
    int max_comp = 6750, min_comp = 2050, max_angle=90, min_angle=-90;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}

int main(void)
{
    lcd_Start();
    lcd_ClearDisplay();
    lcd_Position(0,0);
        
    pwm1_Start();
    float x = 0.0;//5:9
    float y = 8.0;
    
    float a2 = 6.0, a4=5.25;
    float r1 = sqrt(x*x+y*y); //eq 1
    float phi1 = acos((a4*a4-a2*a2-r1*r1)/(-2.0*a2*r1)); //eq 2
    float phi2 = atan(y/x); //eq 3
    float T1 = phi2-phi1;
    float phi3 = acos((r1*r1-a2*a2-a4*a4)/(-2.0*a2*a4)); //eq 5
    float T2 = 3.14159-phi3;
    //T1=1, T2=0;
    
    lcd_PrintNumber((int)(T1*100));

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        pwm1_WriteCompare1(theta1(180)); //servo 1 full clockwise
        pwm1_WriteCompare2(theta2(-90)); //servo 2 full clockwise
        CyDelay(2000);
       
//        pwm1_WriteCompare1(theta1(180)); //servo 1 full ccw
//        CyDelay(2000);
//      
//        CyDelay(2000);
//        pwm1_WriteCompare2(theta2(90)); //servo 2 full ccw
//        CyDelay(2000);
    }
}

/* [] END OF FILE */
