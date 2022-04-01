/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to display elements
*/

#include <unistd.h>
#include "my_strings.h"

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}

void my_puterror(const char *str)
{
    write(2, str, my_strlen(str));
}
