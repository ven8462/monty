#include "monty.h"


/**
* free_stack - Free the memory used by the stack.
* @stack: Pointer to the head of the stack.
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * clean_stack - Free all and close files
 * @stack: Stack
 */

void clean_stack(stack_t **stack)
{
	cmd_t cmd = {NULL, NULL};

	stack_t *temp = *stack;

	while (temp)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	fclose(cmd.fd);
	free(cmd.line);
}
