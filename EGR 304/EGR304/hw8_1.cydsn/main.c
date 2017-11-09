/******************************************************************************
* Project Name		: USB-UART-EGR
* File Name			: main.c
* Version 			: 1.1 (Updated by Dr. Jordan)
* Device Used		: CY8C4245AXI-483
* Software Used		: PSoC Creator 3.0 SP1
* Compiler    		: ARMGCC 4.4.1
* Related Hardware	: CY8CKIT-042 PSoC 4 Pioneer Kit 
*
*
******************************************************************************
*                           THEORY OF OPERATION
* This project demonstrates UART communication over the kit USB-UART Bridge. 
* The project uses the SCB based UART component which stores the users input in an
* array. when the user press the return key the PSoC will send what has be in the 
* array, then clears the array and sets the pointer back to o.
* 
* UART is configured with
* UART Basic
* 	Mode: Standard
* 	Direction: TX+RX
* 	Baud rate (kbps): 9600
* 	Data bits: 8 bits
* 	Parity: None
* 	Stop bits: 1 bit
* 	Physical connections needed:
* 	Jumper between P0[5] and PSoC 5LP Header J8 P12[6]
* UART Advanced
* 	RX buffer size: 8
* 	TX buffer size: 8
* 	Interrupt: None
*
* Physical Connetion
* Connect jumper wire from the UART RX (P0[4]) of PSoC 4 to J8_10 (P12[7]) of PSoC 5LP
* Connect jumper wire from the UART TX (P0[5]) of PSoC 4 to J8_9 (P12[6]) of PSoC 5LP
* ******************************************************************************/ 
#include <project.h>
#include <stdio.h>
#include <stdlib.h>     // contains strtod(), which converts an ASCII string to a double
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char rxbuffer[100];                 // UART receive buffer
    int rxindex;                        // UART receive buffer index
    
    double number;                      // floating-point number
    
    uint8 ch;                           // variable to hold received character
   
    // initialize and clear rxbuffer
    for( rxindex = 0; rxindex < 100; rxindex++ ) {
        rxbuffer[rxindex] = 0u;
    }
    rxindex = 0;                        // initialize rxindex
   
    uart_Start();  // start UART
    
    // printf( "COM OPEN!\n" );
	uart_PutString( "COM OPEN!\n" );// display initialization string
	
    // printf( "Type a number: " );
    uart_PutString( "Type a number: " );
    
    // read string until the user presses return
    // scanf( "%s", rxbuffer );
    while( ch != '\r' ) {
        ch = uart_GetChar();        // get the next character
        
        if( ch != '\r' && ch != 0u ) {  // if the character is not a return or null
            rxbuffer[rxindex] = ch;     // store it in the rxbuffer string
            rxindex++;                  // increment the rxbuffer index
        }
    }
    
    // output the received string to the UART
    // printf( "\n%s\n", rxbuffer );
    uart_PutChar('\n');
    uart_PutString(rxbuffer);
    uart_PutChar('\n');

    // convert the received string to a double (floating-point number)
    //number = strtod( rxbuffer, 0 );

   bool hasDigit = false;
   char passCode[50] = "";
   int valid = 0;

   strcpy(passCode, rxbuffer);

   /* Your solution goes here  */
   for(int i=0; i<50;i++){
      if(isdigit(passCode[i]))
         hasDigit = true;
   }

    // initialize and clear rxbuffer (good practice to avoid bugs)
    for( rxindex = 0; rxindex < 100; rxindex++ ) {
        rxbuffer[rxindex] = 0u;
    }
    rxindex = 0;        // initialize rxindex
    
    // output the float as a string and store it in rxbuffer
    // NOTE: In order to properly output doubles, you must enable them in the compiler
    // See http://www.cypress.com/?id=4&rID=87354 for more details
   if (hasDigit) {
      printf("Has a digit.\n");
   }
   else {
      printf("Has no digit.\n");
   }
    
    // output the new string to the UART
    // printf( "\n%s\n", rxbuffer );
    uart_PutChar('\n');
//    uart_PutString(rxbuffer);
//    uart_PutChar('\n');
    
    return 0;
}

