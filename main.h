#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef struct FormatHandler {
	char specifier;
	int (*handler)(va_list args);
} FormatHandler;

int _printf(const char *format, ...);
int handle_integer(va_list args);
int handle_string(va_list args);
int handle_char(va_list args);
void recursive_print_integer(int n, int *count);
int handle_binary(va_list args);
void recursive_print_binary(unsigned int n, int *count);
int handle_hex(va_list args, int uppercase);
void recursive_print_hex(unsigned int n, int uppercase, int *count);
int handle_unsigned(va_list args);
void recursive_print_unsigned(unsigned int n, int *count);
int handle_octal(va_list args);
void recursive_print_octal(unsigned int n, int *count);

extern FormatHandler handlers[];

#endif
