#include <device.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16 PWMCompare;
    PWM_Start(); /* Replace this line with the PWM start API */

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        PWMCompare = PWMCompare + 1;
        if( PWMCompare >= 1000 )
            PWMCompare = 0;
        PWM_WriteCompare(750); /* Replace this line with the PWM write compare API */
        CyDelay(1);
    }
    
    return 1;
}

/* [] END OF FILE */
