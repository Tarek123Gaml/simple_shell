#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3

/* for convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE       ".simple_shell_history"
#define HIST_MAX        4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
        int num;
        char *str;
        struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
        char *arg;
        char **argv;
        char *path;
        int argc;
        unsigned int line_count;
        int err_num;
        int linecount_flag;
        char *fname;
        list_t *env;
        list_t *history;
        list_t *alias;
        char **environ;
        int env_changed;
        int status;

        char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
        int cmd_buf_type; /* CMD_type ||, &&, ; */
        int readfd;
        int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
        0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
        char *type;
        int (*func)(info_t *);
} builtin_table;

/**string functions**/

int _strlen(char *s);

int _strcmp(char *s ,char *s1);

char *start_with(const char *s, const char *s1);
char *starts_with(const char *haystack, const char *needle);

char *_strcat(char *s, char *s1);
char *_strcat(char *dest, char *src);

char *_strcpy(char *s, char *s1);
char *_strcpy(char *dest, char *src);

char *_strdup(const char *s);
char *_strdup(const char *str);

void _puts(char *str);

int _putchar(char c);

char *_strncpy(char *dest, char *src, int n);

char *_strncat(char *dest, char *src, int n);

char *_strchr(char *s, char c);

char** strtow(const char* str, const char* delimiter, int* wordCount);
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);

/**memory functions**/

int bfree(void **ptr);

char *_memset(char *s, char b, unsigned int n);

void ffree(char **pp);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**other functions**/

int _atoi(char *str);

int is_alpha(int ch);
int _isalpha(int c);

int is_a_delim(char ch, char *delim);
int is_delim(char c, char *delim);

int inter_active(info_t *info);
int interactive(info_t *info);

char change_num(long int num, int base, int flage);
char *convert_number(long int num, int base, int flags);

int err_atoi(char *str);
int _erratoi(char *s);

void print_error(info_t *info, char *erstr);

int print_dec(int input, int fdis);
int print_d(int input, int fd);

void delete_comments(char *buffer);
void remove_comments(char *buf);

/**list functions**/

list_t *add_node_str(list_t **head, const char *str, int num);
list_t *add_node(list_t **head, const char *str, int num);

list_t *add_node_end(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);

size_t print_list_str(const list_t *h);

int delete_xnode(list_t **head, unsigned int index);
int delete_node_at_index(list_t **head, unsigned int index);

void free_list(list_t **head_ptr);

size_t list_len(const list_t *f);

char **list_to_strings(list_t *head);

size_t print_list(const list_t *h);

list_t *node_starts_with(list_t *node, char *prefix, char c);

ssize_t get_node_index(list_t *head, list_t *node);

/**functions path**/

int is_cmd(info_t *, char *);

char *dup_chars(char *, int, int);

char *find_path(info_t *, char *, char *);

/**Umfeld functions**/

int _mon_new_var(info_t *info);
int _mysetenv(info_t *info);

char *get_var_env(info_t *info, const char *Nom);
char *_getenv(info_t *info, const char *name);

int Mon_envir(info_t *info;
int _myenv(info_t *info);

int envir_list(info_t *info);
int populate_env_list(info_t *info);

int unset_env_var(info_t *info);
int _myunsetenv(info_t *info);

int delete_var(info_t *info, char *var);
int _unsetenv(info_t *info, char *var);

int novel_env(info_t *info, char *var, char *value);
int _setenv(info_t *info, char *var, char *value);

char **copy_envir(info_t *info);
char **get_environ(info_t *info);

/**history functions**/

int renumber_history(info_t *info);

int build_history_list(info_t *info, char *buf, int linecount);

int read_history(info_t *info);

int write_history(info_t *info);

char *get_history(info_t *info);
char *get_history_file(info_t *info);

/**info functions**/

void clear_info(info_t *info);

void set_info(info_t *info, char **av);

void free_info(info_t *info, int all);

/**pseudo**/

int pro_change(info_t *info);
int _myhelp(info_t *info);

int curnt_dir(info_t *info);
int _mycd(info_t *info);

int Sh_exit(info_t *info);
int _myexit(info_t *info);

int imprime_pseud(list_t *node);
int print_alias(list_t *node);

int pseudy(info_t *info);
int _myalias(info_t *info);

int Yes_pseud(info_t *info, char *str);
int set_alias(info_t *info, char *str);

int Not_pseud(info_t *info, char *str);
int unset_alias(info_t *info, char *str);

int histo_list(info_t *info);
int _myhistory(info_t *info);

/**weg**/

char *trouve_way(info_t *info, char *pathstr, char *cmd);
char *find_path(info_t *info, char *pathstr, char *cmd);

char *duplic_carac(char *pathstr, int start, int stop);
char *dup_chars(char *pathstr, int start, int stop);

int exe_cmd(info_t *info, char *path);
int is_cmd(info_t *info, char *path);

/**test file**/

int find_chain(info_t *info, char *buf, size_t *p);
int is_chain(info_t *info, char *buf, size_t *p);

void check_status(info_t *info, char *buf, size_t *p, size_t i, size_t len);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);

int show_alias(info_t *info);
int replace_alias(info_t *info);

int vals_vars(info_t *info);
int replace_vars(info_t *info);

int replace_string(char **old, char *new);

/**get_line file**/

ssize_t take_buf(info_t *info, char **buf, size_t *len);
ssize_t input_buf(info_t *info, char **buf, size_t *len);

ssize_t take_input(info_t *info);
ssize_t get_input(info_t *info);

ssize_t read_buf(info_t *info, char *buf, size_t *i);

int _get_line(info_t *info, char **ptr, size_t *length);
int _getline(info_t *info, char **ptr, size_t *length);

void sigintHandler(__attribute__((unused))int sig_num);

/* hshs.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* errors */

void eput_str(char *str);
void _eputs(char *str);

int _eput_char(char ch);
int _eputchar(char c);

int _put_fdis(char ch, int fdis);
int _putfd(char c, int fd);

int _put_str_fdis(char *str, int fd);
int _putsfd(char *str, int fd);

#endif
