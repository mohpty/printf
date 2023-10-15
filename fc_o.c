#include "main.h"

/**
 * print_o - print number of base 8/octal recursively
 * @n: number
 */
void print_o(unsigned int n)
{
	if (n / 8)
		fc_o(n / 8);
	_putchar((n % 8) + '0');
}

/**
 * fc_o - handle %o format specifier for the printf function
 * @n: number to be converted
 * Return: number of bytes printed
 */
int fc_o(unsigned int n)
{
	print_o(n);
	return(count_digits(n) - 1);
}
