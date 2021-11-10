/*
 * hexdump.h
 *
 *  Created on: 09-Nov-2021
 *      Author: Kevin Tom, Kevin.Tom@colorado.edu
 */


#ifndef _HEXDUMP_H_
#define _HEXDUMP_H_


#include <stddef.h>
#include <stdint.h>

char int_to_hexchar(uint32_t x);
void hexdump(void *start, size_t len);


#endif //_HEXDUMP_H_



