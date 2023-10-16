#include <stdio.h>
#include "../main.h"

int main(void)
{
	int cnt1, cnt2;


	cnt1 = _printf("% i,% i\n", -15, 15);
	cnt2 =printf("% i,% i\n", -15, 15);
	printf("ours:%d\nstandard:%d\n", cnt1, cnt2);
	return (0);
}
