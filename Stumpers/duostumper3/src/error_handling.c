/*
** EPITECH PROJECT, 2022
** duostumper3
** File description:
** Functions for error handling
*/

#include <stdbool.h>
#include "my_strings.h"

static bool is_key(char *str)
{
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-')
        return (false);
    for (int i = 1; i < my_strlen(str); i++)
        if (str[i] < '0' && str[i] > '9')
            return (false);
    return (true);
}

bool is_error(int argc, char **argv)
{
    if (argc != 4) {
        my_puterror("Invalid number of arguments\n");
        return (true);
    }
    if (my_strcmp(argv[1], "-f") != 0 && my_strcmp(argv[1], "-s") != 0) {
        my_puterror("Invalid parameter, you can use -f or -s\n");
        return (true);
    }
    if (!is_key(argv[3])) {
        my_puterror("Invalid key provided.\n");
        return (true);
    }
    return (false);
}
