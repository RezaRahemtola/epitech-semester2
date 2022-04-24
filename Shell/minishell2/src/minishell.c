/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Main functions
*/

#include <stdlib.h>
#include "minishell.h"
#include "my_strings.h"

int minishell(char **original_env)
{
    list_t *env = array_to_mylist(original_env, &my_strdup);
    char *buffer = NULL;
    int exit = 0;
    bool is_exit = false;

    while (!is_exit) {
        buffer = get_input(env);
        if (buffer == NULL)
            break;
        exit = exec_input(buffer, &env, &is_exit);
        free(buffer);
    }
    mylist_destroy(env, true, &free);
    return (exit);
}
