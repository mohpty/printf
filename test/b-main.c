#include <stdio.h>
#include "../main.h"

int main(void)
{
	int n, m, x;

	n = _printf("%b\n", 0);	
	m = _printf("%b\n", 64);
	x = _printf("%b\n", 8);
	printf("first: %d\nsecond: %d\nthird: %d\n", n, m, x);

	return (0);
}
