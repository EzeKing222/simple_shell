#include "shell.h"

/**
 * get_path - My designated function to get the all values from a certain path.
 * The enviromental variable PATH.
 * @env: Assigned pointer to enviromental variables.
 * Return: All inclusive tokenized pathways for cmds.
 * Last line
 */
char **get_path(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;

	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = string_cmd(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}
