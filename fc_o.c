#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_o - print number of base 8/octal recursively
 * @n: number
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
 * @n: number to be converted
 * Return: number of bytes printed
 */
int fc_o(unsigned int n)
{
	char *oct;

	oct = ensure_octal(n);
	return(print_octal(oct));
}

/**
 * ensure_octal - ensure than the value of n is in base 8
 * @n: number in unknown base
 * Return: pointer to array of chars
 */
char *ensure_octal(unsigned int n)
{
	char *bin, *oct;
	unsigned i, j, len, idx;
	int bit, digit;

	len = 0;
	/* convert number to binary char array */
	bin = binary_arr(n);

	/* make sure the number of digits is divisable by 3 */
	while (bin[len] != '\0')
		len++;

	i = len;
	while (i % 3 != 0)
		bin[i++] = '0';

	oct = (char *) malloc(sizeof(char) * i + 1);
	idx = 0;

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
