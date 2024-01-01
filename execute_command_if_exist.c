#include "monty.h"

/**
 * execute_command_if_exist - execute command if exist
 * @cmd: command to execute
 * @stack: stack that is a queue or stack
 * @lineNum: line number
 * Return: void
 */

void execute_command_if_exist(char *cmd, stack_t **stack, unsigned int lineNum)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	if (get_op_function(cmd) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		f = get_op_function(cmd);
		cmd = strtok(NULL, " ");
		lineNum = atoi(cmd);
		f(stack, lineNum);
	}
}
