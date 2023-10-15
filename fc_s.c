#include "main.h"

/**
 * fc_s - handle the %s conversion specifier
 * @s: string to be printed
 * Return: 1 always
 */
int fc_s(char *s)
{
	int cnt = 0;

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		cnt++;
	}
	return (cnt);
}
