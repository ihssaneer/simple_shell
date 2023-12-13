#include "main.h"

void dte_space(char *str)
{
	int i = 0, j = 0;

	while ((*(str + i) == ' ' || *(str + i) == '\t') && *(str + i))
		i++;
	while (*(str + i) && *(str + j))
	{
		*(str + j) = *(str + i);
		i++;
		j++;
	}
	*(str + j) = '\0';
}
