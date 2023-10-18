#include "main.h"
#include <stddef.h>
/**
 * fc_s - handle the %s conversion specifier
 * @s: string to be printed
 * Return: 1 always
 */
int fc_s(char *s)
{
	int cnt = 0;
	
	if (s == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		cnt++;
	}
	return (cnt);
}
