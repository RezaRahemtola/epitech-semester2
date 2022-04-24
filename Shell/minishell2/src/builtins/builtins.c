/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Builtins functions
*/

#include "minishell.h"
#include "my_strings.h"

int get_builtin(const char *command)
{
    for (int i = 0; builtins[i].command != NULL; i++) {
        if (my_strcmp(command, builtins[i].command) == 0) {
            return (i);
        }
    }
    return (-1);
}
