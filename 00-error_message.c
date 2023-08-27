#include "shell.h"

/**
 * error_message - function that print error message
 * to standard output
 * @args: first users input on standard input
 * @infi_loop_count: the count number of the infinite iteration.
 * Return: void(nothing)
 */
void error_message(char *args, int infi_loop_count)
{

	write(2, "hsh: ", 5);
	_putchar(infi_loop_count + '0');/*convert integer to character*/
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	write(2, ": ", 2);
	write(2, "not found", 9);
	write(2, "\n", 1);
}


/**
 * error_message_denied - function that print permission denied message
 * @args: first command in users input
 * @infi_loop_count: number of infinite iteration count
 * Return: void(nothing)
 */
void permission_denied(char *args, int infi_loop_count)
{

	write(2, "hsh: ", 5);
	_putchar(infi_loop_count + '0');/*convert integer to character*/
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	write(2, ": ", 2);
	write(2, "permission denied", 17);
	write(2, "\n", 1);
}


/**
 * _putchar - a function that print character.
 * @count_input_strings: number of strings input
 * by user.
 * Return: void(nothing)
 */
int _putchar(char count_input_strings)
{
	return (write(2, &count_input_strings, 1));
}

