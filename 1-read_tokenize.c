#include "shell.h"
/**
 */

char *readline()
{
	char *getline_buffer = NULL, *buffer = NULL, *token_addr;
	char **array_of_tokens = NULL;
	size_t getline_buffer_size = 0;
	ssize_t num_of_char_read;
	int count_tokens_num = 0, i;

	num_of_char_read = getline(&getline_buffer, &getline_buffer_size, stdin);
	/*handle ctrl+D*/
	if (num_of_char_read == -1)
	{
		perror("");
		exit(EXIT_ FAILURE);
	}
	/*check if getline function store the command read from stdin*/
	if (getline_buffer == NULL)
	{
		perror("Unable to read command");
		exit(EXIT_FAILURE);
	}
	buffer = malloc((num_of_char_read + 1) * sizeof(char));
	if (buffer == NULL)
	{
		perror("memory allocation to buffer failed");
		exit(EXIT_FAILURE);
	}
	/*copy content from getline_buffer to buffer*/
	strcpy(buffer, getline_buffer);
	/*tokenize the content of getline buffer based on DELIMITER macro at '\0' & \n*/
	token_addr = strtok(getline_buffer, DELIMITER);
	while (token_addr != NULL)
	{
		count_tokens_num++;
		token_addr = strtok(NULL, DELIMITER);
	}
	count_tokens_num++;
	/*allocate memory to array of the tokens splitted from buffer variable*/
	array_of_tokens = malloc((count_tokens_num + 1) * sizeof(char *));
	if (array_of_tokens == NULL)
	{
		perror("memory allocation to array_of_tokens failed");
		exit(EXIT_FAILURE);
	}
	/*tokenize the content copied into buffer from getline_buffer*/
	token_addr = strtok(buffer, DELIMITER);
	/*iterate through the index of array_of_tokens*/
	 for (i = 0, array_of_tokens[i] != NULL, i++)
	 {
		 array_of_tokens[i] = malloc((strlen(token) + 1) * sizeof(char));
		 if (array_of_tokens[i] == NULL)/*check memory allocated to each index*/
		 {
			perror("memory allocated to array_of_tokens[i] failed");
			exit(EXIT_FAILURE);
		 }
		 strcpy(array_of_tokens[i], token_addr);
		 token_addr = strtok(NULL, DELIMITER);
	 }
	 return (array_of_token);
}
