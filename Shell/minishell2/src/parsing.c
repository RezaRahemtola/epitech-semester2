/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** Parsing functions
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "my.h"

static bool is_valid_command(const char *command)
{
    struct stat sb;

    if (get_builtin(command) != -1)
        return (true);
    if (lstat(command, &sb) == -1)
        return (false);
    if (access(command, X_OK) == -1)
        return (false);
    if (S_ISDIR(sb.st_mode))
        return (false);
    if (my_strstr(command, "/") == NULL)
        return (false);
    return (true);
}

static void disp_command_error(const char *command)
{
    struct stat sb;

    if (access(command, F_OK) == -1 || my_strstr(command, "/") == NULL) {
        my_puterror(command);
        my_puterror(": Command not found.\n");
        return;
    }
    if (lstat(command, &sb) == -1)
        return;
    if (S_ISDIR(sb.st_mode) || access(command, X_OK) == -1) {
        my_puterror(command);
        my_puterror(": Permission denied.\n");
        return;
    }
}

static char **get_paths(list_t *env)
{
    char *str = get_env_value(env, "PATH=");
    char **paths = NULL;

    if (str == NULL)
        return (NULL);
    paths = my_strsplit(str, ':');
    free(str);
    return (paths);
}

static char *search_paths(char **paths, char *command)
{
    char *curr = NULL;

    if (paths == NULL)
        return (NULL);
    for (int i = 0; paths[i] != NULL; i++) {
        curr = my_stringf("%s/%s", paths[i], command);
        if (is_valid_command(curr)) {
            my_free_2d_array(paths);
            return (curr);
        }
        free(curr);
    }
    my_free_2d_array(paths);
    return (NULL);
}

char *get_command_path(char *command, list_t *env)
{
    char **paths = get_paths(env);
    char *path_command = NULL;

    if (is_valid_command(command)) {
        my_free_2d_array(paths);
        return (my_strdup(command));
    }
    path_command = search_paths(paths, command);
    if (path_command != NULL)
        return (path_command);
    disp_command_error(command);
    return (NULL);
}
