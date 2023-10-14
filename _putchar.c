#include <unistd.h>
#include "main.h"

/**
 * _putchar - print a character
 * @c: the character
 * Return: 1 if correct and -1 if error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
