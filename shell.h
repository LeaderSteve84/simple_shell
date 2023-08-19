#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIMITER " \n"
#include <string.h>
/*#include <signal.h>*/

char *read_line(void);
char *duplicate(char *buff);
char **tokenize(char *str, char *buff, char **token_array);
void exec_func(char **token_array, char **environ);
/*void sigint_handler(int signum);*/

#endif /* #ifndef SHELL_H */
