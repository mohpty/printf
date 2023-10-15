#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *binary_arr(unsigned n)
{
	char *p;
	int i;
	
	i = 0;
	p = (char *) malloc(sizeof(int) * 32);
	while (n)
	{
		p[i++] = (n % 2) + '0';
		n /= 2;
	}
	
	return (p);
}

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

int fc_b(unsigned int b)
{
	int cnt = 0;
	char *arr;

	arr = binary_arr(b);
	cnt = print_binary(arr) - 1;
	
	return (cnt);
}
