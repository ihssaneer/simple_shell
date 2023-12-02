#include "main.h"

/**
 * main - a UNIX command line interpreter.
 * Return: void.
 */
int main(void)
{
    ssize_t r = 0;
    char *line = NULL, **arguments;
    size_t len = 0;
    pid_t pid;
    int status = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* intractive mode 1 // 0 non-intractive*/
            write(1, "$> ", 3);
        r = getline(&line, &len, stdin);
        if (r == -1)
        {
            _putchar('\n');
            free(line);
            return (1);
        }
        line[r - 1] = '\0'; /* replace the \n*/
        arguments = get_arguments(line);
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
