#include "main.h"
#include <stdarg.h>
#include <stdlib.h>


/**
 * nums_convs - check for number conversion format specifiers
 * @format: general format of printf call
 * @fc_ptr: pointer to the end of the specifier
 * @list: argument lists
 * Return: number of characters printer
 */
int nums_convs(const char* format, unsigned int fc_ptr, va_list *list)
{
	unsigned int i = fc_ptr;
	int l = 0, h = 0;

	while (format[i] != '%')
	{
		if (format[i] == 'l')
			l = 0;
		else if (format[i] == 'h')
			h = 0;
		i--;
	}
	switch (format[fc_ptr])
	{
		case 'd':
		case 'i':
			if (l)
				return (fc_d_i(va_arg(*list, long int), fc_ptr, format));
			else if (h)
				return (fc_d_i(va_arg(*list, short int), fc_ptr, format));
			else
				return (fc_d_i(va_arg(*list, int), fc_ptr, format));
			break;
		case 'u':
			if (l)
				return (fc_u(va_arg(*list, unsigned long int)));
			else if (h)
				return (fc_u(va_arg(*list, unsigned short int)));
			else
				return (fc_u(va_arg(*list, unsigned int)));
			break;
		case 'o':
			if (l)
				return (fc_o(va_arg(*list, unsigned long int), fc_ptr, format));
			else if (h)
				return (fc_o(va_arg(*list, unsigned short int), fc_ptr, format));
			else
				return (fc_o(va_arg(*list, unsigned int), fc_ptr, format));
			break;
		case 'x':
			return (fc_x(va_arg(*list, unsigned int), 0, fc_ptr, format));
			break;
		case 'X':
			return (fc_x(va_arg(*list, unsigned int), 1, fc_ptr, format));
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
			break;
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
