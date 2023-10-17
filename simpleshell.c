#include "simpleshell.h"
/**
 * main - The entry point of the program
 * handle_input - This function handle_input takes a string input, removes the newline character if it exists at the end of the string, and then passes the string.
 * @my_string_input: A pointer to a character
 */

void handle_input(char *my_string_input)
{
	char *args[ARG_MAX];

	size_t length;
	length = strlen(my_string_input);
	if (length > 0 && my_string_input[length - 1] == '\n')
	{

		 my_string_input[length - 1] = '\0';
	}
	handle_com_line_args(my_string_input, args);
	invoke_program(args[0], args);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int k;
		for (k = 1; k < argc; k++)
		{
			handle_input(argv[k]);
		}
	}
	else
	{
		char *my_string_input = NULL;
		size_t size = 0;

		while (1)
		{
			if (isatty(STDIN_FILENO))
			{
				prompt_exhibit();
				my_command(&my_string_input, &size);
				if (strcmp(my_string_input, "exit\n") == 0)
				{
					free(my_string_input);
					break;
				}
				else
				{
					handle_input(my_string_input);
				}
			}
		}
	}
	return (0);
}

