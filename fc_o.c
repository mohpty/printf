#include "main.h"

/**
 * fc_o - handle %o format specifier for the printf function
 * %o which convert unsigned integers to octal
 * @n: number to be converted
 * Return: number of bytes printed
 */
int fc_o(unsigned int n)
{
	int total = 0;

	if (n / 8)
		fc_o(n / 8);

	total += _putchar((n % 8) + '0');
	return(total);
}
