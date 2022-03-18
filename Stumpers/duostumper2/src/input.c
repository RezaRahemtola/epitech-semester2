/*
** EPITECH PROJECT, 2022
** duo_stumper2
** File description:
** input.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "connect.h"
#include "my.h"

static bool invalid_input(param_t *params, char *buff, char **map)
{
    int i = 0;

    if (buff == NULL)
        return true;
    i = my_getnbr(buff);
    if (i < 1 || i > params->width)
        return true;
    if (map[0][i - 1] != '.')
        return true;
    return false;
}

int get_input(param_t *param, char player, char **map)
{
    size_t bufsize = 0;
    char *buff = NULL;
    int result = 0;

    while (invalid_input(param, buff, map)) {
        my_printf("Player %c, where do you want to play: ", player);
        if (getline(&buff, &bufsize, stdin) == -1)
            return (-1);
        result = my_getnbr(buff);
    }
    free(buff);
    return result;
}
