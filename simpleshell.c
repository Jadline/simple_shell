#include "simpleshell.h"
/**
 * main - The entry point of the program
 */
int main(void)
{
	char my_string_input[280];
	char *args[3];
       	
	args[0] = "/bin/";
	args[1] = my_string_input;
	args[2] = NULL;

	while (1)
	{
		prompt_exhibit();
		my_command(my_string_input,sizeof(my_string_input));
		invoke_program("/bin/",args);

	}
	return (0);
}

