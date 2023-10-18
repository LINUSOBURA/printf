#include "main.h"
int is_valid_specifier(char c);
/**
* _printf - function to print everything to stdout
* @format: format string
* Return: numbers of printed characters
* Code by Linus Obura & Felix Mukah, refactored
*/
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	int handler_found;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
			{
				break;
			}
			handler_found = 0;

			for (i = 0; handlers[i].handler; i++)
			{
				if (handlers[i].specifier == *format)
				{
					count += handlers[i].handler(args);
					handler_found = 1;
					break;
				}
			}

			if (!handler_found)
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
	}
	va_end(args);
	return (count);
}

int is_valid_specifier(char c)
{
	int i;

	char valid_specifiers[] = "csdibxX";
	for (i = 0; valid_specifiers[i]; i++)
		{
			if (c == valid_specifiers[i])
				return (1);
		}
	return (0);
}
