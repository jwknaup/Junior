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
//#include "project.h"
#include <main.h>

int theta1(float angle){
    int max_comp = 6450, min_comp = 1600, max_angle=180, min_angle=0;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}
int theta2(float angle){
    int max_comp = 6750, min_comp = 2050, max_angle=180, min_angle=0;
    int compare;
    compare = (max_comp-min_comp)/(max_angle-min_angle)*(angle-min_angle) + min_comp;
    return compare;
}

void calibrateServos(){
    for(;;)
    {
        /* Place your application code here. */
        Servos_WriteCompare1(theta1(0.0));
        CyDelay(1000);
        Servos_WriteCompare2(theta2(0.0));
        CyDelay(1000);
    
    }
}
    

int main(void)
{
    //CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    initializeServos();
    moveServo(BottomServo,0.0);
    //Servos_WriteCompare1(theta1(0.0));
    Servos_WriteCompare2(theta2(0.0));
    CyDelay(3000);
    
    float velocity = 0;//deg per s
    float angle1=0.0;
    float inc = velocity/100.0;
    while(angle1 < 180.0){
        Servos_WriteCompare1(theta1(0.0));
        angle1+=inc;
        CyDelay(10);
    }
    
    
}

/* [] END OF FILE */
