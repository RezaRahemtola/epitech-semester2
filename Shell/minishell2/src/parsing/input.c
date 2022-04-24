/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** Functions to parse input
*/

#include <string.h>
#include "minishell.h"
#include "mylist.h"
#include "my.h"

static list_t *split_input(char *buffer)
{
    list_t *list = NULL;
    command_t *command = NULL;
    char **semicolon = my_strsplit(buffer, ';');
    char **pipes = NULL;
    int type = NONE;

    for (int i = 0; semicolon[i] != NULL; i++) {
        pipes = my_strsplit(semicolon[i], '|');
        for (int j = 0; pipes[j] != NULL; j++) {
            type = (j + 1 < my_arraylen(pipes)) ? PIPE : NONE;
            command = init_command(pipes[j], type);
            mylist_append(command, &list);
        }
        my_free_2d_array(pipes);
    }
    my_free_2d_array(semicolon);
    return (list);
}

list_t *parse_input(char *buffer, list_t *env)
{
    list_t *commands = split_input(buffer);
    command_t *command = NULL;
    list_t *tmp = commands;

    while (tmp != NULL) {
        command = tmp->data;
        command->argv = str_to_word_array(command->str);
        if (command->argv != NULL)
            command->path = get_command_path(command->argv[0], env);
        tmp = tmp->next;
    }
    if (check_parsing_error(commands))
        return (NULL);
    return (commands);
}
