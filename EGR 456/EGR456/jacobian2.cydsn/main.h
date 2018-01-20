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
#ifndef _MAIN_H_
#define _MAIN_H_
    
#include <project.h>
    
void hi();
int a;

struct Servo{
    int maxComp;
    int minComp;
    float maxAngle;
    float minAngle;
    int compare;
    void (*write)(unsigned short compare);
}BottomServo,TopServo;
   
void initializeServos(void);
int getCompare(struct Servo s, float angle);
void moveServo(struct Servo s, float angle);

#endif

/* [] END OF FILE */
