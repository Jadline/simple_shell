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

	pid_t new_program = fork();
	
	if (new_program == -1)
	{
		perror("failed to create a child process");
		exit(EXIT_FAILURE);
	}
	else if (new_program == 0)
	{
		char *envp[] = { NULL };
		if (execve(my_path,my_args,envp) == -1)
		{
			perror(my_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
