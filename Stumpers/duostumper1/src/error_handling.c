/*
** EPITECH PROJECT, 2022
** duo stumper 1
** File description:
** error_handling.c
*/

#include "fractals.h"
#include "my.h"

static int verify_char(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++)
        if (!my_charinstr(arg[i], ".#@"))
            return (0);
    return (1);
}

int error_handling(int argc, char **argv)
{
    if (argc != 4)
        return (0);
    if (!my_str_isnum(argv[1]) || my_getnbr(argv[1]) < 0
        || !verify_char(argv[2]) || !verify_char(argv[3])
        || my_strlen(argv[2]) != my_strlen(argv[3]))
        return (0);
    return (1);
}
