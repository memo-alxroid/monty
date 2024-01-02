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
	int i;
	instruction_t ops[] = {
		{"push", pushOP},
		{"pall", pallOP},
		{"pint", pintOP},
		{"pop", popOP},
		{"swap", swapOP},
		{"add", addOP},
		{"nop", nopOP},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(cmd, ops[i].opcode) == 0)
		{
			ops[i].f(stack, lineNum);
			return;
		}
	}
	if (cmd && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", lineNum, cmd);
		exit(EXIT_FAILURE);
	}
}
