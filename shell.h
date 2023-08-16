#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIMITER " \n"
#include <string.h>
void prompt();
char **read_line();
char **split_tokenize(int n, char **buff);

#endif
