#include "monty.h"

/**
 * pushOP - push element to stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
 */

void pushOP(stack_t **stack, unsigned int line_number)
{
	stack_t *currentElement = (*stack);
	stack_t *newElement = NULL;
	char *number = NULL;

	number = strtok(NULL, " \n\t\r");
	if (line_number == 0 || number == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newElement = malloc(sizeof(stack_t));
	if (newElement == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newElement->n = atoi(number);

	if (currentElement == NULL)
	{
		newElement->prev = NULL;
		newElement->next = NULL;
		(*stack) = newElement;
	}
	else
	{
		newElement->prev = NULL;
		newElement->next = currentElement;
		currentElement->prev = newElement;
		(*stack) = newElement;
	}
}
