#include "main.h"

/**
 * fc_u - handle %u format specifier for the printf funcion
 * %u which convert unsigned integers to decimal
 * @n: number to be converted
 * Return: number of bytes printed
 */
int fc_u(unsigned int n)
{
	int total = 0;

	if (n / 10)
		fc_u(n / 10);
	
	total += _putchar((n % 10) + '0');
	return(total);
}
