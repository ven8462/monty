#include "monty.h"
/**
 * usage_error - prints an usage error message
 * Return: FAILURE
 */

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);

}

/**
 *open_error - prints an open file error message
 *@file: file
 * Return: FAILURE
 */

void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);

	exit(EXIT_FAILURE);

}

/**
 * push_error - handles a push error
 * @fd: file desciptor
 * @buf: buffer
 * @stack:  stack or queue
 * @line_number: line number of the command
 */

void push_error(FILE *fd, char *buf, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(buf);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * unknown_ins - handles  unknown instructions
 * @fd: file descriptor
 * @buf: buffer
 * @stack:  stack or queue
 * @line_num: line number of the command
 * @val: instruction
 */

void unknown_ins(FILE *fd, char *buf, stack_t *stack, char *val, int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, val);
	fclose(fd);
	free(buf);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
