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

// get/set IO_RA2 aliases
#define IO_RA2_TRIS               TRISAbits.TRISA2
#define IO_RA2_LAT                LATAbits.LATA2
#define IO_RA2_PORT               PORTAbits.RA2
#define IO_RA2_WPU                WPUAbits.WPUA2
#define IO_RA2_OD                ODCONAbits.ODCA2
#define IO_RA2_ANS                ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()      do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()    do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()    do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()   do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()  do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode() do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set IO aliases
#define IO_TRIS               TRISAbits.TRISA4
#define IO_LAT                LATAbits.LATA4
#define IO_PORT               PORTAbits.RA4
#define IO_WPU                WPUAbits.WPUA4
#define IO_OD                ODCONAbits.ODCA4
#define IO_ANS                ANSELAbits.ANSELA4
#define IO_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_GetValue()           PORTAbits.RA4
#define IO_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_SetPushPull()    do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_SetOpenDrain()   do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_SetAnalogMode()  do { ANSELAbits.ANSELA4 = 1; } while(0)
#define IO_SetDigitalMode() do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set SCK2 aliases
#define SCK2_TRIS               TRISBbits.TRISB1
#define SCK2_LAT                LATBbits.LATB1
#define SCK2_PORT               PORTBbits.RB1
#define SCK2_WPU                WPUBbits.WPUB1
#define SCK2_OD                ODCONBbits.ODCB1
#define SCK2_ANS                ANSELBbits.ANSELB1
#define SCK2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SCK2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SCK2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SCK2_GetValue()           PORTBbits.RB1
#define SCK2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SCK2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SCK2_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define SCK2_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define SCK2_SetPushPull()    do { ODCONBbits.ODCB1 = 0; } while(0)
#define SCK2_SetOpenDrain()   do { ODCONBbits.ODCB1 = 1; } while(0)
#define SCK2_SetAnalogMode()  do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SCK2_SetDigitalMode() do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS               TRISCbits.TRISC3
#define SCL1_LAT                LATCbits.LATC3
#define SCL1_PORT               PORTCbits.RC3
#define SCL1_WPU                WPUCbits.WPUC3
#define SCL1_OD                ODCONCbits.ODCC3
#define SCL1_ANS                ANSELCbits.ANSELC3
#define SCL1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL1_GetValue()           PORTCbits.RC3
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL1_SetPullup()      do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL1_ResetPullup()    do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL1_SetPushPull()    do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL1_SetOpenDrain()   do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCL1_SetAnalogMode()  do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SCL1_SetDigitalMode() do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS               TRISCbits.TRISC4
#define SDA1_LAT                LATCbits.LATC4
#define SDA1_PORT               PORTCbits.RC4
#define SDA1_WPU                WPUCbits.WPUC4
#define SDA1_OD                ODCONCbits.ODCC4
#define SDA1_ANS                ANSELCbits.ANSELC4
#define SDA1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA1_GetValue()           PORTCbits.RC4
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA1_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA1_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA1_SetPushPull()    do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDA1_SetOpenDrain()   do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDA1_SetAnalogMode()  do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SDA1_SetDigitalMode() do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set SS aliases
#define SS_TRIS               TRISCbits.TRISC5
#define SS_LAT                LATCbits.LATC5
#define SS_PORT               PORTCbits.RC5
#define SS_WPU                WPUCbits.WPUC5
#define SS_OD                ODCONCbits.ODCC5
#define SS_ANS                ANSELCbits.ANSELC5
#define SS_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SS_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SS_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SS_GetValue()           PORTCbits.RC5
#define SS_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SS_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SS_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define SS_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define SS_SetPushPull()    do { ODCONCbits.ODCC5 = 0; } while(0)
#define SS_SetOpenDrain()   do { ODCONCbits.ODCC5 = 1; } while(0)
#define SS_SetAnalogMode()  do { ANSELCbits.ANSELC5 = 1; } while(0)
#define SS_SetDigitalMode() do { ANSELCbits.ANSELC5 = 0; } while(0)

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

// get/set SDI2 aliases
#define SDI2_TRIS               TRISDbits.TRISD7
#define SDI2_LAT                LATDbits.LATD7
#define SDI2_PORT               PORTDbits.RD7
#define SDI2_WPU                WPUDbits.WPUD7
#define SDI2_OD                ODCONDbits.ODCD7
#define SDI2_ANS                ANSELDbits.ANSELD7
#define SDI2_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define SDI2_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define SDI2_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define SDI2_GetValue()           PORTDbits.RD7
#define SDI2_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define SDI2_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define SDI2_SetPullup()      do { WPUDbits.WPUD7 = 1; } while(0)
#define SDI2_ResetPullup()    do { WPUDbits.WPUD7 = 0; } while(0)
#define SDI2_SetPushPull()    do { ODCONDbits.ODCD7 = 0; } while(0)
#define SDI2_SetOpenDrain()   do { ODCONDbits.ODCD7 = 1; } while(0)
#define SDI2_SetAnalogMode()  do { ANSELDbits.ANSELD7 = 1; } while(0)
#define SDI2_SetDigitalMode() do { ANSELDbits.ANSELD7 = 0; } while(0)

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