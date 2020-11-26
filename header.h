#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/* main*/

/* exit */
void _ctrl_c(int sig);
void _sfree(char **i_want_to_be_free);
void _error(int count_w, char *array[]);

/* get_env */
int _print_env(char *buffer);


/* str_manipulation*/
char **_split_string(char *str, char *delim);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
char *_token(char *array[]);
char *_strdup(char *str);

/* execution */
int _exec(int count_w, char *token, char *array[]);

/* str_man */
char *_itoa(int count_w);
char *_string_directory(char **argv);

#endif