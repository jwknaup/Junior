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

void writePeriods(int per1, int per2){
    PWM_1_WritePeriod(per1);
    PWM_2_WritePeriod(per2);
}

void writeCompares(int comp1, int comp2){
    PWM_1_WriteCompare(comp1);
    PWM_2_WriteCompare(comp2);
}

void setDirections(int dir1, int dir2){
    PWM_1_SetCompareMode(dir1);
    PWM_1_SetCompareMode(dir2);
}

void resetCounters(){
    PWM_1_WriteCounter(0);
    PWM_2_WriteCounter(0);
}

void writePwms(int per, int comp){
    writePeriods(per, per);
    writeCompares(comp,comp);
}


int main(void)
{
    float motorSpeed=1.0;
    int direction = 2;
    int period;
    int clockSpeed = 10000;
    uint8 receive1, receive2;
    
    PWM_1_Start();
    PWM_2_Start();
    UART_Start();
    
    for(;;)
    {
        receive1=UART_GetChar();
        while(!receive1){
            receive1 = UART_GetChar();
        }
        receive2 = UART_GetChar();
        while(!receive2){
            receive2 = UART_GetChar();
        }
        if(receive1 == 1 || receive1 == 2){
            direction = receive1;
            motorSpeed = receive2;
        }
        else{
            direction = receive2;
            motorSpeed = receive1;
        }
        
    if(direction == 1)
        setDirections(3,1);
    else if (direction == 2)
        setDirections(1,3);
    resetCounters();
    period = 4.0*clockSpeed/motorSpeed;
    writePwms(period, period/2.0);
            
    }
}

/* [] END OF FILE */
