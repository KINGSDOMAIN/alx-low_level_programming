#include "main.h"
#include <unistd.h>
/**
 * _putchar - prints out a char at a time
 * @c: char to be printed
 * Retun: 1
 * On error, -1 is returned, and errno is properly set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
