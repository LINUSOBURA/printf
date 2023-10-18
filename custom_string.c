#include "main.h"
int handle_custom_string(va_list args)
{
	int count = 0;

	char *str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			putchar('\\');
			putchar('x');
			putchar("0123456789ABCDEF"[(*str >> 4) & 0xF]);
			putchar("0123456789ABCDEF"[*str & 0xF]);
			count += 4;
		}
		else
		{
			putchar(*str);
			count++;
		}
		str++;
	}
	return (count);
}
