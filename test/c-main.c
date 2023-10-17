#include "../main.h"
#include <stdio.h>

int main(void)
{
	int n,m;

	n = _printf("no more %% to say %c\n", 'c');
	m = printf("no more %% to say %c\n", 'c');
	
	printf("ours:%d\nstandard:%d\n", n, m);
	return (0);
}
