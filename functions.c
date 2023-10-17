#include "main.h"
/**
 * handle_string - function to handle string format
 * @va_list: list of arguments
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	for (; *str; str++, count++)
	{
		putchar(*str);
	}

	return count;
}
/**
 * handle_char - function to handle char format
 * @va_list: list of arguments
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);
	putchar(c);
	return (1);
}

/**
 * handle_char - function to handle char format
 * @va_list: list of arguments
 */

void recursive_print_integer(int n, int *count)
{
	if (n == 0)
		return;

	if (n < 0)
	{
		putchar('-');
		n = -n;
		(*count)++;
	}

	if (n / 10)
		recursive_print_integer(n / 10, count);
	putchar((n % 10) + '0');
	(*count)++;
}

int handle_integer(va_list args)
{
	int num = va_arg(args, int);
	int local_count = 0;

	if (num == 0)
	{
		putchar('0');
		return 1;
	}
	recursive_print_integer(num, &local_count);
	return local_count;
}

