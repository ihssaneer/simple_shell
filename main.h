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

/*Stract section :*/
/**
 * struct input - jr
 * @count: jhf
 * @er_code: jhf
 * @line: jhfs
 * @av: jhfj
 * @args: ji
 * @envir: iji
 * Description: jsjf
*/
typedef struct input
{
	int count;
	int er_code;
	char *line;
	char **av;
	char **args;
	char **envir;
} input_t;

/*Functions section : */

/* main functions : */
void initializer(input_t *ptr, char **av, char **envir);
void get_line(input_t *ptr);
void get_arguments(input_t *ptr);
void path_handler(input_t *ptr);
char* get_path(input_t *ptr);
int check_path(input_t *ptr);
int fork_and_execve(input_t *ptr);
void free_argument(input_t *ptr);
void print_error(input_t *ptr);


/* print functions : */
int _putchar(char c);
int print_num(unsigned int num);
int put_err(char c);


#endif /*SSH_H*/
