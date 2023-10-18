#include "../main.h"
#include <stdio.h>

int main(void)
{
	int n1;

	n1 = _printf("%R\n", "Guvf fragrapr vf ergevrirq sebz in_netf!\n");
	printf("Ours:%d\n\n", n1);
	
	n1 = _printf("Complete the sentence: You %R nothing, Jon Snow.\n", "xabj");
	printf("Ours:%d\n\n", n1);
	
	n1 = _printf("%R\n", "ABCDEFGHIJKLMNOPQRSTUVWXYZ!?.,*&^abcdefghijklmnopqrstuvwxyz");
	printf("\n");
	return (0);
}
