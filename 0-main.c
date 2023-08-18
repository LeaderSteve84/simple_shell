#include "shell.h"
/**
 * main -
 * return: 0 (success)
 */
int main(void)
{
	int isatty_mode = 0, i = 0, j = 0;
	char *prompt = NULL, *getline_buffer = NULL, *buffer = NULL;
	size_t prompt_size = 0;
	ssize_t write_return = 0;
	char **token_array = NULL;

	prompt = "$ ";
	prompt_size = strlen(prompt);
	isatty_mode = isatty(STDIN_FILENO);
	while (isatty_mode)
	{
		if (isatty_mode == 1)
		{
			write_return = write(STDOUT_FILENO, prompt, prompt_size);
			if (write_return == -1)
			{
				perror("propmt failed");
				exit(EXIT_FAILURE);
			}
		}
		getline_buffer = read_line();
		buffer = duplicate(getline_buffer);
		token_array = tokenize(getline_buffer, buffer, NULL);

		for (i = 0; token_array[i] != NULL; i++)
		{
			printf("%s\n", token_array[i]);
		}
		for (j = 0; token_array[j] != NULL; j++)
		{
			free(token_array[j]);
		}
		free(token_array);
		free(buffer);
		free(getline_buffer);
	}
	return (0);
}
