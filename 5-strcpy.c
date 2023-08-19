#include "shell.h"
/**
 * _strcpy - a function that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @str_to: destination value
 * @str_fr: source value
 * Return: 0 (success)
 */

char *_strcpy(char *str_to, char *str_fr)
{
	int i;

	for (i = 0; str_fr[i] != '\0'; i++)
	{
		str_to[i] = str_fr[i];
	}
	str_to[i++] = '\0';
	return (str_to);
}
