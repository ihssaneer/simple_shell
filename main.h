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
char **get_arguments(char *line, char **envir);
void free_argument(char **args);
int _putchar(char c);
char **path_handler(char **args, char **envir);
char *get_path(char **env);
void print_error(char ** av, int count, char ** agrs, int err);
int print_num(unsigned int num);
int put_err(char c);
int check_path(char ** av, int count, char ** args);

#endif /*SSH_H*/
