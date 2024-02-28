#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


#define TOK_DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

extern  char **environ;

char *read_line(void);
char **tokenize(char *line);
char *_getenv(char *var);
char *_getpath(char *command);
int exec(char **command, char **argv, int idx);
void print_error(char *name, char *cmd, int idx);

/*my getline version*/
ssize_t my_getline(char **line, size_t *len, FILE *stream);

/*my strtok version*/
char *my_strtok(char *str, const char *delim);

/*builtin functions*/
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);
void setenv_command(char **command, int *status);
void unsetenv_command(char **command, int *status);





/*str functions*/
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *my_strchr(const char *string, int c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
size_t _strcspn(const char *str1, const char *str2);
char *_itoa(int n);
void reverse_string(char *str, int len);
int is_positive_num(char *str);


void free_array_string(char **arr);
void _realloc(void *ptr, size_t size);

#endif

