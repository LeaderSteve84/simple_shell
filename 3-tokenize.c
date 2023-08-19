#include "shell.h"

/**
 * tokenize - Function tokenizes a string
 * @str: The original string
 * @buff: The duplicated string to be tokenized
 * @token_array: The array of tokens
 *
 * Return: pointer to array of strings.
*/

char **tokenize(char *str, char *buff, char **token_array)
{
	char *token_addr = NULL;
	int count_tokens_num = 0, i = 0;

	token_addr = strtok(str, DELIMITER);
	while (token_addr != NULL)
	{
		count_tokens_num++;
		token_addr = strtok(NULL, DELIMITER);
	}
	count_tokens_num++;

	token_array = malloc((count_tokens_num + 1) * sizeof(char *));
	if (token_array == NULL)
	{
		perror("memory allocation to token_array failed");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < count_tokens_num + 1; i++)
	{
		token_array[i] = NULL;
	}
	token_addr = strtok(buff, DELIMITER);

	for (i = 0; token_addr != NULL; i++)
	{
		token_array[i] = malloc((_strlen(token_addr) + 1) * sizeof(char));

		if (token_array[i] == NULL)
		{
			perror("memory allocation to token_array failed");
			exit(EXIT_FAILURE);
		}
		_strcpy(token_array[i], token_addr);
		token_addr = strtok(NULL, DELIMITER);
	}
	token_array[count_tokens_num] = NULL;
	return (token_array);
}
