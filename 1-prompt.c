#include "shell.h"
/**
 * prompt - 
 * return: nothing
 */

void prompt()
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
