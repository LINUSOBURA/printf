#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct FormatHandler {
	char specifier;
	int (*handler)(va_list args);
} FormatHandler;

int _printf(const char *format, ...);
int handle_integer(va_list args);
int handle_string(va_list args);
int handle_char(va_list args);
int recursive_print_integer(int n);
extern FormatHandler handlers[];

#endif
