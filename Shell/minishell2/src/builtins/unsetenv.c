/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions for unsetenv builtin
*/

#include <stdlib.h>
#include "minishell.h"
#include "my_arrays.h"
#include "my_strings.h"

static bool check_unsetenv_errors(int argc)
{
    if (argc == 1) {
        my_puterror("unsetenv: Too few arguments.\n");
        return (true);
    }
    return (false);
}

static void remove_var(char *var, list_t **list)
{
    int len = my_strlen(var) + 1;
    char *pattern = my_newstrcat(var, "=", 0, 0);
    list_t *tmp = *list;
    list_t *previous = *list;

    if (tmp != NULL && my_strncmp(pattern, tmp->data, len) == 0) {
        *list = tmp->next;
        obj_destroy(tmp, true, &free);
        free(pattern);
        return;
    }
    while (tmp != NULL && my_strncmp(pattern, tmp->data, len) != 0) {
        previous = tmp;
        tmp = tmp->next;
    }
    free(pattern);
    if (tmp == NULL)
        return;
    previous->next = tmp->next;
    obj_destroy(tmp, true, &free);
}

int my_unsetenv(char **argv, list_t **env)
{
    int exit = 0;
    int argc = my_arraylen(argv);

    if (check_unsetenv_errors(argc))
        return (1);
    for (int i = 1; argv[i] != NULL; i++) {
        if (my_strcmp(argv[i], "*") == 0) {
            mylist_destroy(*env, true, &free);
            *env = NULL;
        } else {
            remove_var(argv[i], env);
        }
    }
    return (exit);
}
