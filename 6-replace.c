#include "shell.h"

/**
 * _strcheck - Checks for strings
 * @args: The string to be checked
 *
 * Return: A string pointer
 */

char *_strcheck(char *args)
{
	char *ptr;

	if (_strcmp("ls", args) == 0)
	{
		ptr = "/bin/ls";
		return (ptr);
	}
	if (_strcmp("echo", args) == 0)
	{
		ptr = "/bin/echo";
		return (ptr);
	}
	if (_strcmp("clear", args) == 0)
	{
		ptr = "/bin/clear";
		return (ptr);
	}
	if (_strcmp("exit", args) == 0)
	{
		ptr = "/bin/exit";
		return (ptr);
	}
	if (_strcmp("cat", args) == 0)
	{
		ptr = "/bin/cat";
		return (ptr);
	}
	if (_strcmp("env", args) == 0)
	{
		return (NULL);
	}
	return (args);
}
