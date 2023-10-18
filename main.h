#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_specifier(const char *format, unsigned int fc_ptr);
int print_decimal(int x);
int print_binary(char *arr);
int print_octal(char *arr);
int print_hex(char *arr, int cap);
int ensure_decimal(unsigned int n);
char *ensure_hex(unsigned int n);
int fc_x(unsigned int n, int cap, int fc_ptr, const char *format);
char *ensure_octal(unsigned int n);
char *binary_arr(unsigned int n);
int fc_d_i(int x, int fc_ptr, const char *format);
int fc_r(char *s);
int fc_R(char *s);
int fc_c(unsigned char c);
int fc_s(char *s);
int fc_S(char *s);
int fc_u(unsigned int x);
int fc_o(unsigned int x, int fc_ptr, const char *format);
int fc_b(unsigned int n);
int fc_handler(const char *format, unsigned int fc_ptr, va_list *list);
int count_digits(unsigned int n);
#endif
