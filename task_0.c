#include "monty.h"


/**
 * createNode - creates a new node
 * @n: the value of the node
 * Return: new node
 */

stack_t *createNode(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * push - pushes a new node with the given value to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: value to be pushed
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new = NULL;
	(void)line_number;

	new = createNode(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}


/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	tmp = *stack;

	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
