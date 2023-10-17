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

	va_start(args, format);
	for (; *format; format++)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
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
    return count;
}
