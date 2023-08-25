#include "shell.h"

/**
 * read_line - Reads chars from stdin using getline
 * @ac: Argument count
 * @argv: Argument vectors
 *
 * Return: A pointer to an array string.
 */

char *read_line(int ac, char **argv)
{
	char *getline_buffer = NULL;
	size_t getline_buffer_size = 0;
	ssize_t num_of_char_read;

	if (ac == 2)
	{
		getline_buffer = read_text(argv);
	}
	else
	{
		num_of_char_read = getline(&getline_buffer, &getline_buffer_size, stdin);
	}
	/*handle ctrl+D*/
	if (num_of_char_read == -1)
	{
		free(getline_buffer);
		return (NULL);
	}
	/*check if getline function store the command read from stdin*/
	if (getline_buffer == NULL)
	{
		perror("Unable to read command");
		exit(errno);
	}
	return (getline_buffer);
}

/**
 * read_text - Reads text from a file
 * @argv: Argument vector
 *
 * Return: A string pointer
 */

char *read_text(char **argv)
{
	FILE *stream;
	char *line = NULL, *text = NULL;
	size_t len = 0, fullsize = 0, length;

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("can't open file");
		exit(127);
	}
	while (getline(&line, &len, stream) != -1)
	{
		length = len;
		text = realloc(text, fullsize + length + 1);
		if (text == NULL)
		{
			perror("memory allocation failure");
			fclose(stream);
			free(line);
			exit(127);
		}
		_strcpy(text + fullsize, line);
		fullsize += length;
	}
	free(line);
	fclose(stream);
	if (fullsize == 0)
		exit(127);
	text[fullsize] = '\0';
	return (text);
}
