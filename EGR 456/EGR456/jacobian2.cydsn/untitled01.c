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
#include <main.h>

void hi(){
    a=2;
}
void initializeServos(){
    
    Servos_Start();
    
    BottomServo.minComp = 1600;
    BottomServo.maxComp = 6450;
    BottomServo.minAngle = 0.0;
    BottomServo.maxAngle = 180.0;
    BottomServo.write = Servos_WriteCompare1;
    
    TopServo.minComp = 2050;
    TopServo.maxComp = 6750;
    TopServo.minAngle = 0.0;
    TopServo.maxAngle = 180.0;
    TopServo.write = Servos_WriteCompare2;
}

int getCompare(struct Servo s, float angle){
    s.compare = (s.maxComp-s.minComp)/(s.maxAngle-s.minAngle)*(angle-s.minAngle) + s.minComp;
    return s.compare;
}

void moveServo(struct Servo s, float angle){
    getCompare(s,angle);
    s.write(s.compare);
}

/* [] END OF FILE */
