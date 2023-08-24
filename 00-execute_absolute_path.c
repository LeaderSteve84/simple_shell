#include "shell.h"
/**
 * execute_absolute_path - function that print absolute path
 * @args: token_array[0]
 * @token_array: users inputs
 * @environ: user environ
 * Return: void (nothing)
 */
void execute_absolute_path(char *args, char **token_array, char **environ)
{
	pid_t child_pid;
	int status;
	ssize_t a;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork function at absolute path failed");
		exit(errno);
	}
	else if (child_pid == 0)
	{
		a = execve(args, token_array, environ);
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
