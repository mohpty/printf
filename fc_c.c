#include "main.h"

/**
 * fc_c - handle the %c conversion specifier
 * @c: character to print
 * Return: 1 always
 */
int fc_c(unsigned char c)
{
	_putchar(c);
	return (1);
}
