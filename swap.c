#include "monty.h"

/**
 * swapOP - swap the top two elements of the stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void swapOP(stack_t **stack, unsigned int line_number)
{
	stack_t *firstElement = (*stack), *secondElement = NULL;


	if (firstElement == NULL || firstElement->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		secondElement = firstElement->next;

		firstElement->next = secondElement->next;
		firstElement->prev = secondElement;
		secondElement->next = firstElement;
		secondElement->prev = NULL;
		(*stack) = secondElement;
	}
}