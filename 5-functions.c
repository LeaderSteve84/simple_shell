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
	while (*str != '\0')
	{
		len++;
		str++;
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
	int i = 0;

	if (src == NULL)
		src = "";
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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



/**
 * _strcat - a program that concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * Return: A pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)

{
	int dlen = 0, i;

	while (dest[dlen])
	{
		dlen++;
	}

	for (i = 0; src[i] != 0; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}
	dest[dlen] = '\0';
	return (dest);
}

/**
 * _strncpy - a function that copies a string
 * @dest: The buffer storing the string copy
 * @src: The source string
 * @n: The maximum number of bytes to copied from src.
 * Return: a pointer to the resulting string dest'
 */
char *_strncpy(char *dest, char *src, int n)
{
	int index = 0;
	int src_len = 0;

	while (src[index++])
		src_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[index] = src[index];
	for (index = src_len; index < n; index++)
		dest[index] = '\0';

	return (dest);
}
