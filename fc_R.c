#include "main.h"
#include <stdio.h>

/**
 * fc_R - handle the %R custom specifier
 * which encrypt the string using ROT13 cipher.
 * @s: string to be encrypted
 * Return: 1 always
 */
int fc_R(char *s)
{
	int chr;
	int i = 0;

	while (s[i])
	{
		chr = s[i] + 13;

		if (s[i] >= 65 && s[i] <= 90)
			chr = (chr > 90 ? chr - 26 : chr);

		else if (s[i] >= 97 && s[i] < 123)
			chr = (chr > 122 ? chr - 26 : chr);

		else
			chr = s[i];

		_putchar(chr);
		i++;
	}
	return (i);
}
