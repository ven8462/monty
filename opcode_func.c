#include "monty.h"

/**
 * find_opc - finds the appropriate opcode function
 * @stack: pointer to the stack or queue
 * @instruction: the opcode instruction
 * @value_str: the value as a string
 * @line_num: the line number
 * Return: 0 on success || 1 if not a digit || -1 on error
 */
int find_opc(stack_t **stack, char *instruction, char *value_str, int line_num)
{
	int idx = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (op[idx].opcode)
	{
		if (!strcmp(instruction, op[idx].opcode))
		{
			if (!strcmp(instruction, "push"))
			{
				if (is_digit(value_str) == 1)
					value = atoi(value_str);
				else
					return (1); /** if not digit */
			}
			op[idx].f(stack, (unsigned int)line_num);
			break;
		}
		idx++;
	}
	if (!op[idx].opcode)
		return (-1);

	return (0);
}
