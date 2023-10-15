#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_o - print number of base 8/octal recursively
 * @n: number
 * Return: number of bytes printed
 */
int print_o(char *oct)
{
	int total = 0;
	if (*(oct + 1) != '\0')
	{
		total += print_o(oct + 1);
	}
	return (_putchar(*oct));
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
	return(print_o(oct));
}

char *ensure_octal(unsigned int n)
{
	char *oct, *bin, *p1;
	int i, len, j, coef, digit, bit;

	
	printf("||");
	bin = binary_arr(n);
	i = j = len = 0;
	
	while (bin[len])
		len++;

	oct = (char *) malloc(sizeof(char) * (len / 3) + 1);
	p1 = oct;

	while (*bin != '\0')
	{
		if (i % 3 == 0)
		{
			*p1 = digit + '0';
			printf("%d", *p1);
			p1++;
			digit = 0;
			coef = 1;
		}

		bit = (*bin == '0' ? 0 : 1);
		digit += (bit * coef);
		
		coef *= 2;
		i++;
		bin++;
	}
	printf("||\n");
	return (oct);
}
