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

#define STRIDE            (16)
#define DUMP_MAX_SIZE     (640)




/* This converts integer input to hexadecimal character
 *
 *
 * Parameters:
 * 		uint32_t x - Number to be converted
 *
 * Returns:
 * 		char       - Hexadecimal equivalent
 * */
char int_to_hexchar(uint32_t x);





/* This function prints the hexdump starting from an address till the
 * given length.
 *
 *
 * Parameters:
 * 		int *start - Start address
 * 		size_t len - Total number of locations to be printed
 *
 * Returns:
 * 		None
 * */
void hexdump(int *start, size_t len);



#endif //_HEXDUMP_H_



