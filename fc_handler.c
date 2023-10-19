#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int nums_convs(const char *format, unsigned int fc_ptr, va_list *list);
int char_specs(const char *format, unsigned int fc_ptr, va_list *list);
int print_specifier(const char *format, unsigned int fc_ptr);
/**
 * fc_handler - determine the format specifier and handle it
 * @format: main string from the driver function
 * @fc_ptr: pointer to the end of the format specifier
 * @list: pointer to the list of arguments
 * Return: number of characters printed
 */
int fc_handler(const char *format, unsigned int fc_ptr, va_list *list)
{
	int check_numconvs = nums_convs(format, fc_ptr, list);
	int check_chars = char_specs(format, fc_ptr, list);

	if (check_numconvs)
		return (check_numconvs);
	else if (check_chars)
		return (check_chars);
	else
		return (print_specifier(format, fc_ptr));
	return (0);
}

/**
 * print_specifier - print format specifier literally if it's not supported
 * @format: printf format
 * @fc_ptr: index of the last character in the format specifier
 * Return: number of characters printed
 */
int print_specifier(const char *format, unsigned int fc_ptr)
{
	unsigned int i;
	int counter = 0;

	i = fc_ptr;
	if (format[fc_ptr] == '\0')
		fc_ptr--;

	while (format[i] != '%')
		i--;

	for (; i <= fc_ptr; i++)
		counter += _putchar(format[i]);

	return (counter);
}

/**
 * nums_convs - check for number conversion format specifiers
 * @format: general format of printf call
 * @fc_ptr: pointer to the end of the specifier
 * @list: argument lists
 * Return: number of characters printer
 */
int nums_convs(const char *format, unsigned int fc_ptr, va_list *list)
{
	/*
	 * unsigned int i = fc_ptr;
	 * int l, h;
	 * l = h = 0;
	 * while (format[i] != '%')
	 * {
	 * if (format[i] == 'l')
	 * l = 0;
	 * else if (format[i] == 'h')
	 * h = 0;
	 * i--;
	 * }
	 */
	switch (format[fc_ptr])
	{
		case 'd':
		case 'i':
			return (fc_d_i(va_arg(*list, int), fc_ptr, format));
		case 'u':
			return (fc_u(va_arg(*list, unsigned int)));
		case 'o':
			return (fc_o(va_arg(*list, unsigned int), fc_ptr, format));
		case 'x':
			return (fc_x(va_arg(*list, unsigned int), 0, fc_ptr, format));
		case 'X':
			return (fc_x(va_arg(*list, unsigned int), 1, fc_ptr, format));
		case 'b':
			return (1 + fc_b(va_arg(*list, unsigned int)));
	}

	return (0);
}



/**
 * char_specs - check for character format specifiers
 * @format: general format of printf call
 * @fc_ptr: pointer to the end of the specifier
 * @list: argument lists
 * Return: number of characters printer
 */
int char_specs(const char *format, unsigned int fc_ptr, va_list *list)
{

	switch (format[fc_ptr])
	{
		case 'c':
			return (fc_c(va_arg(*list, int)));
		case 's':
			return (fc_s(va_arg(*list, char *)));
		case 'S':
			return (fc_S(va_arg(*list, char *)));
		case '%':
			return (_putchar('%'));
		case 'r':
			return (fc_r(va_arg(*list, char *)));
		case 'R':
			return (fc_R(va_arg(*list, char *)));
		default:
			return (0);
	}

}
