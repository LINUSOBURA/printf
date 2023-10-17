#include "main.h"
FormatHandler handlers[] = {
	{'s', handle_string},
	{'c', handle_char},
	{'d', handle_integer},
	{'i', handle_integer},
	{'b', handle_binary},
	{'u', handle_unsigned},
    	{'o', handle_octal},
    	{'x', handle_hex_lower},
    	{'X', handle_hex_upper},
	{0, NULL}
};

/**
* _printf - function to print everything to stdout
* @format: format string
* Return: numbers of printed characters
* Code by Linus Obura & Felix Mukah, refactored
*/
int _printf(const char *format, ...)
{
	int i, count = 0;
	const char *p;
	va_list args;
	FormatHandler *handler = NULL;

	va_start(args, format);

	if (!format)
	{
		return (-1);
	}
	for (p = format; *p; ++p)
		{
			handler = NULL;
			if (*p != '%')
			{
				putchar(*p);
				count++;
				continue;
			}

			p++;

			if (*p == '0')
			{
				putchar('%');
				count++;
				return (count);
			}
			else if (*p == '%')
			{
				putchar('%');
				count++;
				continue;
			}

			for (i = 0; handlers[i].handler != NULL; ++i)
				{
					if (handlers[i].specifier == *p)
					{
						handler = &handlers[i];
						break;
					}
				}
			if (handler)
			{
				count += handler->handler(args);
			}
			else
			{
				putchar('%');
				putchar(*p);
				count += 2;
			}
		}
		va_end(args);
		return (count);
}
