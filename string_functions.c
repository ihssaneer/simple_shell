#include "main.h"
/**
 * space_remover - function that delet the spaces from line.
 * @str: line.
 * Return: void.
*/
void space_remover(char *str)
{
	int i = 0, j = 0;

	while ((*(str + i) == ' ' || *(str + i) == '\t') && *(str + i))
		i++;
	for (; *(str + i) && *(str + j); i++, j++)
		*(str + j) = *(str + i);
	*(str + j) = '\0';
}
