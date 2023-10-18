#include "main.h"

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

	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (; *format; format++)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'
			|| *(format + 1) == '%' || *(format + 1) == 'd' || *(format + 1) == 'i'
			|| *(format + 1) == 'b' || *(format + 1) == 'x' || *(format + 1) == 'X'))
		{
			format++;

			if (*format == '%')
			{
				putchar('%');
				count++;
				continue;
			}

			for (i = 0; handlers[i].handler; i++)
			{
				if (handlers[i].specifier == *format)
				{
					count += handlers[i].handler(args);
					break;
				}
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
