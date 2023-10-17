#include <stdio.h>
#include "../main.h"

int main(void)
{
	int x,y;

	x = _printf("decimal: %i, Hex:%x\n", 242, 242);
	y = printf("decimal: %i, Hex:%x\n", 242, 242);
	
	printf("Ours: %d Standard: %d\n", x, y);

	x = _printf("decimal: %i, Hex:%X\n", 242, 242);
	y = printf("decimal: %i, Hex:%X\n", 242, 242);

	printf("Ours: %d Standard: %d\n", x, y);
	return (0);
}
