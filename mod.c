#include "monty.h"

/**
 * mod - computes the remainder of the division of the second top element
 *        of the stack by the top element
 * @stack: double pointer to top node in stack
 * @line_number: line number of command
 *
 * Description: This function computes the remainder of the division of the
 * second top element of the stack by the top element, stores the result in the
 * second top element, and removes the top element. If the stack contains less
 * than two elements, it prints an error message and exits with the status
 * EXIT_FAILURE. If the top element is 0, it prints an error message regarding
 * division by zero and exits with the status EXIT_FAILURE.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n; /*Compute the remainder*/
	temp = *stack;
	*stack = (*stack)->next; /* Make the second top element the new top el*/
	(*stack)->prev = NULL; /* Set the new top elmt's prev pointer to NULL*/

	free(temp); /* Free the original top element*/
}
