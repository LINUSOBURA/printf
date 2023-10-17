#include "main.h"
/**
 * handle_string - function to handle string format
 * @va_list: list of arguments
 */
void handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (*str)
		{
			putchar(*str);
			str++;
			counter++;
		}
}
/**
 * handle_char - function to handle char format
 * @va_list: list of arguments
 */
void handle_char(va_list args)
{
	char c = (char) va_args(args, int);
	putchar(c);
}

void handle_d(va_list args)
{
	int d = va_arg(args, int);
	putchar(d);
}
