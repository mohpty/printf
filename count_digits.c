#include "main.h"

/**
 * count_digits - count the number of digits
 * @n: number
 * Return: number of digits of the number
 *
 */
int count_digits(unsigned int n)
{

	if (n / 10)
		return (1 + count_digits(n / 10));

	return (1);
}
