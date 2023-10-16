#include "simpleshell.h"
/**
 * my_command - this function takes the command from the stdin
 *
 * @my_string:buffer that stores text read from stdin
 * @size:size of the buffer
 */
void my_command(char **my_string, size_t *size)
{
	ssize_t my_char_string;

	my_char_string = getline(my_string, size,stdin);
	if (my_char_string == -1)
	{
		print_myfunc("Error reading input\n");
		exit(EXIT_FAILURE);
	}
	else if (my_char_string == 0)
	{
		print_myfunc("\n");
		exit(EXIT_SUCCESS);
	}
}

