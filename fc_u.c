#include "main.h"


/**
 * print_u - print base 10 integer recursively
 * @n: number in base 10
 */
void print_u(unsigned int n)
{
	if (n / 10)
		print_u(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * fc_u - handle %u format specifier for the printf funcion
 * %u which convert unsigned integers to decimal
 * @n: number to be converted
 * Return: number of bytes printed
 */
int fc_u(unsigned int n)
{
	int number;

	number = ensure_decimal(n);

	print_u(number);
	return (count_digits(number));
}

int ensure_decimal(unsigned int n)
{
	char *bin;
	int i, coff, output = 0;

	i = 0;
	coff = 1;

	bin = binary_arr(n);
	
	while (bin[i++])
	{
		output += (coff * bin[i]);
		coff *= 2;
	}

	return (output);
}
