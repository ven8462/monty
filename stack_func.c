/**
* _push - pushes an element to the stack
* @stack: pointer to first node in stack
* @line_number: int to be stored in stack
*
* Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the new node's value and initialize its pointers */
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* If the stack is not empty, update the previous top node's prev pointer */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* If the stack is empty, set the new node as the first node in the stack */
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		/* Insert the new node at the top of the stack and update pointers */
		new_node->next = *stack;
		*stack = new_node;
	}
}

/**
* _pall - prints all the values on the stack,
* starting from the top of the stack
* @stack: double pointer to the first node in stack
* @line_number: the line number in the script
*
* Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	/* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	temp = *stack;

	/* Iterate through the stack and print each node's value */
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
