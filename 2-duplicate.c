#include "shell.h"
/**
 * duplicate - 
 * @buff:
 * return: pointer to array of strings.
 */
char *duplicate(char *buff)
{
	char *buffer = NULL;

	buffer = malloc((strlen(buff) + 1) * sizeof(char));
	if (buffer == NULL)
	{
		perror("memory allocation to buffer failed");
		exit(EXIT_FAILURE);
	}
	strcpy(buffer, buff);

	return (buffer);
}
