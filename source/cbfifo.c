/*
 *	cbfifo.c - Circular buffer implementation
 *
 *	Author: Kevin Tom, keto9919@colorado.edu
 */


#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "cbfifo.h"
#include <MKL25Z4.h>


#define MAX_SIZE 256 //Max size of the circular buffer is 128 bytes


//Structure for the circular buffer
typedef struct cbfifo_struct
{
	uint16_t buf[MAX_SIZE];
	uint16_t head;
	uint16_t tail;
	uint16_t length;
	uint16_t full;
}cbfifo_t;


//Object of the structure
cbfifo_t q[INSTANCES];



/*
 * This function enqueue data into the buffer, up to 128 bytes.
 *
 * Parameters :
 *   buf - pointer to the data to be enqueued
 *   nbyte - number of bytes to be enqueued
 *
 * Returns :
 *   Number of bytes enqueued (size_t - variable).
 *   In case of error -1.
 *
 */
size_t cbfifo_enqueue(void *buf, size_t nbyte, inst ins)
{
	uint8_t a;
	size_t temp;

	uint32_t masking_state;

	// save current masking state
	masking_state = __get_PRIMASK();
	// disable interrupts
	__disable_irq();



	if(nbyte == 0) //Case when nbyte is 0
	{
		__set_PRIMASK(masking_state);
		return 0;
	}
	if(buf == NULL) //Case when *buf is NULL
	{
		__set_PRIMASK(masking_state);
		return -1;
	}
	if(nbyte > MAX_SIZE) //When nbyte>128 truncating it to 128
		nbyte = MAX_SIZE;
	if(q[ins].full == 1) //If buffer is full returning 0
	{
		__set_PRIMASK(masking_state);
		return 0;
	}


	temp = q[ins].length; //temp for calculating length difference

	if((q[ins].head == MAX_SIZE)) //Wrapping head around
		q[ins].head=0;


	for(int i = 0;i<nbyte;i++)
	{
		if(q[ins].full == 1) // Checking if full
			break;

		a = *(uint8_t *)(buf+i); // converting data in pointer location to uint_8
        q[ins].buf[q[ins].head]=a;        //Writing data into buffer

		(q[ins].head)++;  //Updating head
		(q[ins].length)++; //updating length

		if((q[ins].head == MAX_SIZE)) //Wrapping head around
			q[ins].head=0;
		if(q[ins].head == q[ins].tail)
			q[ins].full = 1;
	}

	__set_PRIMASK(masking_state);
	return (q[ins].length - temp);
}




/*
 * This function dequeue data into the buffer, up to 128 bytes.
 *
 * Parameters :
 *   buf - pointer to the destination
 *   nbyte - number of bytes to be dequeued
 *
 * Returns :
 *   Number of bytes dequeued (size_t - variable).
 *   In case of error -1.
 *
 */
size_t cbfifo_dequeue(void *buf, size_t nbyte, inst ins)
{
	uint16_t temp;
	temp = q[ins].length;

	uint32_t masking_state;

	// save current masking state
	masking_state = __get_PRIMASK();
	// disable interrupts
	__disable_irq();

	if(buf == NULL) // If buf == NULL error
	{
		__set_PRIMASK(masking_state);
		return -1;
	}
	if(nbyte == 0) //Case when nbyte is 0
	{
		__set_PRIMASK(masking_state);
		return 0;
	}
	if(nbyte > MAX_SIZE) //When nbyte>128 truncating it to 128
		nbyte = MAX_SIZE;

	if((q[ins].head==q[ins].tail) && (q[ins].full == 0)) // Buffer is empty
	{
		__set_PRIMASK(masking_state);
		return 0;
	}

	if(nbyte > q[ins].length) //truncating nbyte to available elements
		nbyte = q[ins].length;


	if(q[ins].length != 0)
	{
		if(nbyte > q[ins].length)  /*Case where nbyte is greater than length*/
		{
			for(int i=0;i<q[ins].length;i++)
			{
				if((q[ins].head==q[ins].tail) && (q[ins].full == 0))//Checking if buffer is empty
				{
					break;
				}
				*((uint8_t *)buf+i) = q[ins].buf[q[ins].tail];
				(q[ins].tail)++;   //updating tail (incrementing)
				(q[ins].length)--; //updating length (decrementing)
				if(q[ins].full == 1) //if a dequeue happens full flag should be set to 0
					q[ins].full=0;
				if(q[ins].tail == MAX_SIZE)  //tail wrapping around
					q[ins].tail = 0;
			}
			__set_PRIMASK(masking_state);
			return (temp - q[ins].length); //returning the difference in lengths
		}

		for( int i=0;i<nbyte;i++)
		{
			if((q[ins].head==q[ins].tail) && (q[ins].full == 0))//Checking if buffer is empty
				break;
			*((uint8_t *)buf+i) = q[ins].buf[q[ins].tail];
			(q[ins].tail)++;
			(q[ins].length)--;
			if(q[ins].full == 1)//if a dequeue happens full flag should be set to 0
				q[ins].full=0;
			if(q[ins].tail == MAX_SIZE) //tail wrapping around
				q[ins].tail = 0;
		}
		__set_PRIMASK(masking_state);
		return (temp - q[ins].length);//returning the difference in lengths
	}

	__set_PRIMASK(masking_state);
	return 0; //if control reaches here return 0
}




/*
 *This function returns the length of the buffer
 *
 * Parameter :
 *	None
 * Return :
 * 	length of the buffer (size_t)
 */
size_t cbfifo_length(inst ins)
{
	return q[ins].length;
}





/*
 *This function returns the capacity of the buffer
 *
 * Parameter :
 *	None
 * Return :
 * 	capacity of the buffer (size_t)
 */
size_t cbfifo_capacity(inst ins)
{
	return MAX_SIZE;
}


/* This function dumps characters in the buffer as
 *  char.
 * Parameter:
 *	None
 * Return:
 *	None
 *
 */
void cbfifo_dump(inst ins)
{
	for(int i =0;i<MAX_SIZE;i++)
		printf("%c",q[ins].buf[i]); //This is used for dumping data
}
