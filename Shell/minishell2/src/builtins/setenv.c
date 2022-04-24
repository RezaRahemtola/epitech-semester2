/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions for the setenv builtin
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

static bool check_setenv_errors(int argc, char **argv)
{
    if (argc > 3) {
        my_puterror("setenv: Too many arguments.\n");
        return (true);
    }
    if (argc >= 2 && my_char_isalpha(argv[1][0]) == false) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return (true);
    }
    if (argc >= 2 && my_str_isalphanum(argv[1]) == false) {
        my_puterror("setenv: Variable name must contain ");
        my_puterror("alphanumeric characters.\n");
        return (true);
    }
    return (false);
}

static void update_current_var(list_t *list, char *var, char *new)
{
    for (; list != NULL; list = list->next) {
        if (my_strncmp(var, list->data, my_strlen(var)) == 0) {
            free(list->data);
            list->data = new;
            break;
        }
    }
}

static void set_var(list_t **list, char *var, char *value)
{
    char *full_var = my_newstrcat(var, "=", 0, 0);
    char *current_value = get_env_value(*list, full_var);
    char *new = my_stringf("%s=%s", var, value);

    if (current_value == NULL)
        mylist_append(new, list);
    else
        update_current_var(*list, full_var, new);
    free(current_value);
    free(full_var);
}

int my_setenv(char **argv, list_t **env)
{
    int exit = 0;
    int argc = my_arraylen(argv);

    if (check_setenv_errors(argc, argv))
        return (1);
    if (argc == 1) {
        my_env(argv, env);
    } else {
        set_var(env, argv[1], argv[2]);
    }
    return (exit);
}
