#include "monty.h"

/**
* main - Entry point of the monty program
* @argc: Number of command-line arguments
* @argv: array of command-line arguments.
*
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *montyfile;

	/* check if correct num of argument is provided*/
	if (argc != 2)
	{
		monty_error("USAGE: monty file");
		return (EXIT_FAILURE);
	}

	/* open the file */
	montyfile = fopen(argv[1], "r");
	if (montyfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* process the input file and execute the opcodes */
	process_file(file, &stack);

	/* close the file and free the stack */
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}


/**
* process_file - Process the input file and execute the opcodes.
* @file: Pointer to the input file.
* @stack: Pointer to the stack.
*/
void process_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/* Read the input file line by line */
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		/* Parse the opcode and argument from the line */
	char *opcode;
	char *arg;

	opcode = strtok(line, "\n");
	if (!opcode || opcode[0] == '#')
		continue;
	arg = strtok(NULL, "\n");


	/* Execute the corresponding opcode function*/
	execute_line(opcode, arg, stack);
	}
	/* free memory allocated to line*/
	free(line);
}

/**
* execute_opcode - Execute the corresponding opcode function.
* @opcode: The opcode to execute.
* @arg: The argument for the opcode.
* @stack: Pointer to the stack.
*/
void execute_opcode(char *opcode, char *arg, stack_t **stack)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || !is_digit(arg))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(*stack);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
