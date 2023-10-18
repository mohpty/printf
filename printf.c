#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int supported_specifier(const char *format, unsigned int ptr);
int supported_flags(const char *format, unsigned int ptr);
/**
 * _printf - print a string to the stdout
 * @format: string to print with modifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0;
	unsigned int cnt = 0;
	unsigned int fcp;
	va_list list;
	
	if (format == NULL || *format == '\0')
		return (0);

	va_start(list, *format);

	while (format[i])
	{
		/* fcp = i + 1; */
		if (format[i] == '%')
		{
			for (fcp = i + 1; format[fcp] != '\0'; fcp++)
			{
				if (supported_specifier(format, fcp))
				{
					cnt += fc_handler(format, fcp, &list);
					break;
				}
				else if (supported_flags(format, fcp))
				{
					continue;
				}
				else
				{
					cnt += print_specifier(format, fcp);
					break;
				}
			}
			if (format[fcp] == '\0')
				cnt += print_specifier(format, fcp);
			
			i = fcp;
		}
		else
		{
			_putchar(format[i]);
			cnt++;
		}
		i++;
	}
	va_end(list);

	return (cnt);

}

int supported_specifier(const char *format, unsigned int ptr)
{
	char *supported = "csdibuoxXSrR";
	int i;

	for (i = 0 ; i < 12; i++)
	{
		if (supported[i] == format[ptr])
			return (1);
	}
	return (0);
}

int supported_flags(const char *format, unsigned int ptr)
{
	char *supported = "+ #0lh$-*";
	int i;

	for (i = 0; i < 9; i++)
	{
		if (format[ptr] == supported[i])
			return (1);
	}

	return (0);
}
