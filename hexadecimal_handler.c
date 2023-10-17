#include "main.h"
int handle_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	int local_count = 0;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}

	recursive_print_hex(num, uppercase, &local_count);
	return (local_count);
}

void recursive_print_hex(unsigned int n, int uppercase, int *count)
{
	char hex_chars[] = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n / 16)
	{
		recursive_print_hex(n / 16, uppercase, count);
	}
	putchar(hex_chars[n % 16]);
	(*count)++;
}

int handle_hex_lower(va_list args)
{
	return handle_hex(args, 0);
}

int handle_hex_upper(va_list args)
{
	return handle_hex(args, 1);
}
