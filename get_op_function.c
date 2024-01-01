#include "monty.h"

/**
 * get_op_function - get opcode function
 * @opcode: opcode to check
 * Return: function to opcode
 */

void (*get_op_function(char *opcode))(stack_t **stack, unsigned int lineNumber)
{
	instruction_t opcodes[] = {
		{"push", pushOP},
		{"pall", pallOP},
		{"pint", pintOP},
		{"pop", popOP},
		{"swap", swapOP},
		{"add", addOP},
		{"nop", nopOP},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}
