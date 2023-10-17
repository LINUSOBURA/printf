#include "main.h"
FormatHandler handlers[] = {
	{'s', handle_string},
	{'c', handle_char},
	{'d', handle_integer},
	{'i', handle_integer},
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
	int i count = 0;
	const char *p;
	va_list args;
	FormatHandler *handler = NULL;
	
	va_start(args, format);
	
	for (p = format; *p; ++p)
		{
			if (*p != '%')
			{
				putchar(*p);
				count++;
				continue;
			}

			p++;

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
				handler->handler(args);
				count++;
			}
			else
			{
				putchar('%');
				putchar(*p);
				count += 2;
			}
		}
		va_end(args);
		return(count);
}
