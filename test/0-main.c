#include "../main.h"
#include <stdio.h>

int main(void)
{
	int x, y;

	x = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	y = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("Mine: %d, Standard: %d\n", x, y);
	
	x = _printf(NULL);
	printf("Size: %d\n", x);
	
	x = _printf("%");
	printf("Size: %d\n", x);
	
	x = _printf("%!\n");
	printf("Mine: %d\n\n", x);
	
	x = _printf("%K\n");
	printf("Mine: %d\n\n", x);
	return (0);
}
