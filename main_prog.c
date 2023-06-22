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
	/* check if correct num of arguments is provided */
	if (argc != 2)
	{
		usage_error();
	}

	/* call the execute function with the filename argument */
	execute(argv[1]);

	return (EXIT_SUCCESS);
}
