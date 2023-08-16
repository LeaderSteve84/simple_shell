#include "shell.h"

/**
 * prompt - Prints a prompt "$ " and waits for the user
 * to input a command.
 *
 * Return: nothing
 */

void prompt(void)
{
	char *prompt;
	size_t prompt_size;
	ssize_t write_return;

	prompt = "$ ";
	prompt_size = strlen(prompt);

	write_return = write(STDOUT_FILENO, prompt, prompt_size);
	if (write_return == -1)
	{
		perror("prompt failed\n");
		exit(EXIT_FAILURE);
	}
}
