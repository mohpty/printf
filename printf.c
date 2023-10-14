#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

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
	
	va_start(list, *format);
	while (format[i])
	{
		fcp = i;
		if (format[i] == '%')
		{
			while (!((format[fcp] >= 65 && format[fcp] <= 90) || (format[fcp] >= 97 && format[fcp] <= 122)))
				fcp++;
			cnt += fc_handler(format, fcp, &list);
			i = fcp;
		}
		else
		{
			_putchar(format[i]);
			cnt++;
		}
		i++;
	}	

	return (cnt + 1);

}
