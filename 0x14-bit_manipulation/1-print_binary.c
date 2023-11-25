#include "main.h"
/**
 * print_bin - print the binary representation of a number recursively
 * @n: this is the decimal number inputed
 * Retun: void
 */
void print_bin(unsigned long int n)
{
	if (n == 0)
		return;
	print_bin(n >> 1);
	if ((n & 1) == 1)
		_putchar('1');
	if ((n & 1) == 0)
		_putchar('0');
}
/**
 * print_binary - this func prints out the binary num
 * @n: the decimal to be converted to bin
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
		_putchar('0');
	else
	{
		print_bin(n);
	}
}
