#include "shell.h"
/**
 * main -
 * return: 0 (success)
 */
int main(void)
{
	int isatty_mode = 0, i, j;
	char *getline_buffer = NULL, *buffer = NULL;
	ssize_t write_return;
	char **token_array;

	isatty_mode = isatty(STDIN_FILENO);
	while (1)
	{
		isatty_mode = isatty(STDIN_FILENO);

		if (isatty_mode == 1)
		{
			write_return = write(STDOUT_FILENO, "$ ", 2);
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
