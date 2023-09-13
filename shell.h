#ifndef SHELL_H
#define SHELL_H

#define BUFFSIZE 64
#define DELIM " "

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

/**
 *Main Loop - Function
 *Return: int
 */
int main_loop(void);

/**
 *String Functions
 */
int _putchar(char c);
void _puts(char *c);
int _strlen(char *c);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);

/**
 *checks Functions
 */
void sig_handler(int sig_num);
void _EOF(int len, char *buff);
void _isatty(void);

/**
 *Line_parser Functions
 */
char **commandsplit(char *str, const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void execute(char **argv);

/**
 * Link Path Functions
 */
char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linklist(char *path);
/*
 * Function to compare command arrgument with the stored in linked list nodes
 */
char *_which(char *filename, list_path *head);
/*
 * Function Selsction the apropriate buildin Function acording to argv[0]
 */
void(*checkbuild(char **arv))(char **arv);
/*
 * Buildins Functions
 */
void _exit(char **arv);
int _atoi(char *s);
void _env(char **arv __attribute__ ((unused)));
void _setenv(char **arv);
void _unsetenv(char **arv);

extern char **environ;
#endif
