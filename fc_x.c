#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int flag_hash(int cap);
/**
 * print_o - print number of base 8/octal recursively
 * @n: number
 * Return: number of bytes printed
 */
int print_hex(char *arr, int cap)
{   
	int total = 0;
	if (*arr != '\0')
	{
		total += print_hex(arr + 1, cap);
		if (cap && (*arr >= 97 && * arr <= 122 ))
			_putchar(*arr - 32);
		else
			_putchar(*arr);
		return (total + 1);
	}
	return (0);
}

/**
 * fc_o - handle %o format specifier for the printf function
 * @n: number to be converted
 * Return: number of bytes printed
 */
int fc_x(unsigned int n, int cap, int fc_ptr, const char *format)
{
	char *hex;
	int bytes = 0, i = fc_ptr;
	hex = ensure_hex(n);
	/* check for flags */
	while (format[i] != '%')
	{
		switch (format[i])
		{
			case '#':
				if (n == 0)
					break;
				bytes += flag_hash(cap);
				break;
			default:
				break;
		}
		i--;
	}
	return(bytes + print_hex(hex, cap));
}

int flag_hash(int cap)
{
	_putchar('0');
	if (cap)
		_putchar('X');
	else
		_putchar('x');

	return (2);
}

/**
 * ensure_hex - ensure than the value of n is in base 8
 * @n: number in unknown base
 * Return: pointer to array of chars
 */
char *ensure_hex(unsigned int n)
{
	char *bin, *hex;
	unsigned i, j, len, idx;
	int bit, digit;

	len = 0;
	/* convert number to binary char array */
	bin = binary_arr(n);

	/* make sure the number of digits is divisable by 4 */
	while (bin[len] != '\0')
		len++;

	i = len;
	while (i % 4 != 0)
		bin[i++] = '0';

	hex = (char *) malloc(sizeof(char) * i + 1);
	idx = 0;

	/* calculate each digit and fill octal char array (it'll be in reverse)*/
	idx = 0;
	for (j = 0; j < i; j += 4)
	{
		digit = 0;
		bit = (bin[j] == '0' ? 0 : 1);
		digit += bit * 1;

		bit = (bin[j + 1] == '0' ? 0 : 1);
		digit += bit * 2;

		bit = (bin[j + 2] == '0' ? 0 : 1);
		digit += bit * 4;

		bit = (bin[j + 3] == '0' ? 0 : 1);
		digit += bit * 8;
		
		if (digit >= 10)
		{
			hex[idx] = (digit - 10) + 97;
		}
		else
		{
			hex[idx] = digit + '0';
		}
		idx++;
	}
	return (hex);
}
