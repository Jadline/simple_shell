#include "simpleshell.h"
/**
 * print_myfunc - this function prints to the stdout
 *
 * @message:character string
 */
void print_myfunc(const char *message)
{
	write(STDOUT_FILENO,message,strlen(message));
}
