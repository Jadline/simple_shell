#include "simpleshell.h"
/**
 * handle_com_line_args - A function that handles command lines with arguments.
 * @new_input: A pointer to a character.
 * @args: An array of character pointers.
 */

void handle_com_line_args(char *new_input, char *args[])
{
	char *my_token;
	int p;
	my_token = strtok(new_input, " ");
	p = 0;
	while (my_token != NULL && p  < ARG_MAX - 1)
	{
		args[p] = my_token;
		my_token = strtok(NULL, " ");
		p++;
	}
	args[p] = NULL;
}

