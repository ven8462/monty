#include "monty.h"

/**
* is_digit - Check if a string represents a valid integer.
* @str: The string to check.
*
* Return: 1 if the string represents a valid integer, 0 otherwise.
*/
int is_digit(const char *str)
{
	int i;

	if (str[0] == '-')
	str++; /* Skip the negative sign if present */

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
	}

	return (1);
}
