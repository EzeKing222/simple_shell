#include "shell.h"

/**
 * _print - print text to standard input.
 * @message: text to print.
 * Return: void,
 */
void _print(char *const message)
{
	write(STDOUT_FILENO, message, strlen(message));
}