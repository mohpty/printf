#include "main.h"
#include <stdarg.h>

/**
 * nums_convs - check for number conversion format specifiers
 * @format: general format of printf call
 * @fc_ptr: pointer to the end of the specifier
 * @list: argument lists
 * Return: number of characters printer
 */
int nums_convs(const char* format, unsigned int fc_ptr, va_list *list)
{
	switch (format[fc_ptr])
	{
		case 'd':
		case 'i':
			return (fc_d_i(va_arg(*list, int)));
			break;
		case 'u':
			return (fc_u(va_arg(*list, unsigned int)));
			break;
		case 'o':
			return (fc_o(va_arg(*list, unsigned int)));
			break;
		case 'x':
			return (fc_x(va_arg(*list, unsigned int), 0));
			break;
		case 'X':
			return (fc_x(va_arg(*list, unsigned int), 1));
		case 'b':
			return (fc_b(va_arg(*list, unsigned int)));
			break;
	}

	return (0);
}

/**
 * fc_handler - determine the format specifier and handle it
 * @format: main string from the driver function
 * @fc_ptr: pointer to the end of the format specifier
 * @list: pointer to the list of arguments
 * Return: number of characters printed
 */
int fc_handler(const char* format, unsigned int fc_ptr, va_list *list)
{
	int check_numconvs = nums_convs(format, fc_ptr, list);
	if (check_numconvs)
		return (check_numconvs);

	switch (format[fc_ptr])
	{
		case 'c':
			return fc_c(va_arg(*list, int));
			break;
		case 's':
			return fc_s(va_arg(*list, char *));
			break;
		case 'S':
			return fc_S(va_arg(*list, char *));
		case '%':
			return (_putchar('%'));
			break;
		case 'r':
			return (fc_r(va_arg(*list, char *)));
			break;
		case 'R':
			return (fc_R(va_arg(*list, char *)));
			break;
		default:
			return (0);
	}
}
