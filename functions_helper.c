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
char **get_arguments(char *line, char **envir)
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
	if (i == 0)
		return (NULL);
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
	args = path_handler(args, envir);
	return (args);
}
/**
 * path_handler - jx
 * @args: kjf
 * @envir: kjq
 * Return: kj
 */
char **path_handler(char **args, char **envir)
{
	int i = 0, j = 0;
	char *_path = NULL, *token = NULL, *_full_path = NULL;

	if (args[0][0] == '.' || args[0][0] == '/')
		return (args);
	else
	{
		while (envir[i])
		{
			if (strncmp(envir[i], "PATH", 4) == 0)
			{
				_path = strdup(envir[i]);
				for (; j < 5; j++)
					_path++;
				break;
			}
			i++;
		}
		token = strtok(_path, ":");
		while (token)
		{
			_full_path = (char *)malloc(sizeof(char) * (strlen(args[0]) + strlen(token) + 2));
			strcpy(_full_path, token);
			strcat(_full_path, "/");
			strcat(_full_path, args[0]);
			printf("%s\n", _full_path);
			if (access(_full_path, F_OK) == 0)
			{
				free(args[0]);
				args[0] = strdup(_full_path);
				printf("%s\n", args[0]);
				free(_full_path);
				break;		
			}
			else
			{
				token = strtok(NULL, ":");
				free(_full_path);
			}
		}
		free(_path);
	}
	return (args);
}
