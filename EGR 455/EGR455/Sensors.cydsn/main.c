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

int main(void)
{
    int count;

    enc_Start();
    lcd_Start();

    for(;;)
    {
        count = enc_GetCounter();
        lcd_ClearDisplay();
        lcd_Position(1,0);
        lcd_PrintNumber(count);
            
        if(switch1_Read()){
            lcd_Position(0,0);
            lcd_PrintString("ON");
        }
        else{
            lcd_Position(0,0);
            lcd_PrintString("off");
        }
        CyDelay(50);
    }
}

/* [] END OF FILE */
