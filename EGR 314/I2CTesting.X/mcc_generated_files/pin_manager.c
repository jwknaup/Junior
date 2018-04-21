/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC18F47K40
        Driver Version    :  1.02
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"



void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */   
    LATE = 0x00;    
    LATD = 0x00;    
    LATA = 0x0C;    
    LATB = 0x00;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISE = 0x07;
    TRISA = 0xEB;
    TRISB = 0xFF;
    TRISC = 0xDF;
    TRISD = 0x7F;

    /**
    ANSELx registers
    */   
    ANSELC = 0xE7;
    ANSELB = 0xFF;
    ANSELD = 0xF7;
    ANSELE = 0x07;
    ANSELA = 0xFF;

    /**
    WPUx registers
    */ 
    WPUD = 0x88;
    WPUE = 0x00;
    WPUB = 0x02;
    WPUA = 0x00;
    WPUC = 0x18;

    /**
    ODx registers
    */   
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;
    


   
    
    
    RC3PPS = 0x0F;   //RC3->MSSP1:SCL1;
    RC4PPS = 0x10;   //RC4->MSSP1:SDA1;
    SSP1CLKPPSbits.SSPCLKPPS = 0x13;   //RC3->MSSP1:SCL1;
    RD7PPS = 0x0B;   //RD7->EUSART2:TX2;
    RX2PPSbits.RXPPS = 0x1B;   //RD3->EUSART2:RX2;
    SSP1DATPPSbits.SSPDATPPS = 0x14;   //RC4->MSSP1:SDA1;

}       

void PIN_MANAGER_IOC(void)
{   

}

/**
 End of File
*/