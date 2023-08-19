#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIMITER " \n"
#include <string.h>
#include <fcntl.h>
#include <errno.h>
/*#include <signal.h>*/

char *read_line(void);
char *duplicate(char *buff);
char **tokenize(char *str, char *buff, char **token_array);
void exec_func(char **token_array, char **environ);
<<<<<<< HEAD
char *_strcpy(char *str_to, char *str_fr);
=======
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strstr(char *haystack, char *needle);
char *_strcheck(char *args);
void _printenv(char **environ);

>>>>>>> 044051b2f615b703cb62b4081a98f2ed085171ef
/*void sigint_handler(int signum);*/

#endif /* #ifndef SHELL_H */
