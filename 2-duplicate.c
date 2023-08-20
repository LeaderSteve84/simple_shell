#include "shell.h"

/**
 * duplicate - Duplicates a string
 * @buff: The string to be duplicated
 *
 * Return: Pointer to an array of strings.
 */

char *duplicate(char *buff)
{
	char *buffer;

	buffer = malloc((_strlen(buff) + 1) * sizeof(char));
	if (buffer == NULL)
	{
		perror("memory allocation to buffer failed");
		exit(errno);
	}
	buffer[0] = '\0';

	_strcpy(buffer, buff);

	return (buffer);
}
