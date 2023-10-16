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
	int len;
	va_list params;
	char c, *str;

	va_start(params, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed++;
			format++;
		}
		else
		{
			format++;
			switch (*format)
				{
					case '%':
						{
							write(1, format, 1);
							printed++;
							format++;
							break;
						}
					case 'c':
						{
							c = va_arg(params, int);
							write(1, &c, 1);
							printed++;
							format++;
							break;
						}
					case 's':
						{
							str = va_arg(params, char*);
							len = strlen(str);
							write(1, str, len);
							printed += len;
							format++;
							break;
						}
					default:
						write(1, format - 1, 2);
						printed += 2;
						format++;
						break;
				}
		}
	}

	va_end(params);
	return (printed);
}
