#include "shell.h"

/**
 * _remove_newline - remove newline at
 * end of a charater.
 * @*str: pointer to line of text.
 * Return: void.
 */
void _remove_newline(char *str)
{
	char *newline = NULL;
	char *current_char = str;

	while (*current_char != '\0')
	{
		if (*current_char == '\n')
		{
			newline = current_char;
			break;
		}
		current_char++;
	}

	if (newline != NULL)
	{
		*newline = '\0';
	}
}