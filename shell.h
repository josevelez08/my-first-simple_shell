#ifndef SHELLH
#define SHELLH
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
/**
*struct shell - structura
*@path: array of strings
*@getline: stream
*@counter: counter
*@counterpath: counter for path liberation
*@command_to_ex: direction and command in a string
*@token: command and arguments
*@i: counter
*@str: string
*/
typedef struct shell
{
	char *getline;
	int counter;
	int counterpath;
	char **token;
	char **path;
	char **command_to_ex;
	char *str;
	int i;
} shell_t;
#define BUFFER_SIZE 1024
shell_t *input();
shell_t *tokens(shell_t *buffer);
int execute(shell_t *struc);
int mem_free(shell_t *struc);
int prompt(void);
int _putchar(char c);
int _getchar(void);
char *_strdup(char *src);
shell_t *div_path(shell_t *);
shell_t *find(shell_t *);
void signal_handler(int signal __attribute__((unused)));
char **str_complet(char *, char *);
int _strcmp(char *str1, char *str2);
int process(shell_t *data);
int helpfree(shell_t *data);
#endif
