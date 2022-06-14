/*
** EPITECH PROJECT, 2022
** bs minishell
** File description:
** step 1
*/

#include <signal.h>
#include <unistd.h>
#include "minishell.h"
#include "my_strings.h"

static void sigint_handler(int param)
{
    if (isatty(0))
        my_putstr("\n$> ");
    param = param;
}

int main(int argc, char **argv, char **env)
{
    int exit = 0;

    (void) argv;
    if (argc != 1)
        return (84);
    signal(SIGINT, sigint_handler);
    exit = minishell(env);
    if (isatty(0))
        my_putstr("exit\n");
    return (exit);
}
