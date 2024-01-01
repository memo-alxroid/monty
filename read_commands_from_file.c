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

int read_commands_from_file(char *commands, FILE *filePointer)
{
	int lineNumber = 1;
	char *command = NULL;
	stack_t *stack = NULL;

	while (fgets(commands, 1024, filePointer) != NULL)
	{
		command = strtok(commands, " \n$");
		execute_command_if_exist(&command, &stack, lineNumber);
		lineNumber++;
	}
	if (!feof(filePointer))
	{
		fclose(filePointer);
		printf("Error while reading from file\n");
		exit(EXIT_FAILURE);
	}
	fclose(filePointer);
	return (0);
}
