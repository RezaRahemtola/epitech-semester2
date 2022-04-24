/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions to execute a command
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include "my.h"

const builtin_t builtins[6] = {{"cd", &my_cd}, {"env", &my_env},
{"setenv", &my_setenv}, {"unsetenv", &my_unsetenv}, {"exit", &my_exit},
{NULL, NULL}};

static int parent_waiting(void)
{
    int wstatus = 0;

    wait(&wstatus);
    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) == SIGFPE)
            my_puterror("Floating exception");
        else
            my_puterror(strsignal(WTERMSIG(wstatus)));
        if (WCOREDUMP(wstatus))
            my_puterror(" (core dumped)");
        my_puterror("\n");
    }
    if (WIFEXITED(wstatus))
        return (WEXITSTATUS(wstatus));
    return (0);
}

static int exec_builtin(command_t *command, list_t **env, bool *is_exit)
{
    int exit = 0;
    int index = get_builtin(command->argv[0]);

    exit = builtins[index].fun_ptr(command->argv, env);
    if (my_strcmp(builtins[index].command, "exit") == 0)
        *is_exit = true;
    return (exit);
}

static int exec_command(command_t *command, list_t **env_list, bool *is_exit)
{
    int exit = 0;
    char **env_array = mylist_to_array(*env_list, NULL);

    if (command->path == NULL) {
        free(env_array);
        return (1);
    }
    if (get_builtin(command->argv[0]) != -1) {
        exit = exec_builtin(command, env_list, is_exit);
        free(env_array);
        return (exit);
    }
    if (fork() == 0) {
        if (set_exec_fd(command->input, command->output))
            execve(command->path, command->argv, env_array);
    } else {
        exit = parent_waiting();
    }
    free(env_array);
    return (exit);
}

int exec_input(char *buffer, list_t **env, bool *is_exit)
{
    list_t *list = parse_input(buffer, *env);
    list_t *tmp = list;
    int exit = 0;

    for (command_t *command = NULL; tmp != NULL; tmp = tmp->next) {
        command = tmp->data;
        exit = exec_command(command, env, is_exit);
    }
    mylist_destroy(list, true, &destroy_command);
    return (exit);
}
