#include "shell.h"

/**
 * _putchar - write a message on standard output.
 * @c: message to write on standard output.
 * Return: void.
 */
void _putchar(const char *c)
{

	write(1, c, strlen(c));
}
