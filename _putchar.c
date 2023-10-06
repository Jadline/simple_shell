#include "simpleshell.h"

/**
 * _putchar - writes the output
 * @c: the character to be printed
 *
 * Return: (1) on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
