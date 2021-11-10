
/*
 * command_processor.c
 *
 *  Created on: 08-Nov-2021
 *      Author: Kevin Tom, Kevin.Tom@colorado.edu
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "command_processor.h"
#include "hexdump.h"



typedef void (*command_handler_t)(int, char *argv[]);



/* This function is the handler for author command.
 * This function prints the authors name
 *
 * Parameters:
 * 	argc and argv
 *
 * Returns:
 * None
 *
 *
 * */
void author_handler(int argc, char *argv[])
{
	printf("\n\rKevin Tom");
}







/* This function is the handler for author command.
 * This function prints the authors name
 *
 * Parameters:
 * 	argc and argv
 *
 * Returns:
 * None
 *
 *
 * */
void dump_handler(int argc, char *argv[])
{

	if(str == NULL)
		return;
	char *s = str;


	printf("\n\rHEXDUMP");
}




typedef struct
{
  const char *name;
  command_handler_t handler;
  const char *help_string;
} command_table_t;



static const command_table_t commands[] = {
		{"author", author_handler,"\n\rThis command will print the name of the author who wrote the command line"},
		{"dump", dump_handler,"\n\rThis command will print Hexdump of memory(eg: dump start_addr end_addr ; dump 0 0x64)"}
};


static const int num_commands = sizeof(commands) / sizeof(command_table_t);









void command_processor_start()
{
	char command[100];
	int i=-1;
	printf("\n\n\rWelcome to BreakfastSerial!");

	while(1)
	{
		printf("\n\r? ");
		i= -1;
		while(command[i] != '\r')
		{
			i++;
			command[i] = getchar();
			if(command[i] == '\r')
			{
				command[i++] = '\0';
				break;
			}

		}
		process_command(command);
	}


}






void process_command(char *input)
{
  char *p = input;
  char *end;
  // find end of string
  for (end = input; *end != '\0'; end++)
    ;
  // Tokenize input in place
  bool in_token = false;
  char *argv[10];
  int argc = 0;
  __builtin_memset(argv, 0, sizeof(argv));

  for (p = input; p < end; p++)
  {
	  if((*p >= 48))
	  {
		  in_token = true;

		  if( (*(p-1) ==' ') || (p == input) || (*(p-1) =='\0'))
		  {
			  argv[argc] = p;
			  argc++;
		  }
		  if(*(p+1) == ' ')
			  	*(p+1) = '\0';
	  }


  }


 /* for(int i=0;i<argc;i++)
	  printf("\n\rArgv[%d] : %c",i,*argv[i]);*/


  argv[argc] = NULL;
  if (argc == 0)   // no command
    return;


  // TODO: Dispatch argc/argv to handler
  for (int i=0; i < num_commands; i++)
  {
    if (strcasecmp(argv[0], commands[i].name) == 0)
    {
      commands[i].handler(argc, argv);
      break;
    }
    else
    {									//Reason for hexdump get a unknow command at first
    	printf("\n\rUnknown Command: "); //For first check it will say unknow command, then it will check second it will find match
    }
  }
}
