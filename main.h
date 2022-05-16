#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * struct list_s - singly linked list of values
 * @name: string
 * @value: string
 * @index: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *name;
	char *value;
	int index;
	struct list_s *next;
} list_t;

/* main.c */
void sig_handler(int sig);

/* env_list.c */
list_t *create_env(char **env, list_t *env_list);
char *_getenv(list_t *env_list, 	char *name);
void print_env(list_t *env_list);

/* lists.c */
list_t *add_node_end(list_t **head, const char *name, const char *value);
list_t *create_node(const char *name, const char *value, int index);
list_t *split_string(char *str, char *delim);
void free_node(list_t *h);
void free_list(list_t *h);
size_t list_len(const list_t *h);
char **list_to_array(const list_t *h);
void free_array(char **arr);
size_t print_list(const list_t *h);

/* shell.c */
int shell(list_t *env_list, char *shell_name);
char *get_input(void);
void print_error(char *shell_name, char *message);

/* which.c */
char *get_full_name(char *name, list_t *env_list);
char *get_full_path(char *filename, list_t *path_list);
char *create_path(char *dir, char *filename);
int is_command(char *filename);

/* strings.c */
char *_strcpy(char *dest, const char *src);
unsigned int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);
int is_in_str(const char *str, char c);

#endif
