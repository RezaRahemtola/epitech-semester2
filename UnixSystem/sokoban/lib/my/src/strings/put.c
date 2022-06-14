/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to display elements
*/

#include <unistd.h>
#include "strings.h"

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
