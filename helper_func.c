#include "monty.h"

/**
* monty_error - Print an error message and exit the program.
* @message: The error message to print.
*/
void monty_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

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
