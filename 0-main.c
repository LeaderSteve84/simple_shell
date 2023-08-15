#include "shell.h"
/**
 */
int main()
{
	int isatty_mode;
	char *token;

	isatty_mode = isatty(STDIN_FILENO);
	while (isatty_mode)
	{
		if (isatty_mode == 1);
		{
			prompt();
		}
		token = readline();
	
	}
	return (0);
}
