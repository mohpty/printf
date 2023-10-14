#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;

	cnt1 = _printf("Hello there %o\n", 055);
	cnt2 = printf("Hello there %o\n", 055);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	return (0);
}
