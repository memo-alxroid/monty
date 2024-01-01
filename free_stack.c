#include "monty.h"

/**
 * free_stack - free stack
 * @stack: stack that is a queue or stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
