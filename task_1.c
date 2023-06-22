#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to top node in stack
 * @line_number: line number of command
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp_value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp_value = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_value;
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to top node in stack
 * @line_number: line number of command
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n; /* Add the top two elements*/
	temp = *stack;
	*stack = (*stack)->next; /* Make the second top element the new top element*/
	(*stack)->prev = NULL; /* Set the new top element's prev pointer to NULL*/

	free(temp); /* Free the original top element*/
}

/**
 * nop - does nothing
 * @stack: double pointer to top node in stack
 * @line_number: line number of command
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
