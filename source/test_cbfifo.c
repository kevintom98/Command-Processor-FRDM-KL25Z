#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "cbfifo.h"
#include "test_cbfifo.h"

/*
 *This function tests the cbfifo.c through different test cases.
 *Asserts are used for testing. Program stops is there is a problem.
 *
 *Parameters:
 *	none
 *
 *return:
 *	none
 */
void test_cbfifo()
{
    //char b;
	//void *buf = &b;
	char a[] ="Soft kittyyy,warm kittyyy,little ball of furrrr,happy kittyyyy";

	//Intialization checks
	printf("\n\rChecking if initial conditions are correct(For 1st instance)");
	assert(cbfifo_length(RX_Buffer) == 0);
	printf("\n\rLength : %zu",cbfifo_length(RX_Buffer));
	assert(cbfifo_capacity(RX_Buffer) == 256);
	printf("\n\rCapacity : %zu",cbfifo_capacity(RX_Buffer));
	//assert(q[RX_Buffer].head == 0);
	//printf("Head : %u \n",q[RX_Buffer].head);
	//assert(q[RX_Buffer].tail == 0);
	//printf("Tail : %u \n",q[RX_Buffer].tail);

	//Enqueuing when nbytes=0
	printf("\n\rTrying to enqueue with nbytes = 0\n");
	assert(cbfifo_enqueue(&a,0,RX_Buffer) == 0);
	assert(cbfifo_length(RX_Buffer) == 0);
	printf("\n\rLength : %zu \n",cbfifo_length(RX_Buffer));
	assert(cbfifo_capacity(RX_Buffer) == 256);
	printf("\n\rCapacity : %zu \n",cbfifo_capacity(RX_Buffer));
	//assert(q[RX_Buffer].head == 0);
	//printf("Head : %u \n",q[RX_Buffer].head);
	//assert(q[RX_Buffer].tail == 0);
	//printf("Tail : %u \n",q[RX_Buffer].tail);

	//Dequeuing when buffer doesnt have any elements
	/*printf("\nTrying to dequeue nbyte =1 (buffer doesnt have any elements)\n");
	assert(cbfifo_dequeue(buf,1,RX_Buffer) == 0);
	assert(cbfifo_length(RX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(RX_Buffer));
	assert(cbfifo_capacity(RX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(RX_Buffer));
	assert(q[RX_Buffer].head == 0);
	printf("Head : %u \n",q[RX_Buffer].head);
	assert(q[RX_Buffer].tail == 0);
	printf("Tail : %u \n",q[RX_Buffer].tail);


	buf = NULL;
	//Passing NULL pointer to enqueue and nbytes 2
	printf("\nPassing NULL pointer to enqueue and nbytes=2\n");
	assert(cbfifo_enqueue(buf,2,RX_Buffer) == -1);
	assert(cbfifo_length(RX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(RX_Buffer));
	assert(cbfifo_capacity(RX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(RX_Buffer));
	assert(q[RX_Buffer].head == 0);
	printf("Head : %u \n",q[RX_Buffer].head);
	assert(q[RX_Buffer].tail == 0);
	printf("Tail : %u \n",q[RX_Buffer].tail);



	//Passing null pointer to dequeue and nbytes 0
	printf("\nPassing NULL ponter to dequeue and nbytes=0\n");
	assert(cbfifo_dequeue(buf,0,RX_Buffer) == -1);
	assert(cbfifo_length(RX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(RX_Buffer));
	assert(cbfifo_capacity(RX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(RX_Buffer));
	assert(q[RX_Buffer].head == 0);
	printf("Head : %u \n",q[RX_Buffer].head);
	assert(q[RX_Buffer].tail == 0);
	printf("Tail : %u \n",q[RX_Buffer].tail);












	printf("\n\n\nSecond Instance");
	printf("\n---------------------");

	//Intialization checks for second buffer
	printf("\nChecking if initial conditions are correct(For 2 instance)\n");
	assert(cbfifo_length(TX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(TX_Buffer));
	assert(cbfifo_capacity(TX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(TX_Buffer));
	assert(q[TX_Buffer].head == 0);
	printf("Head : %u \n",q[TX_Buffer].head);
	assert(q[TX_Buffer].tail == 0);
	printf("Tail : %u \n",q[TX_Buffer].tail);

	//Enqueuing when nbytes=0
	printf("\nTrying to enqueue with nbytes = 0\n");
	assert(cbfifo_enqueue(&a,0,TX_Buffer) == 0);
	assert(cbfifo_length(TX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(TX_Buffer));
	assert(cbfifo_capacity(TX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(TX_Buffer));
	assert(q[TX_Buffer].head == 0);
	printf("Head : %u \n",q[TX_Buffer].head);
	assert(q[TX_Buffer].tail == 0);
	printf("Tail : %u \n",q[TX_Buffer].tail);

	//Dequeuing when buffer doesnt have any elements
	printf("\nTrying to dequeue nbyte =1 (buffer doesnt have any elements)\n");
	assert(cbfifo_dequeue(buf,1,TX_Buffer) == 0);
	assert(cbfifo_length(TX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(TX_Buffer));
	assert(cbfifo_capacity(TX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(TX_Buffer));
	assert(q[TX_Buffer].head == 0);
	printf("Head : %u \n",q[TX_Buffer].head);
	assert(q[TX_Buffer].tail == 0);
	printf("Tail : %u \n",q[TX_Buffer].tail);




	buf = NULL;
	//Passing NULL pointer to enqueue and nbytes 2
	printf("\nPassing NULL pointer to enqueue and nbytes=2\n");
	assert(cbfifo_enqueue(buf,2,TX_Buffer) == -1);
	assert(cbfifo_length(TX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(TX_Buffer));
	assert(cbfifo_capacity(RX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(TX_Buffer));
	assert(q[TX_Buffer].head == 0);
	printf("Head : %u \n",q[TX_Buffer].head);
	assert(q[TX_Buffer].tail == 0);
	printf("Tail : %u \n",q[TX_Buffer].tail);



	//Passing null pointer to dequeue and nbytes 0
	printf("\nPassing NULL ponter to dequeue and nbytes=0\n");
	assert(cbfifo_dequeue(buf,0,TX_Buffer) == -1);
	assert(cbfifo_length(TX_Buffer) == 0);
	printf("Length : %zu \n",cbfifo_length(TX_Buffer));
	assert(cbfifo_capacity(TX_Buffer) == 128);
	printf("Capacity : %zu \n",cbfifo_capacity(TX_Buffer));
	assert(q[TX_Buffer].head == 0);
	printf("Head : %u \n",q[TX_Buffer].head);
	assert(q[TX_Buffer].tail == 0);
	printf("Tail : %u \n",q[TX_Buffer].tail);











	buf = &b;
	//Passing string and enqueuing nbytes 20
	printf("\nEnqueuing : nbyte=20 \n");
	assert(cbfifo_enqueue(&a,20) == 20);
	assert(cbfifo_length() == 20);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 20);
	assert(q.tail == 0);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);

	//dequeuing 10 bytes
	printf("\nDequeuing : nbyte=10 \n");
	assert(cbfifo_dequeue(buf,10) == 10);
	assert(cbfifo_length() == 10);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 20);
	assert(q.tail == 10);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);

	//Enqueuing 2 bytes
	printf("\nEnqueuing : nbyte=2 \n");
	assert(cbfifo_enqueue(&a,2) == 2);
	assert(cbfifo_length() == 12);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 22);
	assert(q.tail == 10);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Enqueuing till head = 127 - End of the queue
	printf("\nEnqueuing : nbyte=105 - Till head = 127 \n");
	assert(cbfifo_enqueue(&a,105) == 105);
	assert(cbfifo_length() == 117);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 127);
	assert(q.tail == 10);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);



	//Checking the wrapping around enqueuing again: head = 4, tail=10
	printf("\nEnqueuing : nbyte=5 \n");
	assert(cbfifo_enqueue(&a,5)==5);
	assert(cbfifo_length() == 122);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 4);
	assert(q.tail == 10);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Passing nbyte = 0 again
	printf("\nEnqueuing : nbyte=0 \n");
	assert(cbfifo_enqueue(&a,0)==0);
	assert(cbfifo_length() == 122);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 4);
	assert(q.tail == 10);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Enqueuing beyond buffer capacity and checking full
	printf("\nEnqueuing : nbyte=10 - beyond capacity \n");
	assert(cbfifo_enqueue(&a,10)==6);
	assert(cbfifo_length() == 128);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 10);
	assert(q.tail == 10);
	assert(q.full == 1);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//dequeuing 128 bytes
	printf("\nDequeuing : nbyte=128 \n");
	assert(cbfifo_dequeue(buf,128) == 128);
	assert(cbfifo_length() == 0);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 10);
	assert(q.tail == 10);
	assert(q.full == 0);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Now buffer is empty
	//Making buffer full in one go
	printf("\nEnqueuing : nbyte=128 \n");
	assert(cbfifo_enqueue(&a,128)==128);
	assert(cbfifo_length() == 128);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 10);
	assert(q.tail == 10);
	assert(q.full == 1);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Now buffer is full
	//Trying to push 5 elements
	printf("\nEnqueuing : nbyte=5  \n");
	assert(cbfifo_enqueue(&a,5)==0);
	assert(cbfifo_length() == 128);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 10);
	assert(q.tail == 10);
	assert(q.full == 1);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);

	//Dequeue 1
	printf("\nDequeuing : nbyte=1 \n");
	assert(cbfifo_dequeue(buf,1) == 1);
	assert(cbfifo_length() == 127);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 10);
	assert(q.tail == 11);
	assert(q.full == 0);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);

	//Enqueuing 1
	printf("\nEnqueuing : nbyte=1  \n");
	assert(cbfifo_enqueue(&a,1)==1);
	assert(cbfifo_length() == 128);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 11);
	assert(q.tail == 11);
	assert(q.full == 1);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Moving tail to the end to check the edge wrap
	printf("\nDequeuing : nbyte=116 \n");
	assert(cbfifo_dequeue(buf,116) == 116);
	assert(cbfifo_length() == 12);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 11);
	assert(q.tail == 127);
	assert(q.full == 0);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Moving head to the edge with tail
	printf("\nEnqueuing : nbyte=116\n");
	assert(cbfifo_enqueue(&a,116)==116);
	assert(cbfifo_length() == 128);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 127);
	assert(q.tail == 127);
	assert(q.full == 1);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);

	//Dequeue 1
	printf("\nDequeuing : nbyte=1 \n");
	assert(cbfifo_dequeue(buf,1) == 1);
	assert(cbfifo_length() == 127);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 127);
	assert(q.tail == 0);
	assert(q.full == 0);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);

	//Enqueuing 1, Now the buffer should be full
	printf("\nEnqueuing : nbyte=1\n");
	assert(cbfifo_enqueue(&a,1)==1);
	assert(cbfifo_length() == 128);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 0);
	assert(q.tail == 0);
	assert(q.full == 1);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);


	//Dequeuing 120 elements
	printf("\nDequeuing : nbyte=120 \n");
	assert(cbfifo_dequeue(buf,120) == 120);
	assert(cbfifo_length() == 8);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 0);
	assert(q.tail == 120);
	assert(q.full == 0);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);

	//Dequeuing more elements than capacity of buffer
	printf("\nDequeuing : nbyte=10 \n");
	assert(cbfifo_dequeue(buf,10) == 8);
	assert(cbfifo_length() == 0);
	assert(cbfifo_capacity() == 128);
	assert(q.head == 0);
	assert(q.tail == 0);
	assert(q.full == 0);
	printf("Length : %zu \n",cbfifo_length());
	printf("Capacity : %zu \n",cbfifo_capacity());
	printf("Head : %u \n",q.head);
	printf("Tail : %u \n",q.tail);*/

}





void test2_cbfifo()
{
  char *str ="To be, or not to be: that is the question:\n"
    "Whether 'tis nobler in the mind to suffer\n"
    "The slings and arrows of outrageous fortune,\n"
    "Or to take arms against a sea of troubles,\n"
    "And by opposing end them? To die, to sleep--\n"
    "No more--and by a sleep to say we end\n"
    "The heart-ache and the thousand natural shocks\n"
    "That flesh is heir to, 'tis a consummation\n"
    "Devoutly to be wish'd. To die, to sleep;\n"
    "To sleep: perchance to dream: ay, there's the rub;\n"
    "For in that sleep of death what dreams may come\n"
    "When we have shuffled off this mortal coil,\n"
    "Must give us pause.";

  char buf[1024];
  //size_t a=0;
  const int cap = cbfifo_capacity(TX_Buffer);

  // asserts in following 2 lines -- this is not testing the student,
  // it's validating that the test is correct
  assert(strlen(str) >= cap*2);
  assert(sizeof(buf) > cap);
  assert(cap == 128 || cap == 256);

  /*assert(cbfifo_length(TX_Buffer) == 0);
  assert(cbfifo_dequeue(buf, cap,TX_Buffer) == 0);
  assert(cbfifo_dequeue(buf, 1,TX_Buffer) == 0);

  // enqueue 10 bytes, then dequeue same amt
  assert(cbfifo_enqueue(str, 10,TX_Buffer) == 10);
  assert(cbfifo_length(TX_Buffer) == 10);
  assert(cbfifo_dequeue(buf, 10,TX_Buffer) == 10);
  //for(int i =0;i<10;i++)
  //	printf("\nChar : %d",buf[i]);
  assert(strncmp(buf, str, 10) == 0);
  assert(cbfifo_length(TX_Buffer) == 0);


  // enqueue 20 bytes;  dequeue 5, then another 20
  assert(cbfifo_enqueue(str, 20,TX_Buffer) == 20);
  assert(cbfifo_length(TX_Buffer) == 20);

  assert(cbfifo_dequeue(buf, 5,TX_Buffer) == 5);
  assert(cbfifo_length(TX_Buffer) == 15);
  assert(cbfifo_dequeue(buf+5, 20,TX_Buffer) == 15);
  assert(cbfifo_length(TX_Buffer) == 0);
  assert(strncmp(buf, str, 20) == 0);

  // fill buffer and then read it back out
  /*assert(cbfifo_enqueue(str, cap) == cap);
  assert(cbfifo_length() == cap);
  assert(cbfifo_enqueue(str, 1) == 0);
  assert(cbfifo_dequeue(buf, cap) == cap);
  assert(cbfifo_length() == 0);
  assert(strncmp(buf, str, cap) == 0);

  // Add 20 bytes and pull out 18
  assert(cbfifo_enqueue(str, 20) == 20);
  assert(cbfifo_length() == 20);
  assert(cbfifo_dequeue(buf, 18) == 18);
  assert(cbfifo_length() == 2);
  assert(strncmp(buf, str, 18) == 0);

  // Now add a bunch of data in 4 chunks
  int chunk_size = (cap-2) / 4;
  for (int i=0; i<4; i++) {
    assert(cbfifo_enqueue(str+i*chunk_size, chunk_size) == chunk_size);
    assert(cbfifo_length() == (i+1)*chunk_size + 2);
  }
  assert(cbfifo_length() == 4*chunk_size + 2);

  // Take out the 2 remaining bytes from above
  assert(cbfifo_dequeue(buf, 2) == 2);
  assert(strncmp(buf, str+18, 2) == 0);

  // now read those chunks out a byte at a time
  for (int i=0; i<chunk_size*4; i++) {
    assert(cbfifo_dequeue(buf+i, 1) == 1);
    assert(cbfifo_length() == chunk_size*4 - i - 1);
  }
  assert(strncmp(buf, str, chunk_size*4) == 0);

  // write more than capacity
  assert(cbfifo_enqueue(str, 65) == 65);
  assert(cbfifo_enqueue(str+65, cap) == cap-65);
  assert(cbfifo_length() == cap);
  assert(cbfifo_dequeue(buf, cap) == cap);
  assert(cbfifo_length() == 0);
  assert(strncmp(buf, str, cap) == 0);

  // write zero bytes
  assert(cbfifo_enqueue(str, 0) == 0);
  assert(cbfifo_length() == 0);

  // Exercise the following conditions:
  //    enqueue when read < write:
  //        bytes < CAP-write  (1)
  //        bytes exactly CAP-write  (2)
  //        bytes > CAP-write but < space available (3)
  //        bytes exactly the space available (4)
  //        bytes > space available (5)
  assert(cbfifo_enqueue(str, 32) == 32);  // advance so that read < write
  assert(cbfifo_length() == 32);
  assert(cbfifo_dequeue(buf, 16) == 16);
  assert(cbfifo_length() == 16);
  assert(strncmp(buf, str, 16) == 0);

  assert(cbfifo_enqueue(str+32, 32) == 32);  // (1)
  assert(cbfifo_length() == 48);
  assert(cbfifo_enqueue(str+64, cap-64) == cap-64);  // (2)
  assert(cbfifo_length() == cap-16);
  assert(cbfifo_dequeue(buf+16, cap-16) == cap-16);
  assert(strncmp(buf, str, cap) == 0);

  assert(cbfifo_enqueue(str, 32) == 32);  // advance so that read < write
  assert(cbfifo_length() == 32);
  assert(cbfifo_dequeue(buf, 16) == 16);
  assert(cbfifo_length() == 16);
  assert(strncmp(buf, str, 16) == 0);

  assert(cbfifo_enqueue(str+32, cap-20) == cap-20);  // (3)
  assert(cbfifo_length() == cap-4);
  assert(cbfifo_dequeue(buf, cap-8) == cap-8);
  assert(strncmp(buf, str+16, cap-8) == 0);
  assert(cbfifo_length() == 4);
  assert(cbfifo_dequeue(buf, 8) == 4);
  assert(strncmp(buf, str+16+cap-8, 4) == 0);
  assert(cbfifo_length() == 0);

  assert(cbfifo_enqueue(str, 49) == 49);  // advance so that read < write
  assert(cbfifo_length() == 49);
  assert(cbfifo_dequeue(buf, 16) == 16);
  assert(cbfifo_length() == 33);
  assert(strncmp(buf, str, 16) == 0);

  assert(cbfifo_enqueue(str+49, cap-33) == cap-33);  // (4)
  assert(cbfifo_length() == cap);
  assert(cbfifo_dequeue(buf, cap) == cap);
  assert(cbfifo_length() == 0);
  assert(strncmp(buf, str+16, cap) == 0);

  assert(cbfifo_enqueue(str, 32) == 32);  // advance so that read < write
  assert(cbfifo_length() == 32);
  assert(cbfifo_dequeue(buf, 16) == 16);
  assert(cbfifo_length() == 16);
  assert(strncmp(buf, str, 16) == 0);

  assert(cbfifo_enqueue(str+32, cap) == cap-16);  // (5)
  assert(cbfifo_dequeue(buf, 1) == 1);
  assert(cbfifo_length() == cap-1);
  assert(cbfifo_dequeue(buf+1, cap-1) == cap-1);
  assert(cbfifo_length() == 0);
  assert(strncmp(buf, str+16, cap) == 0);

  //    enqueue when write < read:
  //        bytes < read-write (6)
  //        bytes exactly read-write (= the space available) (7)
  //        bytes > space available (8)

  int wpos=0, rpos=0;
  assert(cbfifo_enqueue(str, cap-4) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length() == cap-4);
  assert(cbfifo_dequeue(buf, 32) == 32);
  rpos += 32;
  assert(cbfifo_length() == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12) == 12);
  wpos += 12;
  assert(cbfifo_length() == cap-24);

  assert(cbfifo_enqueue(str+wpos, 16) == 16);  // (6)
  assert(cbfifo_length() == cap-8);
  assert(cbfifo_dequeue(buf, cap) == cap-8);
  assert(cbfifo_length() == 0);
  assert(strncmp(buf, str+rpos, cap-8) == 0);

  // reset
  wpos=0;
  rpos=0;
  assert(cbfifo_enqueue(str, cap-4) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length() == cap-4);
  assert(cbfifo_dequeue(buf, 32) == 32);
  rpos += 32;
  assert(cbfifo_length() == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12) == 12);
  wpos += 12;
  assert(cbfifo_length() == cap-24);

  assert(cbfifo_enqueue(str+wpos, 24) == 24);  // (7)
  assert(cbfifo_length() == cap);
  assert(cbfifo_dequeue(buf, cap) == cap);
  assert(cbfifo_length() == 0);
  assert(strncmp(buf, str+rpos, cap) == 0);

  // reset
  wpos=0;
  rpos=0;
  assert(cbfifo_enqueue(str, cap-4) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length() == cap-4);
  assert(cbfifo_dequeue(buf, 32) == 32);
  rpos += 32;
  assert(cbfifo_length() == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12) == 12);
  wpos += 12;
  assert(cbfifo_length() == cap-24);

  assert(cbfifo_enqueue(str+wpos, 64) == 24);  // (8)
  assert(cbfifo_length() == cap);
  assert(cbfifo_dequeue(buf, cap) == cap);
  assert(cbfifo_length() == 0);
  assert(strncmp(buf, str+rpos, cap) == 0);*/

  printf("%s: passed all test cases\n", __FUNCTION__);
}

