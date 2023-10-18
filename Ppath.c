#include "simpleshell.h"

char * handle_my_path(char *inputcommand)
{
	char *duplicate_path;
	char * my_token;
	char length_of_path[PATH_MAX];
	char *_getpath;

	if (access(inputcommand, X_OK) == 0)
	{
		return (strdup(inputcommand));
	}
	_getpath = getenv("PATH");
	if (_getpath == NULL)
	{
		perror("failed to get path");
		exit (EXIT_FAILURE);
	}
	duplicate_path  = strdup(_getpath);
	if (duplicate_path == NULL)
	{
		perror("failed to copy the path\n");
		exit(EXIT_FAILURE);
	}
	my_token = strtok(duplicate_path, ":");
	while (my_token != NULL)
	{

		 snprintf(length_of_path, sizeof(length_of_path), "%s/%s", my_token, inputcommand);
		 if (access(length_of_path, X_OK) == 0)
		 {
			 free(duplicate_path);
			 return (strdup(length_of_path));
		 }
		 my_token = strtok(NULL, ":");
	 }
	 free(duplicate_path);
	 return (NULL);
}
