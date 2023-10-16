#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;
	cnt1 = _printf("%x\n", 1000);
	cnt2 = printf("%x\n", 1000);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	
	cnt1 = _printf("%X\n", 1000);
	cnt2 = printf("%X\n", 1000);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	
	return (0);
}
