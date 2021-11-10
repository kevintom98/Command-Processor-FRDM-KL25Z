#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <MKL25Z4.H>
#include "queue.h"
/***************************************************/


#define UART_OVERSAMPLE_RATE 	(16)
#define BUS_CLOCK 				(24e6)  //9446 in decimal //24Mhz
#define SYS_CLOCK				(24e6)  //18662 in decimal //48Mhz


//Paramters according to assignment
#define STOP_BITS               (2)
#define DATA_SIZE				(0) //8bit mode, set this to 1 for 9bit mode
#define PARITY					(0) //Make it 1 for enabling parity

void Init_UART0(uint32_t baud_rate);
//void UART0_Transmit_Poll(uint8_t data);
//uint8_t UART0_Receive_Poll(void);

//void Send_String_Poll(uint8_t * str);
//void Send_String(uint8_t * str);

//uint32_t Rx_Chars_Available(void);
//uint8_t	Get_Rx_Char(void);

extern Q_T TxQ, RxQ;

#endif
