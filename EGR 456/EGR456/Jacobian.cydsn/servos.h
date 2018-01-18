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
#ifndef _SERVOS_H_
#define _SERVOS_H_
   

void hello();

int a;
struct Servo{
    int maxComp;
    int minComp;
    float maxAngle;
    float minAngle;
    int compare;
    //void (*write)(unsigned short *compare);
};
   
void initializeServos(void);
int getCompare(struct Servo s, float angle);
//    
//int hy;
//    
#endif

/* [] END OF FILE */
