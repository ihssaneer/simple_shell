#ifndef SSH_H
#define SSH_H

/*JalilErr & ihssaneer*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Functions section : */
char **get_arguments(char *line);
void free_argument(char **args);
int _putchar(char c);

#endif /*SSH_H*/