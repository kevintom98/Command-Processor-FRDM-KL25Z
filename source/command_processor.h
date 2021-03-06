/*
 * command_processor.h
 *
 *  Created on: 04-Nov-2021
 *      Author: Kevin Tom, Kevin.Tom@colorado.edu
 */
#ifndef _COMMAND_PROCESSOR_H_
#define _COMMAND_PROCESSOR_H_


//Function pointer for each function
typedef void (*command_handler_t)(int, char *argv[]);



//Structure which holds all the handler details
typedef struct
{
  const char *name;
  command_handler_t handler;
  const char *help_string;
} command_table_t;




/* This function is the handler for author command.
 * This function prints the authors name
 *
 * Parameters:
 * None
 *
 * Returns:
 * None
 * */
void author_handler();



/* This function is the handler for author command.
 * This function prints the authors name
 *
 * Parameters:
 * 	argc - Number of arguments
 * 	argv - Array of arguments ending with '\0'
 *
 * Returns:
 * None
 * */
void dump_handler(int argc, char *argv[]);




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
void help_handler();



/********************************************************COMMAND TABLE********************************************************************/
static const command_table_t commands[] =
{
		{"author", author_handler,"\n\rauthor - This command will print the name of the author who wrote the command line\n\r"},
		{"dump", dump_handler,"dump   - This command will print Hexdump of memory(eg: dump start_addr end_addr ; dump 0 0x64)\n\r"},
		{"help", help_handler," "}
};
/*****************************************************************************************************************************************/



//Calculating number of commands
static const int num_commands = sizeof(commands) / sizeof(command_table_t);



/* This function starts the command processor and handles the commands recevied
 *
 * Parameters:
 * 	None
 *
 * Returns:
 * None
 * */
void command_processor_start();



/* This function splits the received command into
 * argc and argv vectors and calls appropriate handling functions
 *
 * Parameters:
 * 	char *input - Input string from accumualtor
 *
 * Returns:
 * 	None
 *
 *
 * */
void process_command(char *input);


#endif // _COMMAND_PROCESSOR_H_

