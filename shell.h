#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0
#define INFO_INIT { 0 }

typedef struct
{
	int readfd;
} info_t;

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


void display_prompt(void);
void leo_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(char *command, char *path[]) ;
char *_strncat(char *dest, char *src, int i);
char *_strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int i);
int main(int arg_count, char **arg_val);
void populate_env_list(info_t *info);
void read_history(info_t *info);
void hsh(info_t *info, char **arguments);
int _putchar(char c);
void _puts(const char *str);
int  _putchar(char ch);



#endif
