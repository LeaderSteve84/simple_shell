#include "shell.h"
/**
 * main -
 * return: 0 (success)
 */
int main(int ac, char **token_array, char **environ)
{
	int isatty_mode = 0, j;
	char *getline_buffer = NULL, *buffer = NULL;
	ssize_t write_return;

	(void)ac;
	isatty_mode = isatty(STDIN_FILENO);
	while (1)
	{
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
		if (getline_buffer == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		buffer = duplicate(getline_buffer);
		token_array = tokenize(getline_buffer, buffer, NULL);
		exec_func(token_array, environ);
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
