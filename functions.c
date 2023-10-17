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
		}
}
/**
 * handle_char - function to handle char format
 * @va_list: list of arguments
 */
void handle_char(va_list args)
{
	char c = (char) va_arg(args, int);
	putchar(c);
}

/**
 * handle_char - function to handle char format
 * @va_list: list of arguments
 */
void print_integer(int n)
{
	if (n == 0)
	{
		return;
	}
	if (n < 0)
	{
		putchar ('-');
		n = -n;
	}
	if (n / 10)
	{
		print_integer(n / 10);
	}

	putchar((n % 10) + '0');
}

void handle_integer(va_list args)
{
	int num = va_arg(args, int);
	if (num == 0)
	{
		putchar('0');
		return;
	}

	print_integer(num);
	putchar('0');
}
