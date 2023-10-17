#include "main.h"

int flag_plus(int x);
int flag_space(int x);
int print_decimal(int x);

/**
 * fc_d_i - function to handle %d %i format specifier for printf
 * @x: integer to be printed
 * @fc_ptr: pointer to format to check for flags
 * @format: pointer to printing format containing format specifiers
 * Return: size of integer
 */
int fc_d_i(int x, int fc_ptr, const char *format)
{
	unsigned int number;
	int cnt = 0;
	int i = fc_ptr;

	/* check for flags first */
	while (format[i] != '%')
	{
		switch (format[i])
		{
			case '+':
				cnt += flag_plus(x);
				break;
			case ' ':
				cnt += flag_space(x);
				break;
			default:
				break;
		}

		i--;
	}
	/* Perform the formatting*/
	if (x < 0)
	{
		number = -x;
		_putchar('-');
	}
	else
	{
		number = x;
	}
	cnt += print_decimal(number);
	return (cnt);
}

/**
 * flag_plus - perform + flag
 * which precede positive numbers with +
 * @x: number to be checked
 * Return: 1 if positive, 0 otherwise
 */
int flag_plus(int x)
{
	if (x >= 0)
		_putchar('+');
	return (x >= 0 ? 1 : 0);
}

/**
 * flag_space - perform ' ' flag
 * which precede positive numbers with ' '
 * @x: number to be printed
 * Return: 1 if positive, 0 otherwise
 */
int flag_space(int x)
{
	if (x >= 0)
		_putchar(' ');

	return (1);

}

/**
 * print_decimal - used to print decimal numbers recursively
 * @x: number to be printed
 * Return: number of digits of x
 */
int print_decimal(int x)
{
	int total = 0;

	if (x / 10)
	{
		total += print_decimal(x / 10);
	}
	return (total + (_putchar((x % 10) + '0')));
}
