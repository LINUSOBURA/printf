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

FormatHandler handlers[] = {
	{'s', handle_string},
	{'c', handle_char},
	{'d', handle_d},
	{'i', handle_i},
	{0, NULL}
};
int _printf(const char *format, ...);

#endif
