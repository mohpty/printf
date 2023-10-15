#include "../main.h"
#include <stdio.h>

int main(void)
{
	int n, m;

	n = _printf("another brick in the wall, %s\n", "solo goes here");
	m = printf("another brick in the wall, %s\n", "solo goes here");

	printf("Ours: %d\n,Standard: %d\n", n, m);
	return (0);
}
