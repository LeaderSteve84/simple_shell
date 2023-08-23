#include "shell.h"
/**
 * remove_newline_character - function that remove newline
 * character from users inputs and replaces it with NULL byte.
 * @getline_buffer: users inputs
 * Return: nothing.
 */
void remove_newline_character(char *getline_buffer)
{
	size_t len;

	/*remove trailing newline character*/
	len = _strlen(getline_buffer);
	if (len > 0 && getline_buffer[len - 1] == '\n')
	{
		getline_buffer[len - 1] = '\0';
	}
}
