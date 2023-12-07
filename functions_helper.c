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
 * @envir: kjj
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
 * get_path - hdhddh
 * @env: sjjssj
 * Return: hhh
 */
char *get_path(char **env)
{
	int i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}
/**
 * path_handler - jgxk
 * @args: kjdf
 * @envir: kks
 * Return: jfjhv
*/
char **path_handler(char **args, char **envir)
{
	char *_path = NULL, *token = NULL, *_full_path = NULL;

	if (args[0][0] == '.' || args[0][0] == '/')
		return (args);

	_path = malloc(strlen(get_path(envir)) + 1);
	strcpy(_path, get_path(envir));
	/*printf("%s", _path);*/
	token = strtok(_path, ":");
	while (token)
	{
		_full_path = (char *)malloc(sizeof(char) *
						(strlen(args[0]) + strlen(token) + 2));
		strcpy(_full_path, token);
		strcat(_full_path, "/");
		strcat(_full_path, args[0]);
		/*printf("%s\n", _full_path);*/
		if (access(_full_path, F_OK) == 0)
		{
			free(args[0]);
			args[0] = strdup(_full_path);		
			free(_full_path);
			break;
		}
		else
		{
			token = strtok(NULL, ":"), free(_full_path);
		}
	}
	free(_path);
	return (args);
}
/**
 * print_error - kjh
 * @av: jkf
 * @err: jdgjh
 * @args: kjfs
 * @count: iKEFZ
 * Return: void.
*/
void print_error(char ** av, int count, char ** args, int err)
{
	write(2, av[0], strlen(av[0]));
	write(2, ": ", 2);
	print_num(count);
	write(2, ": ", 2);
	write(2, args[0], strlen(args[0]));
	if (err == 127)
		write(2, ": not found\n", 12);
	if (err == 126)
		write(2, ": Permission denied\n", 20);
}
/**
 * check_path - kjh
 * @av: jkf
 * @err: jdgjh
 * @args: kjfs
 * @count: iKEFZ
 * Return: 1 on success and 0 on failure.
*/
int check_path(char ** av, int count, char ** args)
{
	if (!((args[0][0] == '.' || args[0][0] == '/') &&
			access(args[0], F_OK) == 0))
	{
		print_error(av, count, args, 127);
		return (127);
	}
	else if (access(args[0], X_OK) == -1)
	{
		print_error(av, count, args, 126);
		return (126);
	}
	return (0);
}
