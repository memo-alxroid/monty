#include "monty.h"

/**
 * execute_command_if_exist - execute command if exist
 * @command: command to execute
 * @stack: stack that is a queue or stack
 * @lineNumber: line number
 * Return: void
 */

void execute_command_if_exist(char *command, stack_t **stack, unsigned int lineNumber)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	if (get_op_function(command) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, command);
		exit(EXIT_FAILURE);
	}
	else
	{
		f = get_op_function(command);
		command = strtok(NULL, " ");
		lineNumber = atoi(command);
		f(stack, lineNumber);
	}
}
