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
#include "math.h"
    

int main(void)
{
    float a1 = 4.9, a2 = 6.0, a3 = 5.5, a4 = 7.2, a5 = 8.9;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    initializeServos();
    
    BottomServo.omega = 0.0;//deg per s
    BottomServo.theta = 60.0;//60
    BottomServo.inc = BottomServo.omega/100.0;
    
    TopServo.omega = 0.0;
    TopServo.theta = -80.0;//-80
    TopServo.inc = TopServo.omega/100.0;
    
    moveServo(BottomServo, BottomServo.theta);
    moveServo(TopServo, TopServo.theta);
    CyDelay(3000);
    
    float jac1, jac2;
    float x=0.0, y=0.0;
    float xDot = -0.0, yDot = 1.0;
    
    while((pow(x,2) + pow(y,2)) < pow(a2+a4,2) - 1){
               
        float q1 = BottomServo.theta*3.14159/180.0;
        float q2 = TopServo.theta*3.14159/180.0;
        
        x = a2*cos(q1) - a4*sin(q1)*sin(q2) + a4*cos(q1)*cos(q2);
        y = a2*sin(q1) + a4*sin(q1)*cos(q2) + a4*sin(q2)*cos(q1);
        
        jac1 = 1.0*(xDot*cos(q1 + q2) + yDot*sin(q1 + q2))/(a2*sin(q2));
        jac2  = -(1.0*a2*xDot*cos(q1) + 1.0*a2*yDot*sin(q1) + 1.0*a4*xDot*cos(q1 + q2) + 1.0*a4*yDot*sin(q1 + q2))/(a2*a4*sin(q2));
    
        BottomServo.omega = jac1*180.0/3.14159;//deg per s
        BottomServo.inc = BottomServo.omega/100.0;
        BottomServo.theta += BottomServo.inc;
        
        TopServo.omega = jac2*180.0/3.14159;//deg per s
        TopServo.inc = TopServo.omega/100.0;
        TopServo.theta += TopServo.inc;
        
        moveServo(BottomServo, BottomServo.theta);
        moveServo(TopServo, TopServo.theta);
             
        CyDelay(10);
    }
    //moveServo(TopServo, TopServo.theta);
    //moveServo(BottomServo, BottomServo.theta);
    
    
}

/* [] END OF FILE */
