/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to measure arrays length
*/

#include "my.h"

int my_arraylen(char **array)
{
    int i = 0;

    if (array == NULL)
        return (0);
    while (array[i] != NULL)
        i++;
    return (i);
}
