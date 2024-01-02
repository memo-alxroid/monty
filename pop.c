#include "monty.h"

/**
 * popOP - remove the top element of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void popOP(stack_t **stack, unsigned int line_number)
{
	stack_t *currentElement = (*stack);

	if (currentElement == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack) = currentElement->next;
		free_stack(currentElement);
	}
}
