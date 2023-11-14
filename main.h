#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>


extern char **environ;
/**
* struct builtin - builtins
* @b_name: name of the command
* @b_func: pointer to a function
*/
typedef struct builtin
{
	char *b_name;
	int (*b_func)();
} builtin_struct;

int (*builtin_main(char *user_input))();
int exit_func(void);
int env_func(void);
void modify_sig(char *str);
char *ret_path_line();
void error_message(char **args);
char **get_path(char *args);
char *fix_path(char **args, char **path);
char **getenvpath(void);
void freedom(int n, ...);
int non_interactive_mode(char **av);
int _interactive(char **av __attribute__((unused)));
int sh_cmd(char *buffer);
char **parser(char *buffer, int characters);
int exec(char *command, char **args);
void free_all(char **dptr1, char **dptr2, char *sptr1, char *sptr2);
void logo(void);
int strncomparer(char *s1, char *s2, size_t n);
int strlarge(char *s);
char *strduplicate(char *s);
int strcomparer(char *s1, char *s2);
char *strconk(char *dest, char *src);
int spaces_finder(char *buffer);
int len_num(int n);
char *int_to_charac(int num);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_itoa(int num);
char *_strstr(char *x, char *y);
int check_compare(char *x, char *y);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strcpy(char *dest, char *src);
void error_falsecommand(char **args, char *buffer);
char **args_construct(char *buffer);
void valid_getline(char *buffer, int len, char **args, char **env_args);
int noutty(char **av __attribute__((unused)));

#endif /*SIMPLESHELL*/
