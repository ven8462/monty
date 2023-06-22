#include "monty.h"

/**
 * process_line - process a line from the file and execute the command
 * @stack: pointer to the stack
 * @line: line read from the file
 * @current_line: line number in the file
 */
void process_line(stack_t **stack, char *line, int current_line)
{
	cmd_t cmd = {NULL, NULL};
	char *token = NULL;
	char *value = NULL;
	int result = 0;

	token = strtok(line, " \n\t\r");

	if (token == NULL || *token == '#')
	{
		return;
	}

	value = strtok(NULL, " \n\t\r");
	result = find_opc(stack, token, value, current_line);

	if (result == 1)
	{
		push_error(cmd.fd, cmd.line, *stack, current_line);
	}
	else if (result == -1)
	{
		unknown_ins(cmd.fd, cmd.line, *stack, token, current_line);
	}
}

/**
 * execute - reads the file and executes the Monty bytecodes
 * @montyfile: argument vector containing the file name
 */
void execute(char *montyfile)
{
	cmd_t cmd = {NULL, NULL};
	int current_line = 0;
	size_t buffer_size = 0;
	stack_t *stack = NULL;

	if (cmd.fd)
	{
		while (getline(&cmd.line, &buffer_size, cmd.fd) != -1)
		{
			current_line++;
			process_line(&stack, cmd.line, current_line);
		}
		free(cmd.line);
		free_stack(stack);
		fclose(cmd.fd);
	}
	else
	{
		open_error(montyfile);
	}
}
