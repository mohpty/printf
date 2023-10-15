#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;

	cnt1 = _printf("%o\n", 03717);
	cnt2 = printf("%o\n", 03717);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	
	cnt1 = _printf("%o\n", 07);
	cnt2 = printf("%o\n", 07);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);

	cnt1 = _printf("%o\n", 077);
	cnt2 = printf("%o\n", 077);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	return (0);
}
