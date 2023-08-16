#include "shell.h"
/**
 * split_tokenize - 
 * @n:
 * @buff:
 * return: pointer to array of string
 */
char **split_tokenize(int n, char **buff)
{
	char **array_of_tokens = NULL;
	char *token_addr;
	int i;

	array_of_tokens = malloc((n + 1) * sizeof(char *));
	if (array_of_tokens == NULL)
	{
		perror("memory allocation to array_of_tokens failed");
		exit(EXIT_FAILURE);
	}
	token_addr = strtok(*buff, DELIMITER);

	for (i = 0; token_addr != NULL; i++)
	{
		array_of_tokens[i] = malloc((strlen(token_addr) + 1) * sizeof(char));

		if (array_of_tokens[i] == NULL)
		{
			perror("memory allocation to array_index[i] failed");
			exit(EXIT_FAILURE);
		}
		strcpy(array_of_tokens[i], token_addr);
		token_addr = strtok(NULL, DELIMITER);
	}
	return (array_of_tokens);
}
