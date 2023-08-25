#include "shell.h"
/**
 * error_message - function that print error message
 * to standard output
 * @args: first users input on standard input
 * @av: an array of user input on standard input
 * Return: void(nothing)
 */
void error_message(char *args, char **av)
{
	/*static variable to track command index*/
	int count_input_strings = 0;
	static int command_index = 0;

	while (av[count_input_strings] != NULL)
	{
		count_input_strings++;
	}
	command_index++;
	
	write(STDOUT_FILENO, "hsh: ", 5);
	_putchar(command_index + '0');/*convert integer to character*/
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, args, _strlen(args));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found", 9);
	write(STDOUT_FILENO, "\n", 1);
}
/**
 * _puchar - a function that print character.
 * @count_input_strings: number of strings input
 * by user.
 * Return: void(nothing)
 */
int _putchar(char count_input_strings)
{
	return (write(1, &count_input_strings, 1));
}

