#ifndef MINISHELL_H
#define MINISHELL_H

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

char *_getenv(const char *name);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
void _array_this(char *entry, char **av);
char *_null_char(char *string);
char *_concat(int n, ...);
char *_itoa(int num);
void not_found(char *argv, int count, char *string, int *retVal);
char *_getenv(const char *name);
void create_child(char *route, char **av, int *retVal);
char *_searchpath(char *com);
char *_strdup(char *src);
int speComs(char *entry, int *retVal);
int compare(char *entry);
char *_lessSpaces(char *entry);
char *_deleteChar(char *entry, int indx);
void freeArr(char *arr[]);
int argsLen(va_list args, int n);
void conditions(char *argv, char *entry, int *retVal, int *count);
void sigfunc(int signal);

#endif
