#include "main.h"

/**
 * free_argument - eee
 * @args: ddd
 */
void free_argument(char **args)
{
    int i;

    if (args == NULL)
        return;
    for (i = 0; args[i] != NULL; i++)
    {
        free(args[i]);
    }
    free(args);
}
/**
 * get_arguments - eee
 * @line: ddd
 * Return: ddddd
 */
char **get_arguments(char *line)
{
    int i = 0;
    char *word, **args, *_line;

    _line = strdup(line);
    word = strtok(_line, " \t");
    while (word)
    {
        i++;
        word = strtok(NULL, " \t");
    }
    free(_line);
    args = malloc(sizeof(char *) * (i + 1));
    i = 0;
    word = strtok(line, " \t");
    while (word)
    {
        args[i] = strdup(word);
        i++;
        word = strtok(NULL, " \t");
    }
    args[i] = NULL;
    return (args);
}
