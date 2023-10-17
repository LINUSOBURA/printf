#include "main.h"
/**
* _printf - function to print everything to stdout
* @format: format string
* Return: numbers of printed characters
* Code by Linus Obura & Felix Mukah, refactored
*/
int _printf(const char *format, ...)
{
	int count = 0;
	va_list params;
	char *p, *s_val;

	va_start(params, format);
	if (format == NULL)
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			count++;
			continue;
		}
		switch (*++p)
		{
			case 'c':
			putchar(va_arg(params, int));
			count++;
			break;
			case 's':
			for (s_val = va_arg(params, char *); *s_val; s_val++)
			{
				if (!s_val)
					s_val = "(null)";
				putchar(*s_val);
				count++;
			}
				break;
				case '%':
				putchar('%');
				count++;
				break;
				case '\0':
				putchar('%');
				count++;
				p--;
				break;
				default:
				putchar('%');
				putchar(*p);
				count += 2;
				break;
				}
				}
				va_end(params);
				return (count);
}
