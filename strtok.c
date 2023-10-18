#include "shell.h"

/**
 * delimiter - My function used to check if
 * a character matchs with any other character
 * @c: Given character to check
 * @str: Given string of delimiters
 * Return: Return (1) on success, (0) for failure
 * Last line
 */
size_t delimiter(char c, const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strtok - My function used to extract tokens in a string
 * check_delim - My functions to be named
 * @str: Given string
 * @delim: delimiter function
 * Return: Returns the pointer to the next token or NULL
 * Last line
 */
char *_strtok(char *str, const char *delim)
{
	static char *tokens;
	static char *new_token;
	unsigned int i;

	if (str != NULL)
		new_token = str;
	tokens = new_token;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (delimiter(tokens[i], delim) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;

		return (NULL);
	}

	tokens = new_token + i;
	new_token = tokens;

	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (delimiter(new_token[i], delim) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokens);
}
