/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC18F47K40
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA4 procedures
#define RA4_SetHigh()    do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()   do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()   do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()         PORTAbits.RA4
#define RA4_SetDigitalInput()   do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()  do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()     do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()   do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode() do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()    do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()   do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()   do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()         PORTBbits.RB4
#define RB4_SetDigitalInput()   do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()  do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()     do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()   do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode() do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()     do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()   do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode() do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set channel_AND1 aliases
#define channel_AND1_TRIS               TRISDbits.TRISD1
#define channel_AND1_LAT                LATDbits.LATD1
#define channel_AND1_PORT               PORTDbits.RD1
#define channel_AND1_WPU                WPUDbits.WPUD1
#define channel_AND1_OD                ODCONDbits.ODCD1
#define channel_AND1_ANS                ANSELDbits.ANSELD1
#define channel_AND1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define channel_AND1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define channel_AND1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define channel_AND1_GetValue()           PORTDbits.RD1
#define channel_AND1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define channel_AND1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define channel_AND1_SetPullup()      do { WPUDbits.WPUD1 = 1; } while(0)
#define channel_AND1_ResetPullup()    do { WPUDbits.WPUD1 = 0; } while(0)
#define channel_AND1_SetPushPull()    do { ODCONDbits.ODCD1 = 0; } while(0)
#define channel_AND1_SetOpenDrain()   do { ODCONDbits.ODCD1 = 1; } while(0)
#define channel_AND1_SetAnalogMode()  do { ANSELDbits.ANSELD1 = 1; } while(0)
#define channel_AND1_SetDigitalMode() do { ANSELDbits.ANSELD1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/