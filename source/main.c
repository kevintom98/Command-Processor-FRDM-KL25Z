/*
 * main.c - application entry point
 * 
 * Author Howdy Pierce, howdy.pierce@colorado.edu
 */

#include "sysclock.h"
#include "UART.h"
#include "test_cbfifo.h"
#include "command_processor.h"


#define BAUD_RATE 38400


int main(void)
{

  //Calling the system clock initialization function
  sysclock_init();

  //Calling the UART initilazation function with BAUD_RATE
  Init_UART0(BAUD_RATE);

  //Calling the CBFIFO testing function
  test2_cbfifo();

  //Starting the command processor
  command_processor_start();

  return 0 ;
}
