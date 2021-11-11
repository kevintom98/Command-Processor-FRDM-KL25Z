#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <MKL25Z4.H>


#define UART_OVERSAMPLE_RATE 	(16)
#define BUS_CLOCK 				(24e6)
#define SYS_CLOCK				(24e6)


//Parameters according to assignment
#define STOP_BITS               (2) // 1 : One Stop bit       | 2 : Two stop bits
#define DATA_SIZE				(0) // 0 : 8-bit mode         | 1 : for 9-bit mode
#define PARITY					(0) // 0 : Parity is disabled | 1 : Parity is enabled


void Init_UART0(uint32_t baud_rate);

#endif
