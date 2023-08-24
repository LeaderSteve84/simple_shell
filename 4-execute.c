#include "shell.h"

/**
 * exec_func - Executes commands
 * @token_array: Array of tokens
 * @environ: Global variable
 *
 * Return: Nothing
 */

void exec_func(char **token_array, char **environ)
{
	int scs;
	ssize_t a;
	char *path_copy = NULL;

	scs = _strcheck(token_array[0]);
	if (scs == 1)
	{
		print_environment(environ);
	}
	if (scs == 2)
	{
		change_directory(token_array[1], environ);
	}
	if (scs == 3 || scs == 4)
	{
		a = access(token_array[0], F_OK);
		if (a == -1)
		{
			path_copy = path_directories(environ);
			find_in_path(token_array[0], path_copy, token_array, environ);
			free(path_copy);
		}
		if (a == 0)
		{
			execute_absolute_path(token_array[0], token_array, environ);
		}
	}
}
