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
#include "main.h"

uint8_t i2caddr;
I2C1_MESSAGE_STATUS status;

void writeRegister(uint8_t regAddr, uint8_t regValue){
    uint8_t data = regAddr;
    I2C1_MasterWrite(&data, 1, MCP23017_ADDRESS | i2caddr, &status);
    data = regValue;
    I2C1_MasterWrite(&data, 1, MCP23017_ADDRESS | i2caddr, &status);
}

uint8_t readRegister(uint8_t addr){
    uint8_t data=addr;
    I2C1_MasterWrite(&data,1,MCP23017_ADDRESS | i2caddr, &status);
    uint8_t result;
    I2C1_MasterRead(&result, 1, MCP23017_ADDRESS | i2caddr, &status);
    return result;
}

void mcpBegin(uint8_t addr){
    if (addr > 7) {
		addr = 7;
	}
	i2caddr = addr;

	I2C1_Initialize();

	// set defaults!
	// all inputs on port A and B
	writeRegister(MCP23017_IODIRA,0xff);
    writeRegister(MCP23017_IODIRB,0xff);
}

uint8_t regForPin(uint8_t pin, uint8_t portAaddr, uint8_t portBaddr){
    return(pin<8) ?portAaddr:portBaddr;
}
uint8_t bitForPin(uint8_t pin){
    return pin%8;
}
uint8_t bitWrite(uint8_t x, unsigned int n, bool b) {
    if (n <= 7 && n >= 0) {
        if (b) {
            x |= (1u << n);
        } else {
            x &= ~(1u << n);
        }
    } 
    return x;
}

void updateRegisterBit(uint8_t pin, uint8_t pValue, uint8_t portAaddr, uint8_t portBaddr){
    uint8_t regValue;
    uint8_t regAddr = regForPin(pin, portAaddr, portBaddr);
    uint8_t bitty = bitForPin(pin);
    regValue = readRegister(regAddr);
    
    regValue = bitWrite(regValue, bitty, pValue);
    
    writeRegister(regAddr, regValue);
}

void mcpPinMode(uint8_t p, uint8_t d){
    updateRegisterBit(p,(d==INPUT),MCP23017_IODIRA, MCP23017_IODIRB);
}

uint8_t digitalRead(uint8_t pin) {
    uint8_t bitty = bitForPin(pin);
    uint8_t regAddr=regForPin(pin,MCP23017_GPIOA,MCP23017_GPIOB);
    return (readRegister(regAddr) >> bitty) & 0x1;
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
    

    mcpBegin(0);
    mcpPinMode(8,INPUT);
    
    while (1)
    {
        if(digitalRead(8)){
            LED_Toggle();
        }
        
        __delay_ms(50);
        
        // Add your application code
    }
}
/**
 End of File
*/