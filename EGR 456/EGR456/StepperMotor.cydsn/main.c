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
#include "stdio.h"

int readKeypad(){
    int key=0;
    Row1_Write(1);
    Row2_Write(0);
    Row3_Write(0);
    Row4_Write(0);
    if(Col1_Read())
        key=1;
    else if(Col2_Read())
        key=2;
    else if(Col3_Read())
        key=3;
    else
        key = 0;
    return key;
}

void setPins(int a,int b,int c,int d){
    A_Write(a);
    B_Write(b);
    C_Write(c);
    D_Write(d);
}

void setVelocity(float omega, int direction){
    float delayS = (2.0*3.14159/2048.0/fabs(omega));
    delayS = delayS*1000.0;
    int delay = delayS;
    if(direction > 0){
        setPins(1,0,0,0);
        CyDelay(delay);
        setPins(0,1,0,0);
        CyDelay(delay);
        setPins(0,0,1,0);
        CyDelay(delay);
        setPins(0,0,0,1);
        CyDelay(delay);
    }
    else if(direction < 0){
        setPins(0,0,0,1);
        CyDelay(delay);
        setPins(0,0,1,0);
        CyDelay(delay);
        setPins(0,1,0,0);
        CyDelay(delay);
        setPins(1,0,0,0);
        CyDelay(delay);
    }
}

void moveToAngle(float theta, float omega, int direction){
    float angle = 0.0;
    float degPerStep = 360.0/2048.0;
    while(fabs(angle) < fabs(theta)){
        setVelocity(omega, direction);
        angle += degPerStep*4.0;
    }
    
}

int main(void)
{
    for(;;)
    {
    if(readKeypad() == 1)
        setVelocity(1.0, 1);
    else if(readKeypad() == 2)
        setVelocity(1.0, -1);
    else if(readKeypad() == 3)
        moveToAngle(180.0,0.31, -1);
        
    }
}

/* [] END OF FILE */
