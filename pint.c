#include "monty.h"

/**
 * pintOP - print the value at the top of the stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void pintOP(stack_t **stack, unsigned int line_number)
{
	stack_t *currentElement = (*stack);

	if (currentElement == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", currentElement->n);
	}
}