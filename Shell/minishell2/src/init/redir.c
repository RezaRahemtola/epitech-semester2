/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** Functions to init and destroy redir
*/

#include <stdlib.h>
#include "minishell.h"

redir_t *init_redir(char *str, int type)
{
    redir_t *redir = malloc(sizeof(redir_t));

    redir->str = str;
    redir->type = type;
    return (redir);
}

void destroy_redir(redir_t *redir)
{
    if (redir == NULL)
        return;
    free(redir->str);
    free(redir);
}
