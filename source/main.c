/*
 * main.c - application entry point
 * 
 * Author Howdy Pierce, howdy.pierce@colorado.edu
 */


#include <stdio.h>

#include "sysclock.h"
#include "cbfifo.h"
#include "UART.h"
#include "test_cbfifo.h"
#include "command_processor.h"


#define BAUD_RATE 38400


int main(void)
{

  sysclock_init();

  Init_UART0(BAUD_RATE);

  test2_cbfifo();


  //test_cbfifo();



  command_processor_start();


  return 0 ;
}
