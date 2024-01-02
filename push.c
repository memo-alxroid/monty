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
	stack_t *newElement;
	char *number;
	size_t i;

	number = strtok(NULL, " \n\t\r");
	if (line_number == 0 || number == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < strlen(number); i++)
	{
		if (!isdigit(number[i]) && number[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	newElement = malloc(sizeof(stack_t));
	if (newElement == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newElement->n = atoi(number);
	newElement->prev = NULL;
	newElement->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newElement;

	*stack = newElement;
}
