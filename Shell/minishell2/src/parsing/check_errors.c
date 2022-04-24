/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** Functions to test for parsing invalid data
*/

#include "minishell.h"
#include "my_strings.h"

static bool is_redirection_error(redir_t *input, redir_t *output)
{
    if ((output->type != NO_OUT && output->str == NULL) ||
    (input->type != NO_IN && input->str == NULL)) {
        my_puterror("Missing name for redirect.\n");
        return (true);
    }
    return (false);
}

static bool is_pipe_error(command_t *command, list_t *next)
{
    command_t *next_command = NULL;

    if (command->next == PIPE) {
        next_command = next->data;
        if (command->path == NULL || next_command->path == NULL) {
            my_puterror("Invalid null command.\n");
            return (true);
        }
    }
    return (false);
}

bool check_parsing_error(list_t *list)
{
    command_t *command = NULL;
    bool is_error = false;

    while (list != NULL && !is_error) {
        command = list->data;
        is_error = is_redirection_error(command->input, command->output);
        is_error = is_pipe_error(command, list->next) ? true : is_error;
        list = list->next;
    }
    return (is_error);
}
