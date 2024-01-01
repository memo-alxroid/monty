#include "monty.h"

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