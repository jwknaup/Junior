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
    char rxbuffer1[100];                 // UART receive buffer
    int rxindex1;                        // UART receive buffer index
    char rxbuffer2[100];                 // UART receive buffer
    int rxindex2;  
    
    double number;                      // floating-point number
       int numRows=0;
   int numCols=0;
    
   int i=1;
   int j =1;
   char c='A';
    
    
    uint8 ch1;                           // variable to hold received character
    uint8 ch2;
    
    // initialize and clear rxbuffer
    for( rxindex1 = 0; rxindex1 < 100; rxindex1++ ) {
        rxbuffer1[rxindex1] = 0u;
    }
    rxindex1 = 0;                        // initialize rxindex
        // initialize and clear rxbuffer
    for( rxindex2 = 0; rxindex2 < 100; rxindex2++ ) {
        rxbuffer2[rxindex2] = 0u;
    }
    rxindex2 = 0; 
   
    uart_Start();  // start UART
    
    // printf( "COM OPEN!\n" );
	uart_PutString( "COM OPEN!\n" );// display initialization string
	
    // printf( "Type a number: " );
    uart_PutString( "Type a number: " );
    
    // read string until the user presses return
    // scanf( "%s", rxbuffer );
    while( ch1 != '\r' ) {
        ch1 = uart_GetChar();        // get the next character
        
        if( ch1 != '\r' && ch1 != 0u ) {  // if the character is not a return or null
            rxbuffer1[rxindex1] = ch1;     // store it in the rxbuffer string
            rxindex1++;                  // increment the rxbuffer index
        }
    }

    uart_PutString( "Type a number: " );
       
    while( ch2 != '\r' ) {
        ch2 = uart_GetChar();        // get the next character
        
        if( ch2 != '\r' && ch2 != 0u ) {  // if the character is not a return or null
            rxbuffer2[rxindex2] = ch2;     // store it in the rxbuffer string
            rxindex2++;                  // increment the rxbuffer index
        }
    }
    uart_PutChar('\n');
    
    numRows = strtod(rxbuffer1,0);
    numCols = strtod(rxbuffer2, 0);
    
    // output the float as a string and store it in rxbuffer
    // NOTE: In order to properly output doubles, you must enable them in the compiler
    // See http://www.cypress.com/?id=4&rID=87354 for more details

   while(i <= numRows){
      while(j <= numCols){
         sprintf( rxbuffer1, "%d%c ", i, c );
         uart_PutString(rxbuffer1);
         j++;
         ++c;
      }
      i++;
      j=1;
      c='A';
   }
    //sprintf( rxbuffer, "%d%c ", i, c );
    
    // output the new string to the UART
    // printf( "\n%s\n", rxbuffer );
    uart_PutChar('\n');
    uart_PutChar('\n');
    
    return 0;
}

