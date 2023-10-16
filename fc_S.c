#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * fc_S - handle the %S conversion specifier
 * which prints the string alongside all non printable ascii
 * characters using \x[hex] format
 * @s: string to be printed
 * Return: 1 always
 */
int fc_S(char *s)
{
	int cnt = 0;

	while (*s != '\0')
	{
		if ((0 < *s && *s < 32) || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');

			if (*s < 16)
				cnt += _putchar('0');
			cnt += 2 + _printf("%X", *s);
			
		}
		else
		{
			_putchar(*s);
			cnt++;
		}
		s++;
	}
	return (cnt);
}

