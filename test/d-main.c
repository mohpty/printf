#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;

	cnt1 = _printf("hello there this is my %i last resort\n the number is \t%d\n", 5, 10);
	cnt2 = printf("hello there this is my %d last resort\n the number is \t%d\n", 5, 10);

	_printf("%i%i\n", 15, 15);
	printf("%d%d\n", 15, 15);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	return (0);
}
