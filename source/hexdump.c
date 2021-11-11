/*
 * hexdump.c
 *
 *  Created on: 09-Nov-2021
 *      Author: Kevin Tom, Kevin.Tom@colorado.edu
 */


#include "hexdump.h"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define STRIDE    (16)
#define DUMP_MAX_SIZE (640)







char int_to_hexchar(uint32_t x)
{
	if (x < 10)
		return ('0' + x);
	else
		return ('A' + (x - 10));
}


void hexdump(int *start, size_t len)
{
	uint8_t *buf = (uint8_t*) start;
	int start_addr = (int)start;


	if(len > DUMP_MAX_SIZE)
	{
		len = DUMP_MAX_SIZE;
	}

	printf("\n\r");

	for(int i =0;i<len;i+=STRIDE)
	{
		    printf("%04x_%04x",(start_addr & (0xFFFF0000)),(start_addr & (0x0000FFFF)));
			printf("  ");

			for (int j=0; (j < STRIDE) && (i+j < len); j++)
			{
			  printf("%c",int_to_hexchar((buf[i+j]) >> 4));
			  printf("%c",int_to_hexchar((buf[i+j]) & 0x0f));
			  printf(" ");
			}

			start_addr += STRIDE;

			if(i < (len-1))
			{
				printf("\r");
				printf("\n");
			}
	  }
}




