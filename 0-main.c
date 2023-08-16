#include "shell.h"
/**
 * main - 
 * return: o (success)
 */
int main()
{
	int isatty_mode, i;
	char **token_array, **getline_buffer;

	isatty_mode = isatty(STDIN_FILENO);
	while (isatty_mode)
	{
		if (isatty_mode == 1)
		{
			prompt();
		}
		token_array = read_line();
		if (token_array == NULL)
		{
			perror("token_array pointer address return to main failed");
			exit(EXIT_FAILURE);
		}
		for (i = 0; token_array[i] != NULL; i++)
		{
			printf("%s\n", token_array[i]);
		}
		for (i = 0; token_array[i] != NULL; i++)
		{
			free(token_array[i]);
		}
	}
	free(token_array);
	free(getline_buffer);
	return (0);
}
