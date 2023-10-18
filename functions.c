#include "main.h"
/**
 * handle_string - function to handle string format
 * @args: list of arguments
 * Return: count
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

	return (count);
}
/**
 * handle_char - function to handle char format
 * @args: list of arguments
 * Return: count
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);
	
	putchar(c);
	return (1);
}

/**
 * recursive_print_integer - function to handle char format
 * @n: integer
 * @count: conts of printed ints
 */

void recursive_print_integer(int n, int *count)
{
	if (n == 0)
		return;

	if (n < 0)
	{
		putchar('-');
		(*count)++;
		if (n == INT_MIN)
		{
			recursive_print_integer(-(n / 10), count);
			putchar('8');
			(*count)++;
			return;
		}
		n = -n;
	}

	if (n / 10)
		recursive_print_integer(n / 10, count);
	putchar((n % 10) + '0');
	(*count)++;
}

/**
 * handle_integer - function to handle char format
 * @args: list of arguments
 * Return: count
 */

int handle_integer(va_list args)
{
	int num = va_arg(args, int);
	int local_count = 0;

	recursive_print_integer(num, &local_count);
	return (local_count);
}

