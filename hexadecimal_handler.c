#include "main.h"
/**
* handle_hex - function to handle hexadecimal numbers
* @args: arguments list
* @uppercase: integer
* Return: count
*/
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
/**
* recursive_print_hex - function to handle hexadecimal numbers
* @n: unsigned integer
* @uppercase: integer
* @count: pointer to count
*/
void recursive_print_hex(unsigned int n, int uppercase, int *count)
{
	char *hex_chars = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n / 16)
	{
		recursive_print_hex(n / 16, uppercase, count);
	}
	putchar(hex_chars[n % 16]);
	(*count)++;
}

/**
* handle_hex_lower - function to handle hexadecimal numbers
* @args: arguments list
* Return: handle hex
*/
int handle_hex_lower(va_list args)
{
	return (handle_hex(args, 0));
}

/**
* handle_hex_upper - function to handle hexadecimal numbers
* @args: arguments list
* Return: handle hex
*/
int handle_hex_upper(va_list args)
{
	return (handle_hex(args, 1));
}
