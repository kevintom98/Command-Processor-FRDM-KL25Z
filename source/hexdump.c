/*
 * hexdump.c
 *
 *  Created on: 09-Nov-2021
 *      Author: Kevin Tom, Kevin.Tom@colorado.edu
 */


#include "hexdump.h"

#define STRIDE    (16)
#define MAX_SIZE (640)


#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>




char int_to_hexchar(uint32_t x)
{
	if (x >=0 && x < 10)
		return '0' + x;
	else if (x >= 10 && x < 16)
		return 'A' + x - 10;
	else
		return '-';
}


void hexdump(void *start, size_t len)
{

	uint16_t *buf = (uint16_t*)start;
	uint16_t *max = (uint16_t*)start + len;

	if(len > MAX_SIZE)
	{
		len = MAX_SIZE;
	}

	printf("\n\r");
	  while(buf < max )
	  {
		    printf("%c",int_to_hexchar(((uint32_t)(buf) & 0xF0000000) >> 28));
			printf("%c",int_to_hexchar(((uint32_t)(buf) & 0x0F000000) >> 24));
			printf("%c",int_to_hexchar(((uint32_t)(buf) & 0x00F00000) >> 20));
			printf("%c",int_to_hexchar(((uint32_t)(buf) & 0x000F0000) >> 16));
			printf("%c",'_');
			printf("%c",int_to_hexchar(((uint32_t)(buf) & 0x0000F000) >> 12));
			printf("%c",int_to_hexchar(((uint32_t)(buf) & 0x00000F00) >>  8));
			printf("%c",int_to_hexchar(((uint32_t)(buf) & 0x000000F0) >>  4));
			printf("%c",int_to_hexchar((uint32_t)(buf) & 0x0000000F));
			printf(" ");
			printf(" ");
			for (int j=0; j < STRIDE && buf+j < max; j++)
			{
			  printf("%c",int_to_hexchar(buf[j] >> 4));
			  printf("%c",int_to_hexchar(buf[j] & 0x0F));
			  printf(" ");
			}
			buf += STRIDE;
			printf("\r");
			printf("\n");

	  }
}




