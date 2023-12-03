#include "main.h"

/**
 * main - a UNIX command line interpreter.
 * Return: void.
 */
int main(int ac, char **av, char **envir)
{
	ssize_t r = 0;
	char *line = NULL, **arguments;
	size_t len = 0;
	pid_t pid;
	int status = 0;
	(void)ac, (void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* intractive mode 1 // 0 non-intractive*/
			write(1, "$> ", 3);       
		r = getline(&line, &len, stdin);
		if (r == -1)
		{
			free(line);
			return (0);
		}
		line[r - 1] = '\0'; /* replace the \n*/      
		arguments = get_arguments(line, envir);
		if (arguments != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				printf("fork() failed");
				return (1);
			}
			if ((pid == 0) && (execve(arguments[0], arguments, NULL) == -1))
			{
				perror(line);
				return (1);
			}
			else
				wait(&status);
			free_argument(arguments);
		}
	}
	return (0);
}
