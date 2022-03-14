/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to display elements
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}

void my_puterror(const char *str)
{
    write(2, str, my_strlen(str));
}
