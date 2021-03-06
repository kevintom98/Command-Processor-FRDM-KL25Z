
/*
 * command_processor.c
 *
 *  Created on: 08-Nov-2021
 *      Author: Kevin Tom, Kevin.Tom@colorado.edu
 *
 *
 *  This file has the function implementation of command processor
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "command_processor.h"
#include "hexdump.h"





/* This function is the handler for author command.
 * This function prints the authors name
 *
 * Parameters:
 * None
 *
 * Returns:
 * None
 *
 *
 * */
void author_handler()
{
	//Printing author name
	printf("\n\rKevin Tom\n\r");
}







/* This function is the handler for author command.
 * This function prints the authors name
 *
 * Parameters:
 * 	argc - Number of arguments
 * 	argv - Array of arguments ending with '\0'
 *
 * Returns:
 * None
 *
 *
 * */
void dump_handler(int argc, char *argv[])
{

	int start = 0, len = 0;

	//Converting start address to from hex to decimal
	start = (int)strtol(argv[1],NULL,16);

	/*If given address is in hex convert it into decimal
	 * Else convert it into decimal from string
	 */
	if((*(argv[2]) == '0') && (*(argv[2]+1) == 'x'))
		len = (int)strtol(argv[2],NULL,16);
	else
		len = atoi(argv[2]);


	//Calling the hexdump function
	hexdump((int *)start,len);
}




/* This function is the handler for help command
 * it prints the help menu
 *
 * Parameters:
 * 	argc - Number of arguments
 * 	argv - Array of arguments ending with '\0'
 *
 * Returns:
 * 	None
 * */
void help_handler()
{
	for (int i=0; i < num_commands; i++)
	  {
		//Prints until help
	    if (strcasecmp("help", commands[i].name) != 0)
	    {
	    	//Printing the string
	    	for(const char *j=commands[i].help_string; *j != '\0'; j++)
	    		printf("%c",*j);
	    }
	  }
}





/* This function starts the command processor and handles the commands recevied
 *
 * Parameters:
 * 	None
 *
 * Returns:
 * None
 *
 *
 * */
void command_processor_start()
{
	char command[100];
	int i=-1;
	printf("\rWelcome to BreakfastSerial!\n\r");

	while(1)
	{
		printf("? ");
		i= -1;


		/*******************Accumulator**********************/
		while(command[i] != '\r')
		{
			i++;
			//Getting character
			command[i]= getchar();

			//Handling backspace
			if((command[i] == '\b') && (i > 1))
			{
				command[i] =' ';
				printf(" \b \b");
			}

		}
		command[i++] = '\0';
		/****************************************************/


		//Calling process command function
		process_command(command);
	}


}





/* This function splits the received command into
 * argc and argv vectors and calls appropriate handling functions
 *
 * Parameters:
 * 	char *input - Input string from accumulator
 *
 * Returns:
 * 	None
 * */
void process_command(char *input)
{
  char *p = input;
  char *end;


  // find end of string
  for (end = input; *end != '\0'; end++)
    ;


  //Bool for printing error message
  bool found = false;
  char *argv[10];
  int argc = 0;


  //Setting argv array to '0'
  __builtin_memset(argv, 0, sizeof(argv));


  for (p = input; p < end; p++)
  {
	  //If a character is recognized
	  if((*p >= 48))
	  {
		  //if previous character is ' ' or '\0' or it is starting character
		  if( (*(p-1) == ' ') || (p == input) || (*(p-1) == '\0'))
		  {
			  //Write the address to argv[argc]
			  argv[argc] = p;
			  //Incrementing argc
			  argc++;
		  }
		  //If trailing character is space make it as '\0'
		  if(*(p+1) == ' ')
			  	*(p+1) = '\0';
	  }
  }


  //If no command received
  argv[argc] = NULL;
  if (argc == 0)   // no command
    return;


  //Checking which handler to call using argv[0] string
  for (int i=0; i < num_commands; i++)
  {
    if (strcasecmp(argv[0], commands[i].name) == 0)
    {
      commands[i].handler(argc, argv);
      found = true;
      break;
    }
  }


  //If no handler is found print error message
  if(found == false)
  {
	  printf("\n\rUnknown Command: ");
	  for(char *i= argv[0];*i != '\0' ;i++)
		  printf("%c",*i);
	  printf("\n\r");
  }


}
