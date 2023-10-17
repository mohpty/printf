#include "main.h"

int flag_plus(int x);
int flag_space(int x);
int print_decimal(int x);

/**
 * fc_d_i - function to handle %d %i format specifier for printf
 * @x: integer to be printed
 * Return: size of integer
 */
int fc_d_i(int x, int fc_ptr, const char* format)
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


int flag_plus(int x)
{
	if (x >= 0)
		_putchar('+');
	
	return (1);
}

int flag_space(int x)
{
	if (x >= 0)
		_putchar(' ');

	return (1);

}


int print_decimal(int x)
{
	int total = 0;
	
	if (x / 10)
	{
		total += print_decimal(x / 10);
	}
	return (total + (_putchar((x % 10) + '0')));
}	
