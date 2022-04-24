/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to measure string lengths
*/

#include <stddef.h>

int my_strlen(const char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}
