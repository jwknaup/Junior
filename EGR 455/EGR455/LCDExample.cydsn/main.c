#include "project.h"

int main(void)
{
    int i=1;
    LCD_Char_1_Start();
    i=5+5*5;
        LCD_Char_1_ClearDisplay();
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintNumber(i);

    for(;;)
    {
        
    }
}


