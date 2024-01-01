#include "monty.h"

/**
 * pallOP - print all elements of stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void pallOP(stack_t **stack, unsigned int line_number)
{
	stack_t *currentElement = (*stack);

	while (currentElement != NULL)
	{
		printf("%d\n", currentElement->n);
		currentElement = currentElement->next;
	}
	(void)line_number;
}
