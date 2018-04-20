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

// get/set MOTOR aliases
#define MOTOR_TRIS               TRISAbits.TRISA4
#define MOTOR_LAT                LATAbits.LATA4
#define MOTOR_PORT               PORTAbits.RA4
#define MOTOR_WPU                WPUAbits.WPUA4
#define MOTOR_OD                ODCONAbits.ODCA4
#define MOTOR_ANS                ANSELAbits.ANSELA4
#define MOTOR_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define MOTOR_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define MOTOR_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define MOTOR_GetValue()           PORTAbits.RA4
#define MOTOR_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define MOTOR_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define MOTOR_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define MOTOR_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define MOTOR_SetPushPull()    do { ODCONAbits.ODCA4 = 0; } while(0)
#define MOTOR_SetOpenDrain()   do { ODCONAbits.ODCA4 = 1; } while(0)
#define MOTOR_SetAnalogMode()  do { ANSELAbits.ANSELA4 = 1; } while(0)
#define MOTOR_SetDigitalMode() do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set SS aliases
#define SS_TRIS               TRISCbits.TRISC6
#define SS_LAT                LATCbits.LATC6
#define SS_PORT               PORTCbits.RC6
#define SS_WPU                WPUCbits.WPUC6
#define SS_OD                ODCONCbits.ODCC6
#define SS_ANS                ANSELCbits.ANSELC6
#define SS_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SS_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SS_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SS_GetValue()           PORTCbits.RC6
#define SS_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SS_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SS_SetPullup()      do { WPUCbits.WPUC6 = 1; } while(0)
#define SS_ResetPullup()    do { WPUCbits.WPUC6 = 0; } while(0)
#define SS_SetPushPull()    do { ODCONCbits.ODCC6 = 0; } while(0)
#define SS_SetOpenDrain()   do { ODCONCbits.ODCC6 = 1; } while(0)
#define SS_SetAnalogMode()  do { ANSELCbits.ANSELC6 = 1; } while(0)
#define SS_SetDigitalMode() do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set SCK2 aliases
#define SCK2_TRIS               TRISDbits.TRISD1
#define SCK2_LAT                LATDbits.LATD1
#define SCK2_PORT               PORTDbits.RD1
#define SCK2_WPU                WPUDbits.WPUD1
#define SCK2_OD                ODCONDbits.ODCD1
#define SCK2_ANS                ANSELDbits.ANSELD1
#define SCK2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SCK2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SCK2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SCK2_GetValue()           PORTDbits.RD1
#define SCK2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SCK2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SCK2_SetPullup()      do { WPUDbits.WPUD1 = 1; } while(0)
#define SCK2_ResetPullup()    do { WPUDbits.WPUD1 = 0; } while(0)
#define SCK2_SetPushPull()    do { ODCONDbits.ODCD1 = 0; } while(0)
#define SCK2_SetOpenDrain()   do { ODCONDbits.ODCD1 = 1; } while(0)
#define SCK2_SetAnalogMode()  do { ANSELDbits.ANSELD1 = 1; } while(0)
#define SCK2_SetDigitalMode() do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set SDI2 aliases
#define SDI2_TRIS               TRISDbits.TRISD2
#define SDI2_LAT                LATDbits.LATD2
#define SDI2_PORT               PORTDbits.RD2
#define SDI2_WPU                WPUDbits.WPUD2
#define SDI2_OD                ODCONDbits.ODCD2
#define SDI2_ANS                ANSELDbits.ANSELD2
#define SDI2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define SDI2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define SDI2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define SDI2_GetValue()           PORTDbits.RD2
#define SDI2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define SDI2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define SDI2_SetPullup()      do { WPUDbits.WPUD2 = 1; } while(0)
#define SDI2_ResetPullup()    do { WPUDbits.WPUD2 = 0; } while(0)
#define SDI2_SetPushPull()    do { ODCONDbits.ODCD2 = 0; } while(0)
#define SDI2_SetOpenDrain()   do { ODCONDbits.ODCD2 = 1; } while(0)
#define SDI2_SetAnalogMode()  do { ANSELDbits.ANSELD2 = 1; } while(0)
#define SDI2_SetDigitalMode() do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set SDO2 aliases
#define SDO2_TRIS               TRISDbits.TRISD3
#define SDO2_LAT                LATDbits.LATD3
#define SDO2_PORT               PORTDbits.RD3
#define SDO2_WPU                WPUDbits.WPUD3
#define SDO2_OD                ODCONDbits.ODCD3
#define SDO2_ANS                ANSELDbits.ANSELD3
#define SDO2_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define SDO2_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define SDO2_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define SDO2_GetValue()           PORTDbits.RD3
#define SDO2_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define SDO2_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define SDO2_SetPullup()      do { WPUDbits.WPUD3 = 1; } while(0)
#define SDO2_ResetPullup()    do { WPUDbits.WPUD3 = 0; } while(0)
#define SDO2_SetPushPull()    do { ODCONDbits.ODCD3 = 0; } while(0)
#define SDO2_SetOpenDrain()   do { ODCONDbits.ODCD3 = 1; } while(0)
#define SDO2_SetAnalogMode()  do { ANSELDbits.ANSELD3 = 1; } while(0)
#define SDO2_SetDigitalMode() do { ANSELDbits.ANSELD3 = 0; } while(0)

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