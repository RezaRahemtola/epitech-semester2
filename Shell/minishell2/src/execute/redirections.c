/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** Functions to handle redirections when executing commands
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "minishell.h"
#include "my.h"

static bool is_fd_error(redir_t *input, redir_t *output, int fd_in, int fd_out)
{
    char *error = NULL;
    char *filename = NULL;

    if (fd_in == -1 || fd_out == -1) {
        filename = (fd_in == -1) ? input->str : output->str;
        error = my_stringf("%s: %s.\n", filename, strerror(errno));
        my_puterror(error);
        free(error);
        return (true);
    }
    return (false);
}

bool set_exec_fd(redir_t *input, redir_t *output)
{
    int fd_in = 0;
    int fd_out = 1;

    if (output != NULL && output->type == SIMPLE_OUT)
        fd_out = open(output->str, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (output != NULL && output->type == DOUBLE_OUT)
        fd_out = open(output->str, O_WRONLY | O_CREAT | O_APPEND, 0664);
    if (input != NULL && input->type == SIMPLE_IN)
        fd_in = open(input->str, O_RDONLY);
    if (is_fd_error(input, output, fd_in, fd_out))
        return (false);
    dup2(fd_in, 0);
    dup2(fd_out, 1);
    return (true);
}
