#include "simpleshell.h"
/**
 * my_command - this function takes the command from the stdin
 *
 * @my_string:buffer that stores text read from stdin
 * @size:size of the buffer
 */
void my_command(char *my_string, size_t size)
{
	if (fgets(my_string, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_myfunc("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_myfunc("Error");
			exit(EXIT_FAILURE);
		}
	}
}
