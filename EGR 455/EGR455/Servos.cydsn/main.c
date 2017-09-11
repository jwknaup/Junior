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

int theta1(float angle){
    int max_comp = 6450, min_comp = 1600, max_angle=180, min_angle=0;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}
int theta2(float angle){
    int max_comp = 7000, min_comp = 2100, max_angle=90, min_angle=-90;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}

int main(void)
{
    pwm1_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        pwm1_WriteCompare1(theta1(45)); //servo 1 full clockwise
        pwm1_WriteCompare2(theta2(45)); //servo 2 full clockwise
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
