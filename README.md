# PES-Assignment-3
Code for Assignment-3 for PES, ECEN-5813,  Fall 2021
****************************************************************************************************************   
**Author**            - Kevin Tom  
**Development Board** - FRDM KL25Z (MKL25Z128VLK4)  
**Tools used**        - MCUXpresso IDE v11.2.0 [Build 4120] [2020-07-09]      
**Operating System**  - Windows 10 Home  
****************************************************************************************************************

## Important files in the build   
    1. delay .c - This function has the delay function which takes input in milliseconds and delays
    2. infinit_loop_pattern.c - This file has the timing (.5s - 1s - 2s -3s delay) and other related functions.    
    3. LED_init.c - This file has code for initializing LEDs
    4. log.h - Abstraction away from printf
    5. Startup.c - This file has the code for initial startup pattern
    6. TSI_Init.c - This function initializes the touch sensor
    7. TSI_Measure.c - TSI scanning function, which returns raw values
    8. update_led.c - Maps LEDs to TSI readings

 


## How to compile and run the file    
    1. Open MCUXpresso IDE and export the project 
    2. Press "Build" to build the code 
    3. Connect your FRDM KL25Z to your computer
    4. Press "Debug" to debug the code on FRDM KL25Z
   
    
    
##   Extra Credit
**What is the address of your main() function?**  
Snippet of Main function from Disassembly file is given below:  
![Main Function Disassembly](/Main_Function_Add.JPG) 
\
**Answer**  
The address of the main function was found to **E44** hex.    
\
\
\
\
**What is the size in bytes of your delay() function, as shown by objdump?**  
Snippet of Delay function from Disassembly file is given below:  
![Delay Function Disassembly](/Disassembly.JPG)  
\
\
**Answer**  
The size of delay function can be caculated by subtracting the last address from first address in the file    
Size of delay function = 66C - 644 = **28 in Hex**.  
Size of delay function is **40 Bytes** when subtracting addresses.  
This can be done by adding bytes consumed by all the instructions in the function,  
size = 2+2+2+2+2+2+1+2+2+2+2+2+2+2+1+2+2+2+2+2+2 = 40 Bytes
\
NOTE:  
The .word instruction in the last adds a word (4 bytes) to the function, if we want to add that it becomes **44 Bytes**.  
\
\
\
\
\
**Show the full disassembly of your delay() function, adding comments to each line to explain the functionality.**\ 
\
**Answer** \
<00000644 <delay>:  
 644:	b580      	push	{r7, lr} ; moving lr to register 7 (r7)  
 646:	b082      	sub	sp, #8 ; subtracting 8 from Stack pointer  
 648:	af00      	add	r7, sp, #0 ; adding Stack pointer to 0 and storing it in r7  
 64a:	6078      	str	r0, [r7, #4] ; store with immidiate offset - Store r7 based address with offset of 4 to r0  
 64c:	687b      	ldr	r3, [r7, #4] ; load r3 with r7 based address with offset of 4  
 64e:	4a07      	ldr	r2, [pc, #28]	; (66c <delay+0x28>)  ; load r2 with PC based address with offset of 28  
 650:	4353      	muls	r3, r2 ; multiply r2 and r2  
 652:	607b      	str	r3, [r7, #4] ; store r7 based address with offset of 4 to r3  
 654:	e000      	b.n	658 <delay+0x14> ; unconditional branch instruction (branch to 658 addr) - .N tells assembler to encode instruction in 16 bits  
 656:	46c0      	nop			; (mov r8, r8) ; no operation
 658:	687b      	ldr	r3, [r7, #4] ; load r3 with r7 based address with offset of 4  
 65a:	1e5a      	subs	r2, r3, #1 ; subtracts 1 from r3 and stores in r2  
 65c:	607a      	str	r2, [r7, #4] ; store r7 based address with offset of 4 in r2  
 65e:	2b00      	cmp	r3, #0 ; compare r3 and 0  
 660:	d1f9      	bne.n	656 <delay+0x12> ; Branch Not Equal, checks zero or non-zero (branch to 656)  
 662:	46c0      	nop			; (mov r8, r8) ; no operation  
 664:	46c0      	nop			; (mov r8, r8) ; no operation  
 666:	46bd      	mov	sp, r7 ; move r7 to stack pointer  
 668:	b002      	add	sp, #8 ; add 8 with stack pointer  
 66a:	bd80      	pop	{r7, pc} ; pops r7 and pc from stack  
 66c:	00000916 	.word	0x00000916 ; places 4 bytes (0x00000916) memeory space in the location   
 










  


