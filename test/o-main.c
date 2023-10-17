#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;
	cnt1 = _printf("%o\n", 0x15);
	cnt2 = printf("%o\n", 0x15);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	
	return (0);
}
