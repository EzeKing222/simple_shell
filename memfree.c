#include "shell.h"

/**
 * free_rp - My function used to free all the memory allocated for cmd.
 * @cmd: Assigned pointer to allocated memory to free.
 * Return: Absolutely nothing.
 * Last line
 */
void free_rp(char **cmd)
{
	size_t j = 0;

	if (cmd == NULL)
		return;
	while (cmd[j])
	{
		free(cmd[j]);
		j++;
	}
	if (cmd[j] == NULL)
		free(cmd[j]);
	free(cmd);
}

/**
 * free_exit - This function frees all the memory allocated and exit.
 * @cmd: specific cmd memory to free.
 * Return: Absolutely nothing.
 * Last line
 */
void free_exit(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
	exit(EXIT_FAILURE);
}
