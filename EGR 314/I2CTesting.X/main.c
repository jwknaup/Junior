/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC18F47K40
        Driver Version    :  2.00
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"

uint8_t readIoExpander(uint8_t addr, char bank){
    uint8_t data[2];
    if(bank == 'A' || bank == 'a' || bank == 'r' || bank == 'R')
        data[0]=0x12;
    else
        data[0]=0x13;
    i2c_writeNBytes(addr, &data[0], 1);
    uint8_t rec;
    i2c_readNBytes(addr, &rec, 1);
    return ~rec;
}

uint8_t updateExpanders(){
    uint8_t lL, lR, mL, mR, rL, rR;
    lL = readIoExpander(0x20, 'l');
    lR = readIoExpander(0x20, 'r');
    mL = readIoExpander(0x21, 'l');
    mR = readIoExpander(0x21, 'r');
    rL = readIoExpander(0x22, 'l');
    rR = readIoExpander(0x22, 'r');
    
    spaces = lL+lR+mL+mR+rL+rR;
    return spaces;
}

uint8_t getSpaces(void){
    uint8_t space = 0;
    uint8_t spaceLast = updateExpanders();    
    for(int i=0;i<40;i++){
        space = updateExpanders();
        if(space != spaceLast)
            i=0;
        spaceLast = space;
        __delay_ms(50);
    }
}



/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //send the space number, alternate between space 
    //detect when a player has reached the last space 
    //tell the score pad when the last space is reached
    //receive player's score from score pad
    //repeat for second player
    //send player1/2 scores to photon
    
    //i2c_writeNBytes(i2c_address_t address, void* data, size_t len); 
    uint8_t data[2];
    uint8_t addr = 0x20;
    uint8_t gamerScore = 0x17;  //gammer score = 23
    uint8_t photonAddress = 0x30;  //I2C address for Particle 
    
    //set A to out
//    data[0] = 0x00;
//    data[1] = 0x00;
//    i2c_writeNBytes(addr, data, 2);
    //set B to out
//    data[0]=0x01
//    i2c_writeNBytes(addr, data, 2);    
    
    
    //read B
//    data[0]=0x13;
//    i2c_writeNBytes(addr, &data[0], 1);
//    uint8_t rec;
//    i2c_readNBytes(addr, &rec, 1);

    //set A;
//    data[0]=0x12;
//    data[1]=8;
//    i2c_writeNBytes(addr, data, 2);
    
    //i2c_writeNBytes(photonAddress, &gamerScore, 1); //sends gamer score to the Photon
    
    for(int i=0; i<80; i++)
        __delay_ms(50);

    EUSART2_Initialize();
    
    //uint8_t rec = 0;

    while (1)
    {
//        // Read B
//        data[0]=0x12;
//        i2c_writeNBytes(addr, &data[0], 1);
//        uint8_t rec;
//        i2c_readNBytes(addr, &rec, 1);
//
//        //set LED
//        if(rec != 0b11111111)
//            IO_RA2_SetLow();
//        else
//            IO_RA2_SetHigh();
//        
//        for(int i=0; i<20; i++)
//            __delay_ms(50);    
        
        EUSART2_Write(~rec);
        
        if(EUSART2_is_rx_ready())
            rec = EUSART2_Read();
        if(rec == 64)
            IO_RA2_SetLow();
        
        for(int i=0; i<20; i++)
            __delay_ms(50);

    }
}
/**
 End of File
*/