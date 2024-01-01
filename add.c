#include "monty.h"

/**
 * addOP - add the top two elements of the stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void addOP(stack_t **stack, unsigned int line_number)
{
	stack_t *firstElement = (*stack), *secondElement = NULL;
	int sum = 0;

	if (firstElement == NULL || firstElement->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		secondElement = firstElement->next;

		sum = firstElement->n + secondElement->n;
		secondElement->n = sum;

		secondElement->prev = firstElement->prev;
		(*stack) = secondElement;
		free(firstElement);
	}
}
