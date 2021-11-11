#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <MKL25Z4.H>


#define UART_OVERSAMPLE_RATE 	(16)
#define BUS_CLOCK 				(24e6)  //24Mhz
#define SYS_CLOCK				(24e6)


//Parameters according to assignment
#define STOP_BITS               (2) //Number of stop bits
#define DATA_SIZE				(0) //8-bit mode, set this to 1 for 9-bit mode
#define PARITY					(0) //Make it 1 for enabling parity


void Init_UART0(uint32_t baud_rate);

#endif
