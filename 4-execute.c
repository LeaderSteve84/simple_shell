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
	char *ret;

	if (access((ret = _strcheck(token_array[0])), F_OK) == -1)
	{
		write(STDOUT_FILENO, "./hsh: No such file or directory\n", 33);
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork function failed");
		exit(127);
	}
	else if (child_pid == 0)
	{
		a = execve((ret = _strcheck(token_array[0])), token_array, environ);
		if (a == -1)
		{
			write(STDOUT_FILENO, "./hsh: No such file or directory\n", 33);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
