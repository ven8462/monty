#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to top node in stack
 * @line_number: line number of command
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL; /*Set the new top element's prev pointer to NULL*/

	free(temp); /* Free the original top element*/
}
