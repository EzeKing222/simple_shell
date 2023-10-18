#include "shell.h"

/**
 *  * string_cmd - This function split and create a full string command.
 *   *@s: Given delimiter for strtok.
 *    *@buffer: This is the pointer to input string.
 *     * Return: A string string with total command.
 *     *Last line
 *      */
char **string_cmd(char *buffer, const char *s)
{
		char *token = NULL, **commands = NULL;
			size_t bufsize = 0;
				int i = 0;

					if (buffer == NULL)
								return (NULL);
						bufsize = _strlen(buffer);
							commands = malloc((bufsize + 1) * sizeof(char *));
								if (commands == NULL)
										{
													perror("Unable to allocate buffer");
															free(buffer);
																	free_rp(commands);
																			exit(EXIT_FAILURE);
																				}
									token = strtok(buffer, s);
										while (token != NULL)
												{
															commands[i] = malloc(_strlen(token) + 1);
																	if (commands[i] == NULL)
																				{
																								perror("Buffer allocation error");
																											free_rp(commands);
																														return (NULL);
																																}
																			_strcpy(commands[i], token);
																					token = strtok(NULL, s);
																							i++;
																								}
											commands[i] = NULL;
												return (commands);
}
