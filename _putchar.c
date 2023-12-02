#include "main.h"

/**
 * _putchar - write a character.
 * @c: the character to print.
 * Return: 1 in success.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}