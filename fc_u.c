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


/**
 * ensure_decimal - function to ensure parameter passed in is decimal
 * @n: unsigned int to check
 *
 * Return: the output of the parameter
 */
int ensure_decimal(unsigned int n)
{
	char *bin;
	int i, coff, output = 0;
	int bit;

	i = 0;
	coff = 1;

	bin = binary_arr(n);

	while (bin[i] != '\0')
	{
		if (bin[i] == '0')
			bit = 0;
		else
			bit = 1;

		output += (coff * bit);
		coff *= 2;
		i++;
	}

	return (output);
}
