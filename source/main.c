/*
 * main.c - application entry point
 * 
 * Author Howdy Pierce, howdy.pierce@colorado.edu
 */

#include <MKL25Z4.h>
#include <stdio.h>

#include "sysclock.h"
#include "cbfifo.h"
#include "UART.h"
#include "test_cbfifo.h"
#include "command_processor.h"


#define BAUD_RATE 38400


int main(void)
{

  //uint8_t buffer[80], c, * bp;

  char qw;


  sysclock_init();

  Init_UART0(BAUD_RATE);



  /*printf("\n\rInitialized both sysclock and UART!");
  printf("\n\rEnter a character: ");

  qw = getchar();

  printf("\n\n\rThe character you entered :%c",qw);*/



  //test_cbfifo();
  //test2_cbfifo();


  command_processor_start();



  //Send_String("\n\rHello, World!\n\r");

  	// Code listing 8.10, p. 234
  	/*while (1)
  	{
  		// Blocking receive
  		//while (Q_Size(&RxQ) == 0);
  		while(cbfifo_length(RX_Buffer)==0)
  			; // wait for character to arrive
  		//c = Q_Dequeue(&RxQ);
  		cbfifo_dequeue(&c, 1, RX_Buffer);

  		//if((size != 0) && (size != -1))
  			//c = *buf;


  		// Blocking transmit
  		sprintf((char *) buffer, "You pressed %c\n\r", c);
  		// enqueue string
  		bp = buffer;
  		while (*bp != '\0') {
  			// copy characters up to null terminator
  			//while (Q_Full(&TxQ))
  			while(cbfifo_is_full(TX_Buffer) == 1)
  				; // wait for space to open up
  			//Q_Enqueue(&TxQ, *bp);
  			cbfifo_enqueue(bp,1,TX_Buffer);

  			//if((size != 0) && (size != -1))
  				bp++;
  		}
  		// start transmitter if it isn't already running
  		if (!(UART0->C2 & UART0_C2_TIE_MASK))
  		{
  			UART0->C2 |= UART0_C2_TIE(1);
  		}
  	}*/
  return 0 ;
}
