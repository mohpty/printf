#include "main.h"

/**
 * is_binary - check if the number consist only of 0 and 1
 * @n: the number to be tested
 * Return: 1 if true, 0 otherwise
 */
int is_binary(unsigned int n)
{
	while (n)
	{
		if (n % 10 != 0 && n % 10 != 1)
			return (0);
		
		n /= 10;
	}
	return (1);
}
