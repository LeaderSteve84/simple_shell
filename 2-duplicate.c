#include "shell.h"
/**
 * duplicate - 
 * @buff:
 * return: pointer to array of strings.
 */
char *duplicate(char *buff)
{
	char *buffer;

	buffer = malloc((strlen(buff) + 1) * sizeof(char));
	if (buffer == NULL)
	{
		perror("memory allocation to buffer failed");
		exit(EXIT_FAILURE);
	}
	buffer[0] = '\0';

	strcpy(buffer, buff);

	return (buffer);
}
