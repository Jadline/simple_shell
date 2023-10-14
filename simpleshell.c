#include "simpleshell.h"
/**
 * main - The entry point of the program
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		char *my_string_input = NULL;
		size_t size = 0;

		char *args[3];

		while (1)
		{
			prompt_exhibit();
			my_command(&my_string_input,&size);
			if (strcmp(my_string_input, "exit\n") == 0)
			{
				free(my_string_input);
				break;
			}
			else
			{
				my_string_input[strcspn(my_string_input, "\n")] = '\0';
				args[0] = my_string_input;
				args[1] = NULL;

				invoke_program(args[0],args);
			}
		}
	}
	return (0);
}
