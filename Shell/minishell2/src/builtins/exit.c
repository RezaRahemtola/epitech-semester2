/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions for the exit builtin
*/

#include "minishell.h"
#include "my.h"

static bool check_exit_errors(int argc, char **argv)
{
    if (argc > 2) {
        my_puterror("exit: Expression Syntax.\n");
        return (true);
    }
    if (argc == 2 && my_char_isnum(argv[1][0]) && !my_str_isnum(argv[1])) {
        my_puterror("exit: Badly formed number.\n");
        return (true);
    }
    if (argc == 2 && !my_str_isnum(argv[1])) {
        my_puterror("exit: Expression Syntax.\n");
        return (true);
    }
    return (false);
}

int my_exit(char **argv, list_t **env)
{
    int exit = 0;
    int argc = my_arraylen(argv);

    if (check_exit_errors(argc, argv))
        return (1);
    (void) env;
    if (argv[1] != NULL)
        exit = my_getnbr(argv[1]);
    return (exit);
}
