#include "main.h"
#include <stdarg.h>

/**
 * fc_handler - determine the format specifier and handle it
 * @format: main string from the driver function
 * @fc_ptr: pointer to the end of the format specifier
 * @list: pointer to the list of arguments
 * Return: number of characters printed
 */
int fc_handler(const char* format, unsigned int fc_ptr, va_list *list)
{
	switch (format[fc_ptr])
	{
		case 'd':
		case 'i':
			return fc_d_i(va_arg(*list, int));
			break;
		case 'u':
			return (1 + fc_u(va_arg(*list, unsigned int)));
			break;
		case 'o':
			return (1 + fc_o(va_arg(*list, unsigned int)));
			break;
		default:
			return (0);
	}
}
