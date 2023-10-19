#include <stdio.h>
#include "../main.h"
#include <limits.h>

int main(void)
{
	int cnt1, cnt2,x;


	cnt1 = _printf("% i,% i\n", 'a', 0x1A);
	cnt2 = printf("% i,% i\n", 'a', 0x1A);
	printf("ours:%d\nstandard:%d\n\n", cnt1, cnt2);


	cnt1 = _printf("%+d\n", -1024);
	cnt2 = printf("%+d\n", -1024);
	printf("ours:%d\nstandard:%d\n\n", cnt1, cnt2);
	
	x = -1 * INT_MIN;
	cnt1 = _printf("%d\n", x);
	cnt2 = printf("%d\n", x);
	printf("ours:%d\nstandard:%d\n\n", cnt1, cnt2);
	return (0);
}
