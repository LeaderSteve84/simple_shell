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
	pid_t child_pid;
	int status;
	ssize_t a;
	char *ret = NULL, *path_copy = NULL;

	a = access((ret = _strcheck(token_array[0])), F_OK);
	if (a == -1)
	{
		path_copy = path_directories(environ);
		find_in_path((ret = _strcheck(token_array[0])), path_copy,
				token_array, environ);
		free(path_copy);
	}
	if (a == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork function failed");
			exit(errno);
		}
		else if (child_pid == 0)
		{
			a = execve((ret = _strcheck(token_array[0])), token_array, environ);
			if (a == -1)
			{
				perror(token_array[0]);
				exit(errno);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
