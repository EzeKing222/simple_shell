#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdarg.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

void _print(char *const print);
void _printf(const char *format, ...);
void _remove_newline(char *str);

#endif