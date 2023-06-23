#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to top node in stack
 * @line_number: line number of command
 *
 * Description: The integer stored at the top of the stack is treated as the
 * ASCII value of the character to be printed. If the value is not in the ASCII
 * table, print an error message and exit with status EXIT_FAILURE. If the stac
 * is empty, print an error message and exit with status EXIT_FAILURE.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
