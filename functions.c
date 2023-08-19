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
 * _strstr - Function locates a substring
 * @haystack: String to be checked
 * @needle: Second string
 *
 * Return: Always 0 or "NULL" if otherwise.
 */

char *_strstr(char *haystack, char *needle)
{
	char *str1, *str2;

	while (*haystack != '\0')
	{
		str1 = haystack;
		str2 = needle;
		while (*haystack != '\0' && *str2 != '\0' && *haystack == *str2)
		{
			haystack++;
			str2++;
		}
		if (*str2 == '\0')
			return (str1);
		haystack = str1 + 1;
	}
	return (NULL);
}
