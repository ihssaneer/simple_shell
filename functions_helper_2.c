#include "main.h"

/* Function 1/5 : */
/**
 * check_path - kjh
 * @ptr: jdsjii
 * Return: 1 on success and 0 on failure.
 */
int check_path(input_t *ptr)
{
	if (access(ptr->args[0], F_OK) == -1)
	{
		ptr->er_code = 127;
		print_error(ptr);
		return (1);
	}
	else if (access(ptr->args[0], X_OK) == -1)
	{
		ptr->er_code = 126;
		print_error(ptr);
		return (1);
	}
	return (0);
}
/* Function 2/5 : */
/**
 * fork_and_execve - kjh
 * @ptr: jdsjii
 * Return: void
 */
int fork_and_execve(input_t *ptr)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
		return (1);
	if ((pid == 0) && (execve(ptr->args[0], ptr->args, NULL) == -1))
		return (1);
	wait(&status);
	return (0); /*err*/
}

/* Function 3/5 : */
/**
 * free_argument - eee
 * @ptr: ddd
 */
void free_argument(input_t *ptr)
{
	int i;

	if (ptr->args == NULL)
		return;
	for (i = 0; ptr->args[i] != NULL; i++)
	{
		free(ptr->args[i]);
	}
	free(ptr->args);
}

/* Function 4/5 : */
/**
 * print_error - kjh
 * @ptr: ddd
 * Return: void.
 */
void print_error(input_t *ptr)
{
	write(2, ptr->av[0], strlen(ptr->av[0]));
	write(2, ": ", 2);
	print_num(ptr->count);
	write(2, ": ", 2);
	write(2, ptr->args[0], strlen(ptr->args[0]));
	if (ptr->er_code == 127)
		write(2, ": not found\n", 12);
	if (ptr->er_code == 126)
		write(2, ": Permission denied\n", 20);
}
