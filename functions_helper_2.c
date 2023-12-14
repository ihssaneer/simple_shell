#include "main.h"

/* Function 1/5 : */
/**
 * check_path - function to verified the path.
 * @ptr: jdsjii
 * Return: 1 on success and 0 on failure.
 */
int check_path(input_t *ptr)
{
	if (!((ptr->args[0][0] == '.' || ptr->args[0][0] == '/') &&
			access(ptr->args[0], F_OK) == 0))
	{
		ptr->er_code = 127, print_error(ptr);
		return (1);
	}
	else if (access(ptr->args[0], X_OK) == -1)
	{
		ptr->er_code = 126, print_error(ptr);
		return (1);
	}
	return (0);
}
/* Function 2/5 : */
/**
 * fork_and_execve - function that creat the process child and exute the commande.
 * @ptr: the commande line.
 * Return: 1 in successe, 0 in in error.
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
 * free_argument - function use it to free the argument.
 * @ptr: line to free.
 * Return: Void.
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
 * print_error - function that print the error
 * @ptr: line
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
/* Function 5/5 : */
/**
 * check_exit_env - function that print the envirement of variables, and excute the exit commande.
 * @ptr: line.
 * Return: 0 in successe, amd 1 in failure.
 */
int check_exit_env(input_t *ptr)
{
	int i = 0;

	if (strncmp(ptr->line, "env", 3) == 0)
	{
		for (; ptr->envir[i]; i++)
		{
			write(1, ptr->envir[i], strlen(ptr->envir[i]));
			_putchar('\n');
		}
		return (0);
	}
	if (strncmp(ptr->line, "exit", 4) == 0)
	{
		free_argument(ptr);
		free(ptr->line);
		exit(ptr->er_code);
	}
	return (1);
}
