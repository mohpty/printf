#include "main.h"

/**
 * fc_R - handle the %R custom specifier
 * which encrypt the string using ROT13 cipher.
 * @s: string to be encrypted
 * Return: 1 always
 */
int fc_R(char *s)
{
	char chr;
	int i = 0;

	while (s[i] != '\0')
	{
		chr = s[i];
		if (s[i] >= 65 && s[i] <= 90)
		{
			/* handling Upper case letters */
			chr += 13;
			if (chr > 90)
				chr -= 26;

		}
		else if (s[i] >= 97 && s[i] <= 122)
		{
			/* handling Lower case letters */
			chr += 13;
			if (chr > 122)
				chr -= 26;

		}

		_putchar(chr);
		i++;
	}

	return (i);
}
