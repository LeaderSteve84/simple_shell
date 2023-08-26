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

char *duplicate(char *buff);
char **tokenize(char *str, char *buff, char **token_array);
void exec_func(char **token_array, char **environ, int count);

char *_strcpy(char *dest, char *src);
/*5-functions.c*/
int _strcmp(char *s1, char *s2);
/*5-functions.c*/
int _strncmp(char *s1, char *s2, size_t n);
/*7-more_functions.c*/
int _strlen(char *str);
/*5-functions.c*/
char *_strstr(char *haystack, char *needle);
/*7-more_functions.c*/
int _strcheck(char *args);
/*6-path_exec.c*/
char *_strcat(char *dest, char *src);
/*5-more_functions.c*/
char *_strncpy(char *dest, char *src, int n);
/*5-more_functions.c*/
char *_strchr(char *s, char c);
/*7-more_functions.c*/
char *path_directories(char **environ);
/*6-path_exec.c*/
int compare_first_five(char *str1, char *str2);
/*6-path_exec.c*/
char *_getenv(char *name, char **environ);
/*6-path_exec.c*/
void find_in_path(char *args, char *str, char **av, char **environ,
		int count);
/*6-path_exec.c*/
void _free(char **token_array, char *buf, char *s);
/*7-more_functions.c*/
int exit_status(char **token_array);
/*7-more_functions.c*/
void remove_newline_character(char *getline_buffer);
void print_environment(char **environ);
/*9-even_more_functions.c*/
void execute_absolute_path(char *args, char **token_array,
		char **environ, int count);
void change_directory(char *dir, char **environ);
int _isdigit(int c);
/*10-more_functions.c*/
int _isalpha(int c);
/*10-more_functions.c*/
char *check_spaces(char *str);
/*10-more_functions.c*/
void error_message(char *args, int infi_loop_count);
/*00-error_message.c*/
int _putchar(char count_num_strings);
/*00-error_message.c*/
char *read_text(char **argv);
/*1-readline.c*/
char *read_line(int ac, char **argv);
/*1-readline.c*/

#endif /* #ifndef SHELL_H */
