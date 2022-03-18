/*
** EPITECH PROJECT, 2022
** duo_stumper2
** File description:
** error_tech.c
*/

#include <stdbool.h>
#include "connect.h"

bool invalid_option(param_t *param)
{
    if (param->width < 1 || param->width > 80)
        return true;
    if (param->height < 1 || param->height > 16)
        return true;
    if (param->width * param->height < 20)
        return true;
    if (param->player_one == param->player_two)
        return true;
    if (param->player_one == param->referee)
        return true;
    if (param->player_two == param->referee)
        return true;
    return false;
}
