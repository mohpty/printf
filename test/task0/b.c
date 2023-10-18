#include <stdio.h>
#include "../../main.h"

int main(void)
{
	int cnt1, cnt2;
	
	cnt1 = _printf("%%%\n");
	cnt2 = _printf("%%%\n");
	printf("Ours: %d\tStandard: %d\n", cnt1, cnt2);
	return (0);
}
