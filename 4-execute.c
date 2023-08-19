#include "shell.h"
/**
 * exec_func -
 * @token_array:
 * return:
 */

void exec_func(char **token_array, char **environ)
{
	pid_t child_pid;
	int status;
	ssize_t a;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork function failed");
		exit(127);
	}

	else if (child_pid == 0)
	{
		a = execve(token_array[0], token_array, environ);
		if (a == -1)
		{
			write(STDOUT_FILENO, "./hsh: No such file or directory", 32);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
	{
		wait(&status);

	}
}
