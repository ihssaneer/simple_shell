#include "main.h"

/* Function 1/5 : */
/**
 * initializer - ofh
 * @ptr: kjrn
 * @av: jyfi
 * @envir: heg
 * Return: kjfhwx
 */
void initializer(input_t *ptr, char **av, char **envir)
{
	ptr->count = 0;
	ptr->av = av;
	ptr->line = NULL;
	ptr->args = NULL;
	ptr->envir = envir;
	ptr->er_code = 0;
}

/* Function 2/5 : */
/**
 * get_line - jdfhhfjsh
 * @ptr: jhf
 * Return: jhhfgh
 */
void get_line(input_t *ptr)
{
	ssize_t r = 0;
	size_t len = 0;

	r = getline(&ptr->line, &len, stdin);
	if (r == -1)
	{
		free(ptr->line);
		exit(ptr->er_code);
	}
	ptr->line[r - 1] = '\0'; /* replace the \n*/
}
/* Function 3/5 : */
/**
 * get_arguments - eee
 * @ptr: jhf
 * Return: ddddd
 */
void get_arguments(input_t *ptr)
{
	int i = 0;
	char *word, *_line;

	_line = strdup(ptr->line);
	word = strtok(_line, " \t");
	while (word)
	{
		i++;
		word = strtok(NULL, " \t");
	}
	free(_line);
	if (i == 0)
		return;
	ptr->args = malloc(sizeof(char *) * (i + 1));
	i = 0;
	word = strtok(ptr->line, " \t");
	while (word)
	{
		ptr->args[i] = strdup(word);
		i++;
		word = strtok(NULL, " \t");
	}
	ptr->args[i] = NULL;
	path_handler(ptr);
}
/* Function 4/5 : */
/**
 * path_handler - jgxk
 * @ptr: kjdf
 * Return: jfjhv
 */
void path_handler(input_t *ptr)
{
	char *_path = NULL, *token = NULL, *_full_path = NULL;

	if (ptr->args[0][0] == '.' || ptr->args[0][0] == '/')
		return;
	_path = malloc(strlen(get_path(ptr)) + 1);
	strcpy(_path, get_path(ptr));
	token = strtok(_path, ":");
	while (token)
	{
		_full_path = (char *)malloc(sizeof(char) *
				(strlen(ptr->args[0]) + strlen(token) + 2));
		strcpy(_full_path, token);
		strcat(_full_path, "/"), strcat(_full_path, ptr->args[0]);
		if (access(_full_path, F_OK) == 0)
		{
			free(ptr->args[0]), ptr->args[0] = strdup(_full_path), free(_full_path);
			break;
		}
		else
			token = strtok(NULL, ":"), free(_full_path);
	}
	free(_path);
}
/* Function 5/5 : */
/**
 * get_path - hdhddh
 * @ptr: sjjssj
 * Return: hhh
 */
char* get_path(input_t *ptr)
{
	int i = 0;

	while (ptr->envir[i])
	{
		if (strncmp(ptr->envir[i], "PATH=", 5) == 0)
			return (ptr->envir[i] + 5);
		i++;
	}
	return (NULL);
}