#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_arr - Function to convert an unsigned integer to a binary string
 * @n: The unsigned integer to convert.
 *
 * Return: A pointer to the binary string.
 */

char *binary_arr(unsigned int n)
{
	char *p;
	int i;

	i = 0;
	p = (char *) malloc(sizeof(int) * 32);

	if (p == NULL)
		return (NULL);

	while (n)
	{
		p[i++] = (n % 2) + '0';
		n /= 2;
	}


	return (p);
}

/**
 * print_binary - function to print the binary string
 * @arr: the binary string to pass in
 * Return: Always 0
 */

int print_binary(char *arr)
{
	int x;

	if (*arr != '\0')
	{
		x = print_binary(arr + 1);
		return (x + _putchar(*arr));
	}

	return (0);
}

/**
 * fc_b - function to print the binary
 * @b: the unsigned integer to convert and print
 * Return: The number of characters printed
 */

int fc_b(unsigned int b)
{
	int cnt = 0;
	char *arr;

	if (b == 0)
	{
		_putchar('0');
		return (0);
	}
	arr = binary_arr(b);

	if (arr == NULL)
		return (0);

	cnt = print_binary(arr) - 1;

	free(arr);

	return (cnt);
}
