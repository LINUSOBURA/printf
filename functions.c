#include "main.h"
/**
 * handle_string - function to handle string format
 * @va_list: list of arguments
 */
int handle_string(va_list args)
{
	int local_count = 0;
	
	char *str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (*str)
		{
			putchar(*str++);
			local_count++;
		}
}
/**
 * handle_char - function to handle char format
 * @va_list: list of arguments
 */
int handle_char(va_list args)
{
	char c = (char) va_arg(args, int);
	putchar(c);
	return (1);
}

/**
 * handle_char - function to handle char format
 * @va_list: list of arguments
 */

int recursive_print_integer(int n, int *count)
{
	if (n / 10)
	{
		recursive_print_integer(n / 10, count);
	}
	putchar((n % 10) + '0');
	(*count)++;
}

void handle_integer(va_list args)
{
	int num = va_arg(args, int);
	int local_count = 0;
	
	if (num == 0)
	{
		putchar('0');
		return 1;
	}

	if (num < 0)
	{
		putchar('-');
		num = -num;
		local_count++;
	}

	recursive_print_integer(num, &local_count);
	return (local_count);
}
