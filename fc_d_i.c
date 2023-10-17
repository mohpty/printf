#include "main.h"

/**
 * fc_d_i - function to handle %d %i format specifier for printf
 * @x: integer to be printed
 * Return: size of integer
 */
int fc_d_i(int x)
{
	unsigned int number;
	int cnt = 0;

	if (x < 0)
	{
		number = -x;
		cnt += _putchar('-');
	}
	else
	{
		number = x;
	}

	if (number / 10)
		fc_d_i(number / 10);

	cnt += _putchar((number % 10) + '0');
	return (cnt);
}
