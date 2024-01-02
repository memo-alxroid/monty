#include "monty.h"

/**
 * read_commands_from_file - read commands from file
 *
 * @filePointer: file pointer
 *
 * Return: 0 on success
 *
 */

void read_commands_from_file(FILE *filePointer)
{
	int lineNumber = 1;
	char *command = NULL;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	while (getline(&line, &len, filePointer) != -1)
	{
		command = strtok(line, " \n\t\r$");
		if (command != NULL)
		{
			execute_command_if_exist(command, &stack, lineNumber);
		}
		lineNumber++;
	}
	if (!feof(filePointer))
	{
		fclose(filePointer);
		free(stack);
		free(line);
		printf("Error while reading from file\n");
		exit(EXIT_FAILURE);
	}
	if (line != NULL)
		free(line);
	fclose(filePointer);
}
