#include "main.h"

int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int local_count = 0;

	if (num == 0)
	{
		putchar('0');
		return 1;
	}
	recursive_print_binary(num, &local_count);
	return local_count;
}

void recursive_print_binary(unsigned int n, int *count)
{
	if (n / 2)
	{
		recursive_print_binary(n / 2, count);
	}
	putchar((n % 2) + '0');
	(*count)++;
}
