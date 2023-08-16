#include "shell.h"
/**
 * read_line - 
 * return: a pointer to an array string.
 */

char **read_line()
{
	char *getline_buffer = NULL, *buffer = NULL;
	char **tokens_array;
	size_t getline_buffer_size = 0;
	ssize_t num_of_char_read;
	int count_tokens_num = 0;
	char *token_addr;

	num_of_char_read = getline(&getline_buffer, &getline_buffer_size, stdin);
	/*handle ctrl+D*/
	if (num_of_char_read == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
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

	tokens_array = split_tokenize(count_tokens_num, &buffer);

	return (tokens_array);
}
