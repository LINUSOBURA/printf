#include "main.h"

/**
 * _printf - function to print everything to the stdout
 * @format: character string
 * Return: numbers of printed characters
 * Code by Linus Obura & Felix Mukah
 */
int _printf(const char *format, ...)
{
	int printed = 0;
	va_list params;

	va_start(params, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
			}

			if (*format == 'c')
			{
				char c = va_arg(params, int);
				write(1, &c, 1);
			}

			if (*format == 's')
			{
				char *str = va_arg(params, char*);
				write(1, str, strlen(str));
				printed++;
			}

		}
	}

	va_end(params);
	return (printed);
}
