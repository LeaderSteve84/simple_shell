#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DELIMITER " \n\t"
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#define MAX_PATH_LENGTH 1024

char *read_line(void);
char *duplicate(char *buff);
char **tokenize(char *str, char *buff, char **token_array);
void exec_func(char **token_array, char **environ);

char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str);
char *_strstr(char *haystack, char *needle);
int _strcheck(char *args);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *path_directories(char **environ);
int compare_first_five(char *str1, char *str2);
char *_getenv(char *name, char **environ);
void find_in_path(char *args, char *str, char **av, char **environ);
void _free(char **token_array, char *buf, char *s);
int exit_status(char **token_array);
void remove_newline_character(char *getline_buffer);
void print_environment(char **environ);
void execute_absolute_path(char *args, char **token_array, char **environ);
void change_directory(char *dir, char **environ);
int _isdigit(int c);
int _isalpha(int c);
char *check_spaces(char *str);

#endif /* #ifndef SHELL_H */
