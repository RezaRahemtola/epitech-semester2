/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** Functions to handle commands
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

command_t *init_command(char *str, int type)
{
    command_t *command = malloc(sizeof(command_t));

    command->str = my_strdup(str);
    command->next = type;
    command->path = NULL;
    command->argv = NULL;
    command->input = get_input_redir(command);
    command->output = get_output_redir(command);;
    return (command);
}

void destroy_command(void *command)
{
    command_t *tmp = command;

    if (tmp == NULL)
        return;
    free(tmp->str);
    free(tmp->path);
    my_free_2d_array(tmp->argv);
    destroy_redir(tmp->input);
    destroy_redir(tmp->output);
    free(tmp);
}
