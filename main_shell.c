#include "main.h"

/**
 * main - a UNIX command line interpreter.
 * @av: jhf
 * @ac: di
 * @envir: uuhs
 * Return: void.
 */
int main(int __attribute__((unused)) ac, char **av, char **envir)
{
	input_t ptr;

	initializer(&ptr, av, envir);
	while (++ptr.count)
	{
		if (isatty(STDIN_FILENO)) /* intractive mode 1 // 0 non-intractive*/
			write(1, "$> ", 3);
		get_line(&ptr); /*brings line*/
		if (strlen(ptr.line))
		{
			get_arguments(&ptr); /*Analyse + divid + organise the line*/
			if (check_exit_env(&ptr))
			{
				if (!check_path(&ptr))
					fork_and_execve(&ptr);
			}
			free_argument(&ptr);
		}
		free(ptr.line);
	}
	return (ptr.er_code);
}
