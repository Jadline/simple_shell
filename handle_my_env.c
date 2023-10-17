#include "simpleshell.h"

void output_my_environ(void)
{
	 extern char **my_environ;
	 char **env = my_environ;
	 
	 while (*env != NULL)
	 {
		 write(STDOUT_FILENO, *env, strlen(*env));
		 env++;
	 }
}

