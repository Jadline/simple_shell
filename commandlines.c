#include "simpleshell.h"

void handle_com_line_args(char *new_input, char *args[])
{
	char *my_token;
	int p ;
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
