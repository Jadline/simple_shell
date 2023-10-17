#include "simpleshell.h"
/**
 * invoke_program - function that executes the new_program
 *
 * @my_path:path of the executable
 * @my_args:takes the arguments for the path
 */
void invoke_program(char *my_path, char *my_args[])
{
	int status;
	char *actual_full_path;
	pid_t new_program;

	actual_full_path = handle_my_path(my_path);
	if (actual_full_path == NULL)
	{
		print_myfunc("failed to find command");
		return;
	}

	new_program = fork();
	if (new_program == -1)
	{
		perror("failed to create a child process");
		exit(EXIT_FAILURE);
	}
	else if (new_program == 0)
	{
		char *envp[] = { NULL };

		if (execve(actual_full_path, my_args, envp) == -1)
		{
			perror("failed to load the program\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(actual_full_path);
		wait(&status);
	}
}
