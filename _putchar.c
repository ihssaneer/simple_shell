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
/**
 * _putchar - write a character.
 * @c: the character to print.
 * Return: 1 in success.
 */
int put_err(char c)
{
	return (write(2, &c, 1));
}
/**
 * print_num - Prints a positive integer to stdout
 * @num: The positive integer to print
 * Return: Number of characters printed, excluding null byte.
 */
int print_num(unsigned int num)
{
	unsigned int num_tmp = num, i = 1;
	int lenth = 0;

	while (num_tmp / 10)
	{
		num_tmp /= 10;
		i *= 10;
	}
	for (; i >= 1; i /= 10)
	{
		num_tmp = num / i;
		num -= (i * num_tmp);
		lenth += put_err(num_tmp + '0');
	}
	return (lenth);
}