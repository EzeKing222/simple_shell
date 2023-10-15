#include "shell.h"

/**
 * main - Entry point.
 * Return: 0 (on success).
 */
int main(void)
{
	char *command = NULL;
	size_t command_length = 0;

	char *argv[MAX_ARGUMENTS], *delim;
	int numbers_of_command, status;
	ssize_t nread;
	char *token;
	pid_t pid;
	struct stat sfile;

	while (true)
	{
		_print("$ ");

		nread = getline(&command, &command_length, stdin);
		if (nread == -1)
		{
			/* handle end of file */
			if (feof(stdin))
			{
				_print("\n");
				free(command);
				exit(EXIT_SUCCESS);
			}
			else
			{
				_print("Error reading input.\n");
				free(command);
				exit(EXIT_FAILURE);
			}
		}

		/* Remove the trailing newline character */
		_remove_newline(command);

		/* Parse the command into argument vectors */
		numbers_of_command = 0;
		delim = " ";
		token = strtok(command, delim);

		while (token != NULL && numbers_of_command < MAX_ARGUMENTS - 1)
		{
			argv[numbers_of_command] = token;
			numbers_of_command++;
			token = strtok(NULL, delim);
		}

		argv[numbers_of_command] = NULL;

		/* Fork a child process to execute the command */
		pid = fork();

		if (pid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process */
			/* check if any command is entered */
			if (argv[0])
			{
				/* if command is entered, check if found */
				if (stat(argv[0], &sfile) == 0)
				{
					execve(argv[0], argv, NULL);
					perror("execve failed");
					exit(EXIT_FAILURE);
				}
				else
				{
					_printf("%s: No such file or directory\n", argv[0]);
				}
			}
		}
		else
		{
			/* Parent process */
			waitpid(pid, &status, 0);
		}
	}

	free(command);

	return (0);
}