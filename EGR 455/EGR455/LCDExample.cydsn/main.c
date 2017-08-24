#include "project.h"

int main(void)
{
    int i=1;
    LCD_Char_1_Start();
    while(i<15){
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintNumber(i);
        i=i+1;
        CyDelay(1000);
    }
    for(;;)
    {
        
    }
}


