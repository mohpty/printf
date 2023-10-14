#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int fc_d_i(int x);
int fc_u(unsigned int x);
int fc_o(unsigned int x);
int fc_handler(const char* format, unsigned int fc_ptr, va_list *list);
int is_binary(unsigned int n);
#endif
