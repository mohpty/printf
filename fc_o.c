#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int oflag_hash(char *oct);


/**
 * print_octal - print number of base 8/octal recursively
 * @arr: array of octal number digits
 *
 * Return: number of bytes printed
 */
int print_octal(char *arr)
{
	int total = 0;

	if (*arr != '\0')
	{
		total += print_octal(arr + 1);
		_putchar(*arr);
		return (total + 1);
	}
	return (0);
}
/**
 * fc_o - handle %o format specifier for the printf function
 * @x: number to be converted
 * @fc_ptr: pointer to %o format specifier, used for flag checks
 * @format: format of printf
 * Return: number of bytes printed
 */
int fc_o(unsigned int x, int fc_ptr, const char *format)
{
	char *oct;
	unsigned int i;
	int bytes;

	i = fc_ptr;
	bytes = 0;

	oct = ensure_octal(x);
	/* handle flags */
	while (format[i] != '%')
	{
		switch (format[i])
		{
			case '#':
				bytes += oflag_hash(oct);
		}

		i--;
	}
	return (bytes + print_octal(oct));
}

/**
 * oflag_hash - perform # flag function in format specifier %o
 * @oct: digits of oct number
 * Return: always 2
 */
int oflag_hash(char *oct)
{
	unsigned int i = 0;

	while (oct[i])
		i++;

	if (oct[i - 1] != 0)
		_putchar('0');

	return (1);
}

/**
 * ensure_octal - converts an unsigned integer to octal
 * @n: The integer to convert
 *
 * Return: character converted
 */
char *ensure_octal(unsigned int n)
{
	char *bin, *oct;
	unsigned int i, j, len, idx;
	int bit, digit;

	len = 0;
	/* convert number to binary char array */
	bin = binary_arr(n);

	/* make sure the number of digits is divisable by 3 */
	i = j = len = 0;

	while (bin[len])
		len++;

	i = len;
	while (i % 3 != 0)
		bin[i++] = '0';

	oct = (char *) malloc(sizeof(char) * i + 1);

	/* calculate each digit and fill octal char array (it'll be in reverse)*/
	idx = 0;
	for (j = 0; j < i; j += 3)
	{
		digit = 0;
		bit = (bin[j] == '0' ? 0 : 1);
		digit += bit * 1;

		bit = (bin[j + 1] == '0' ? 0 : 1);
		digit += bit * 2;

		bit = (bin[j + 2] == '0' ? 0 : 1);
		digit += bit * 4;

		oct[idx] = digit + '0';
		idx++;
	}
	return (oct);
}
