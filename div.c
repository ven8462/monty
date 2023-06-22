#include "monty.h"


/**
 * _div - divides the second top element of the stack by the top element
 * @stack: double pointer to top node in stack
 * @line_number: line number of command
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n; /* Div the 2nd top el with top el*/
	temp = *stack;
	*stack = (*stack)->next; /* Make the 2nd top element the new top el*/
	(*stack)->prev = NULL; /* Set the new top el's prev pointer to NULL*/

	free(temp); /* Free the original top element*/
}
