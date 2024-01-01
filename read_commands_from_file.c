#include "monty.h"

/**
 * read_commands_from_file - read commands from file
 *
 * @commands: commands line
 * @filePointer: file pointer
 *
 * Return: 0 on success
 *
 */

void read_commands_from_file(char *commands, FILE *filePointer)
{
	int lineNumber = 1;
	char *command = NULL;
	stack_t *stack = NULL;

	while (fgets(commands, 1024, filePointer) != NULL)
	{
		command = strtok(commands, " \n$");
		while (command != NULL)
		{
			execute_command_if_exist(command, &stack, lineNumber);
			command = strtok(NULL, " ");
		}
		lineNumber++;
	}
}
