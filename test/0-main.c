#include "../main.h"
#include <stdio.h>

int main(void)
{
	int x, y;

	x = _printf("hello\n");
	y = printf("hello\n");

	printf("mine: %d\nstandard: %d\n", x, y);

	return (0);
}
