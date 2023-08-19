#include "shell.h"
/**
 * read_line -
 * return: a pointer to an array string.
 */

char *read_line(void)
{
	char *getline_buffer = NULL;
	size_t getline_buffer_size = 0;
	ssize_t num_of_char_read;

	num_of_char_read = getline(&getline_buffer, &getline_buffer_size, stdin);
	/*handle ctrl+D*/
	if (num_of_char_read == -1)
	{
		free(getline_buffer);
		return (NULL);
	}
	/*check if getline function store the command read from stdin*/
	if (getline_buffer == NULL)
	{
		perror("Unable to read command");
		exit(EXIT_FAILURE);
	}
	return (getline_buffer);
}
