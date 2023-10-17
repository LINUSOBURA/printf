#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct FormatHandler {
	char specifier;
	void (*handler)(va_list args);
} FormatHandler;

int _printf(const char *format, ...);
void handle_integer(va_list args);
void handle_string(va_list args);
void handle_char(va_list args);
extern FormatHandler handlers[];

#endif
