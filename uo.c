#include "main.h"

int handle_unsigned(va_list args)
{

	unsigned int num = va_arg(args, unsigned int);
	int local_count = 0;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	recursive_print_unsigned(num, &local_count);
	return (local_count);
}

void recursive_print_unsigned(unsigned int n, int *count)
{
	if (n / 10)
	{
		recursive_print_unsigned(n / 10, count);
	}
	putchar((n % 10) + '0');
	(*count)++;
}

int handle_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int local_count = 0;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}

	recursive_print_octal(num, &local_count);
	return local_count;
}

void recursive_print_octal(unsigned int n, int *count)
{
	if (n / 8)
	{
		recursive_print_octal(n / 8, count);
	}
	putchar((n % 8) + '0');
	(*count)++;
}

