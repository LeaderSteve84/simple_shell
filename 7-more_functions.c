#include "shell.h"

/**
 * _strchr -  a function that locates a character in a string.
 * @s: input
 * @c: input
 * Return: NULL
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
		return (s + i);
	}
	return (NULL);
}

/**
 * _strstr - Function locates a substring
 * @haystack: String to be checked
 * @needle: Second string
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
/**
 * _strncmp - a function that compare two strings
 * @s1: first string
 * @s2: second string
 * @n: n byte of s1 and s2
 * Return: an integer value
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		if (s1[i] == '\0')
		{
			break;
		}
	}
	return (0);
}

