
#include "project.h"

int main(void)
{
    int i=0;

    for(;;)
    {
        White_LED_Write(0);
        i=0;
        while(i<3){
            Blue_LED_Write(1);
            CyDelay(1000);
            Blue_LED_Write(0);
            CyDelay(1000);
            i++;
        }
        
        White_LED_Write(1);
        CyDelay(1000);
        White_LED_Write(0);
    }
}
