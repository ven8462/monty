#include "monty.h"


/**
 * sub - substracts the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	sum = temp->n;
	sum -= (*stack)->n;
	pop(stack, line_number);
	temp->n = sum;
}

