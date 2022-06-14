/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions to display env
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

int my_env(char **argv, list_t **env)
{
    list_t *list = *env;

    (void) argv;
    for (; list != NULL; list = list->next) {
        my_putstr(list->data);
        my_putchar('\n');
    }
    return (0);
}

char *get_env_value(list_t *env, char *name)
{
    int len = my_strlen(name);
    char *value = NULL;

    while (env != NULL && my_strncmp(env->data, name, len) != 0)
        env = env->next;
    if (env == NULL)
        return (NULL);
    value = env->data + len;
    return (my_strdup(value));
}
