#include "../main.h"
#include <stdio.h>

int main(void)
{
	int n1;

	n1 = _printf("%R\n", "blob");
	
	printf("Ours:%d\n", n1);

	return (0);
}
