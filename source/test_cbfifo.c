#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "cbfifo.h"




/*
 *This function test2s the cbfifo.c through different test2 cases.
 *Asserts are used for test2ing. Program stops is there is a problem.
 *
 *Parameters:
 *	none
 *
 *return:
 *	none
 */
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
  const int cap = cbfifo_capacity(test1);



  // asserts in following 2 lines -- this is not test2ing the student,
  // it's validating that the test2 is correct
  assert(strlen(str) >= cap*2);
  assert(sizeof(buf) > cap);
  assert(cap == 256 || cap == 127);



  printf("\n\rTesting CBFIFO");
  printf("\n\r---------------");


  assert(cbfifo_length(test1) == 0);
  assert(cbfifo_dequeue(buf, cap,test1) == 0);
  assert(cbfifo_dequeue(buf, 1,test1) == 0);

  assert(cbfifo_length(test2) == 0);
  assert(cbfifo_dequeue(buf, cap,test2) == 0);
  assert(cbfifo_dequeue(buf, 1,test2) == 0);

  // enqueue 10 bytes, then dequeue same amt
  assert(cbfifo_enqueue(str, 10,test1) == 10);
  assert(cbfifo_length(test1) == 10);
  assert(cbfifo_dequeue(buf, 10,test1) == 10);
  assert(strncmp(buf, str, 10) == 0);
  assert(cbfifo_length(test1) == 0);



   // enqueue 10 bytes, then dequeue same amt
  assert(cbfifo_enqueue(str, 10,test2) == 10);
  assert(cbfifo_length(test2) == 10);
  assert(cbfifo_dequeue(buf, 10,test2) == 10);
  assert(strncmp(buf, str, 10) == 0);
  assert(cbfifo_length(test2) == 0);
  printf("\n\rTest 1 passed");



  // enqueue 20 bytes;  dequeue 5, then another 20
  assert(cbfifo_enqueue(str, 20,test1) == 20);
  assert(cbfifo_length(test1) == 20);

   // enqueue 20 bytes;  dequeue 5, then another 20
  assert(cbfifo_enqueue(str, 20,test2) == 20);
  assert(cbfifo_length(test2) == 20);
  printf("\n\rTest 2 passed");


  /*printf("\n\r RX:");
  cbfifo_dump(test1);
  printf("\n\r");

  printf("\n\r TX:");
  cbfifo_dump(test2);
  printf("\n\r");*/



  assert(cbfifo_dequeue(buf, 5, test1) == 5);
  assert(cbfifo_length(test1) == 15);
  assert(cbfifo_dequeue(buf+5, 20,test1) == 15);
  assert(cbfifo_length(test1) == 0);
  assert(strncmp(buf, str, 20) == 0);

  assert(cbfifo_dequeue(buf, 5, test2) == 5);
  assert(cbfifo_length(test2) == 15);
  assert(cbfifo_dequeue(buf+5, 20,test2) == 15);
  assert(cbfifo_length(test2) == 0);
  assert(strncmp(buf, str, 20) == 0);
  printf("\n\rTest 3 passed");

  // fill buffer and then read it back out
  assert(cbfifo_enqueue(str, cap, test1) == cap);
  assert(cbfifo_length(test1) == cap);
  assert(cbfifo_enqueue(str, 1,test1) == 0);
  assert(cbfifo_dequeue(buf, cap,test1) == cap);
  assert(cbfifo_length(test1) == 0);
  assert(strncmp(buf, str, cap) == 0);

  // Add 20 bytes and pull out 18
  assert(cbfifo_enqueue(str, 20,test1) == 20);
  assert(cbfifo_length(test1) == 20);
  assert(cbfifo_dequeue(buf, 18,test1) == 18);
  assert(cbfifo_length(test1) == 2);
  assert(strncmp(buf, str, 18) == 0);


  // fill buffer and then read it back out
  assert(cbfifo_enqueue(str, cap, test2) == cap);
  assert(cbfifo_length(test2) == cap);
  assert(cbfifo_enqueue(str, 1,test2) == 0);
  assert(cbfifo_dequeue(buf, cap,test2) == cap);
  assert(cbfifo_length(test2) == 0);
  assert(strncmp(buf, str, cap) == 0);

  // Add 20 bytes and pull out 18
  assert(cbfifo_enqueue(str, 20,test2) == 20);
  assert(cbfifo_length(test2) == 20);
  assert(cbfifo_dequeue(buf, 18,test2) == 18);
  assert(cbfifo_length(test2) == 2);
  assert(strncmp(buf, str, 18) == 0);
  printf("\n\rTest 4 passed");



  // Now add a bunch of data in 4 chunks
  int chunk_size = (cap-2) / 4;
  for (int i=0; i<4; i++) {
    assert(cbfifo_enqueue(str+i*chunk_size, chunk_size,test1) == chunk_size);
    assert(cbfifo_length(test1) == (i+1)*chunk_size + 2);
  }
  assert(cbfifo_length(test1) == 4*chunk_size + 2);


  // Now add a bunch of data in 4 chunks
  chunk_size = (cap-2) / 4;
  for (int i=0; i<4; i++) {
    assert(cbfifo_enqueue(str+i*chunk_size, chunk_size,test2) == chunk_size);
    assert(cbfifo_length(test2) == (i+1)*chunk_size + 2);
  }
  assert(cbfifo_length(test2) == 4*chunk_size + 2);

  printf("\n\rTest 5 passed");





  // Take out the 2 remaining bytes from above
  assert(cbfifo_dequeue(buf, 2, test1) == 2);
  assert(strncmp(buf, str+18, 2) == 0);

  // Take out the 2 remaining bytes from above
  assert(cbfifo_dequeue(buf, 2, test2) == 2);
  assert(strncmp(buf, str+18, 2) == 0);
  printf("\n\rTest 6 passed");




  // now read those chunks out a byte at a time
  for (int i=0; i<chunk_size*4; i++) {
    assert(cbfifo_dequeue(buf+i, 1,test1) == 1);
    assert(cbfifo_length(test1) == chunk_size*4 - i - 1);
  }
  assert(strncmp(buf, str, chunk_size*4) == 0);

  // now read those chunks out a byte at a time
  for (int i=0; i<chunk_size*4; i++) {
    assert(cbfifo_dequeue(buf+i, 1,test2) == 1);
    assert(cbfifo_length(test2) == chunk_size*4 - i - 1);
  }
  assert(strncmp(buf, str, chunk_size*4) == 0);
  printf("\n\rTest 7 passed");




  // write more than capacity
  assert(cbfifo_enqueue(str, 65, test1) == 65);
  assert(cbfifo_enqueue(str+65, cap,test1) == (cap-65));
  assert(cbfifo_length(test1) == cap);
  assert(cbfifo_dequeue(buf, cap,test1) == cap);
  assert(cbfifo_length(test1) == 0);
  assert(strncmp(buf, str, cap) == 0);

  // write more than capacity
  assert(cbfifo_enqueue(str, 65, test2) == 65);
  assert(cbfifo_enqueue(str+65, cap,test2) == (cap-65));
  assert(cbfifo_length(test2) == cap);
  assert(cbfifo_dequeue(buf, cap,test2) == cap);
  assert(cbfifo_length(test2) == 0);
  assert(strncmp(buf, str, cap) == 0);
   printf("\n\rTest 8 passed");




  // write zero bytes
  assert(cbfifo_enqueue(str, 0, test1) == 0);
  assert(cbfifo_length(test1) == 0);

    // write zero bytes
  assert(cbfifo_enqueue(str, 0, test2) == 0);
  assert(cbfifo_length(test2) == 0);
   printf("\n\rTest 9 passed");

  // Exercise the following conditions:
  //    enqueue when read < write:
  //        bytes < CAP-write  (1)
  //        bytes exactly CAP-write  (2)
  //        bytes > CAP-write but < space available (3)
  //        bytes exactly the space available (4)
  //        bytes > space available (5)
  assert(cbfifo_enqueue(str, 32, test1) == 32);  // advance so that read < write
  assert(cbfifo_length(test1) == 32);
  assert(cbfifo_dequeue(buf, 16, test1) == 16);
  assert(cbfifo_length(test1) == 16);
  assert(strncmp(buf, str, 16) == 0);

  assert(cbfifo_enqueue(str, 32, test2) == 32);  // advance so that read < write
  assert(cbfifo_length(test2) == 32);
  assert(cbfifo_dequeue(buf, 16, test2) == 16);
  assert(cbfifo_length(test2) == 16);
  assert(strncmp(buf, str, 16) == 0);

  printf("\n\rTest 10 passed");





  assert(cbfifo_enqueue(str+32, 32, test1) == 32);  // (1)
  assert(cbfifo_length(test1) == 48);
  assert(cbfifo_enqueue(str+64, cap-64,test1) == cap-64);  // (2)
  assert(cbfifo_length(test1) == cap-16);
  assert(cbfifo_dequeue(buf+16, cap-16, test1) == cap-16);
  assert(strncmp(buf, str, cap) == 0);

  assert(cbfifo_enqueue(str, 32, test1) == 32);  // advance so that read < write
  assert(cbfifo_length(test1) == 32);
  assert(cbfifo_dequeue(buf, 16, test1) == 16);
  assert(cbfifo_length(test1) == 16);
  assert(strncmp(buf, str, 16) == 0);


  assert(cbfifo_enqueue(str+32, 32, test2) == 32);  // (1)
  assert(cbfifo_length(test2) == 48);
  assert(cbfifo_enqueue(str+64, cap-64,test2) == cap-64);  // (2)
  assert(cbfifo_length(test2) == cap-16);
  assert(cbfifo_dequeue(buf+16, cap-16, test2) == cap-16);
  assert(strncmp(buf, str, cap) == 0);

  assert(cbfifo_enqueue(str, 32, test2) == 32);  // advance so that read < write
  assert(cbfifo_length(test2) == 32);
  assert(cbfifo_dequeue(buf, 16, test2) == 16);
  assert(cbfifo_length(test2) == 16);
  assert(strncmp(buf, str, 16) == 0);

  printf("\n\rTest 11 passed");




  assert(cbfifo_enqueue(str+32, cap-20, test1) == cap-20);  // (3)
  assert(cbfifo_length(test1) == cap-4);
  assert(cbfifo_dequeue(buf, cap-8, test1) == cap-8);
  assert(strncmp(buf, str+16, cap-8) == 0);
  assert(cbfifo_length(test1) == 4);
  assert(cbfifo_dequeue(buf, 8, test1) == 4);
  assert(strncmp(buf, str+16+cap-8, 4) == 0);
  assert(cbfifo_length(test1) == 0);

  assert(cbfifo_enqueue(str, 49 ,test1) == 49);  // advance so that read < write
  assert(cbfifo_length(test1) == 49);
  assert(cbfifo_dequeue(buf, 16, test1) == 16);
  assert(cbfifo_length(test1) == 33);
  assert(strncmp(buf, str, 16) == 0);


  assert(cbfifo_enqueue(str+32, cap-20, test2) == cap-20);  // (3)
  assert(cbfifo_length(test2) == cap-4);
  assert(cbfifo_dequeue(buf, cap-8, test2) == cap-8);
  assert(strncmp(buf, str+16, cap-8) == 0);
  assert(cbfifo_length(test2) == 4);
  assert(cbfifo_dequeue(buf, 8, test2) == 4);
  assert(strncmp(buf, str+16+cap-8, 4) == 0);
  assert(cbfifo_length(test2) == 0);

  assert(cbfifo_enqueue(str, 49 ,test2) == 49);  // advance so that read < write
  assert(cbfifo_length(test2) == 49);
  assert(cbfifo_dequeue(buf, 16, test2) == 16);
  assert(cbfifo_length(test2) == 33);
  assert(strncmp(buf, str, 16) == 0);
  printf("\n\rTest 12 passed");







  assert(cbfifo_enqueue(str+49, cap-33, test1) == cap-33);  // (4)
  assert(cbfifo_length(test1) == cap);
  assert(cbfifo_dequeue(buf, cap, test1) == cap);
  assert(cbfifo_length(test1) == 0);
  assert(strncmp(buf, str+16, cap) == 0);

  assert(cbfifo_enqueue(str, 32, test1) == 32);  // advance so that read < write
  assert(cbfifo_length(test1) == 32);
  assert(cbfifo_dequeue(buf, 16, test1) == 16);
  assert(cbfifo_length(test1) == 16);
  assert(strncmp(buf, str, 16) == 0);

  assert(cbfifo_enqueue(str+49, cap-33, test2) == cap-33);  // (4)
  assert(cbfifo_length(test2) == cap);
  assert(cbfifo_dequeue(buf, cap, test2) == cap);
  assert(cbfifo_length(test2) == 0);
  assert(strncmp(buf, str+16, cap) == 0);


  assert(cbfifo_enqueue(str, 32, test2) == 32);  // advance so that read < write
  assert(cbfifo_length(test2) == 32);
  assert(cbfifo_dequeue(buf, 16, test2) == 16);
  assert(cbfifo_length(test2) == 16);
  assert(strncmp(buf, str, 16) == 0);
  printf("\n\rTest 13 passed");




  assert(cbfifo_enqueue(str+32, cap, test1) == cap-16);  // (5)
  assert(cbfifo_dequeue(buf, 1, test1) == 1);
  assert(cbfifo_length(test1) == cap-1);
  assert(cbfifo_dequeue(buf+1, cap-1,test1) == cap-1);
  assert(cbfifo_length(test1) == 0);
  assert(strncmp(buf, str+16, cap) == 0);

  assert(cbfifo_enqueue(str+32, cap, test2) == cap-16);  // (5)
  assert(cbfifo_dequeue(buf, 1, test2) == 1);
  assert(cbfifo_length(test2) == cap-1);
  assert(cbfifo_dequeue(buf+1, cap-1,test2) == cap-1);
  assert(cbfifo_length(test2) == 0);
  assert(strncmp(buf, str+16, cap) == 0);
  printf("\n\rTest 14 passed");




  //    enqueue when write < read:
  //        bytes < read-write (6)
  //        bytes exactly read-write (= the space available) (7)
  //        bytes > space available (8)

  int wpos=0, rpos=0;
  assert(cbfifo_enqueue(str, cap-4, test1) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length(test1) == cap-4);
  assert(cbfifo_dequeue(buf, 32, test1) == 32);
  rpos += 32;
  assert(cbfifo_length(test1) == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12, test1) == 12);
  wpos += 12;
  assert(cbfifo_length(test1) == cap-24);


  assert(cbfifo_enqueue(str, cap-4, test2) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length(test2) == cap-4);
  assert(cbfifo_dequeue(buf, 32, test2) == 32);
  rpos += 32;
  assert(cbfifo_length(test2) == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12, test2) == 12);
  wpos += 12;
  assert(cbfifo_length(test2) == cap-24);

  printf("\n\rTest 15 passed");




  assert(cbfifo_enqueue(str+wpos, 16, test1) == 16);  // (6)
  assert(cbfifo_length(test1) == cap-8);
  assert(cbfifo_dequeue(buf, cap, test1) == cap-8);
  assert(cbfifo_length(test1) == 0);
  //assert(strncmp(buf, str+rpos, cap-8) == 0);


  // reset
  wpos=0;
  rpos=0;
  assert(cbfifo_enqueue(str, cap-4, test1) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length(test1) == cap-4);
  assert(cbfifo_dequeue(buf, 32, test1) == 32);
  rpos += 32;
  assert(cbfifo_length(test1) == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12, test1) == 12);
  wpos += 12;
  assert(cbfifo_length(test1) == cap-24);

  assert(cbfifo_enqueue(str+wpos, 16, test2) == 16);  // (6)
  assert(cbfifo_length(test2) == cap-8);
  assert(cbfifo_dequeue(buf, cap, test2) == cap-8);
  assert(cbfifo_length(test2) == 0);
  //assert(strncmp(buf, str+rpos, cap-8) == 0);


  // reset
  wpos=0;
  rpos=0;
  assert(cbfifo_enqueue(str, cap-4, test2) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length(test2) == cap-4);
  assert(cbfifo_dequeue(buf, 32, test2) == 32);
  rpos += 32;
  assert(cbfifo_length(test2) == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12, test2) == 12);
  wpos += 12;
  assert(cbfifo_length(test2) == cap-24);
  printf("\n\rTest 16 passed");





  assert(cbfifo_enqueue(str+wpos, 24, test1) == 24);  // (7)
  assert(cbfifo_length(test1) == cap);
  assert(cbfifo_dequeue(buf, cap, test1) == cap);
  assert(cbfifo_length(test1) == 0);
  assert(strncmp(buf, str+rpos, cap) == 0);

  // reset
  wpos=0;
  rpos=0;
  assert(cbfifo_enqueue(str, cap-4, test1) == cap-4);
  wpos += cap-4;
  assert(cbfifo_length(test1) == cap-4);
  assert(cbfifo_dequeue(buf, 32, test1) == 32);
  rpos += 32;
  assert(cbfifo_length(test1) == cap-36);
  assert(strncmp(buf, str, 32) == 0);
  assert(cbfifo_enqueue(str+wpos, 12, test1) == 12);
  wpos += 12;
  assert(cbfifo_length(test1) == cap-24);
  printf("\n\rTest 17 passed");


  assert(cbfifo_enqueue(str+wpos, 64, test1) == 24);  // (8)
  assert(cbfifo_length(test1) == cap);
  assert(cbfifo_dequeue(buf, cap, test1) == cap);
  assert(cbfifo_length(test1) == 0);
  assert(strncmp(buf, str+rpos, cap) == 0);

  assert(cbfifo_enqueue(str+wpos, 64, test2) == 24);  // (8)
  assert(cbfifo_length(test2) == cap);
  assert(cbfifo_dequeue(buf, cap, test2) == cap);
  assert(cbfifo_length(test2) == 0);
  assert(strncmp(buf, str+rpos, cap) == 0);
  printf("\n\rTest 18 passed");

  printf("\n\r%s: passed all test cases\n", __FUNCTION__);
}
