/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** header
*/

#pragma once

#include "mylist.h"
#include "parsing.h"

typedef struct builtin_s {
    char *command;
    int (*fun_ptr)(char **argv, list_t **env);
} builtin_t;

typedef enum {
    NONE,
    PIPE
} next_types_t;

typedef enum {
    NO_IN,
    NO_OUT,
    SIMPLE_IN,
    SIMPLE_OUT,
    DOUBLE_IN,
    DOUBLE_OUT
} redir_types_t;

typedef struct redir_s {
    char *str;
    redir_types_t type;
} redir_t;

typedef struct command_s {
    char *str;
    char *path;
    char **argv;
    int next;
    redir_t *input;
    redir_t *output;
} command_t;

// Redirections
redir_t *init_redir(char *str, int type);
void destroy_redir(redir_t *redir);
redir_t *get_input_redir(command_t *command);
redir_t *get_output_redir(command_t *command);

// General
int minishell(char **env);
char *get_input(list_t *env);

// Execute
int exec_input(char *buffer, list_t **env, bool *is_exit);
bool set_exec_fd(redir_t *input, redir_t *output);

// Commands
command_t *init_command(char *str, int type);
void destroy_command(void *command);

// Builtins
int get_builtin(const char *command);
int my_cd(char **argv, list_t **env);
int my_setenv(char **argv, list_t **env);
int my_unsetenv(char **argv, list_t **env);
int my_env(char **argv, list_t **env);
int my_exit(char **argv, list_t **env);

// Env
char *get_env_value(list_t *env, char *name);

extern const builtin_t builtins[6];
