#include "shell.h"

/**
 * _strlen - Function gets the length of a string
 * @str: The string
 *
 * Return: The length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (-1);
	while (str[len] != NULL)
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - Copies strings
 * @dest: Destination of the copying action
 * @src: Source
 *
 * Return: Pointer to the destination string
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0, if the two strings are the same
 * else, it returns the difference which is != 0
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((s1[i] + '0') - (s2[i] + '0'));
		}
		i++;
	}
	return (0);
}
