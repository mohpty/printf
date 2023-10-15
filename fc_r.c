#include "main.h"

/**
 * fc_r - handle the %r custom specifier
 * which reverse a string
 * @s: string to be printed
 * Return: 1 always
 */
int fc_r(char *s)
{
	int len = 0;
	int i;

	while (s[len] != '\0')
		len++;

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	return (len);
}
