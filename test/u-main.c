#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;
	
	cnt1 = _printf("Hello there %u, %u, %u\n", 0xAF, 0101, 022);
	cnt2 = printf("Hello there %u, %u, %u\n", 0xAF, 0101, 022);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	return (0);
}
