#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;


	cnt1 = _printf("% i,% i\n", 'a', 0x1A);
	cnt2 =printf("% i,% i\n", 'a', 0x1A);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	return (0);
}
