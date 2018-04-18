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


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc.h"
#include "spi2_driver.h"

#pragma warning disable 520        

inline void spi2_close(void)
{
    SSP2CON1bits.SSPEN = 0;
}

//con1 == SSPxCON1, stat == SSPxSTAT, add == SSPxADD
typedef struct { uint8_t con1; uint8_t stat; uint8_t add; } spi2_configuration_t;
static const spi2_configuration_t spi2_configuration[] = {   
    {0x0, 0x40, 0x4 }
};

//Setup SPI for Master Mode
bit spi2_master_open(spi2_modes spiUniqueConfiguration)
{
    if(!SSP2CON1bits.SSPEN)
    {
        SSP2STAT = spi2_configuration[spiUniqueConfiguration].stat;
        SSP2CON1 |= spi2_configuration[spiUniqueConfiguration].con1 | 0x2A;
        SSP2CON2 = 0x00;
        SSP2ADD = spi2_configuration[spiUniqueConfiguration].add | 0;

        SCK2_SetDigitalOutput();
        return true;
    }
    return false;
}

//Setup SPI for Slave Mode
bit spi2_slave_open(spi2_modes spiUniqueConfiguration)
{
    if(!SSP2CON1bits.SSPEN)
    {
        SSP2STAT = spi2_configuration[spiUniqueConfiguration].stat;
        SSP2CON1 |= spi2_configuration[spiUniqueConfiguration].con1 | 0x25;
        SSP2CON2 = 0x00;
        SSP2ADD = spi2_configuration[spiUniqueConfiguration].add | 0;
        
        SCK2_SetDigitalInput();
        return true;
    }
    return false;
}

// Full Duplex SPI Functions
uint8_t spi2_exchangeByte(uint8_t b)
{
    SSP2BUF = b;
    while(!PIR3bits.SSP2IF);
    PIR3bits.SSP2IF = 0;
    return SSP2BUF;
}

void spi2_exchangeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data = spi2_exchangeByte(*data );
        data++;
    }
}

// Half Duplex SPI Functions
void spi2_writeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        spi2_exchangeByte(*data++);
    }
}

void spi2_readBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = spi2_exchangeByte(0);
    }
}
