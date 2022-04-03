/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to measure arrays length
*/

#include "my_strings.h"

int my_arraylen(char **array)
{
    int i = 0;

    if (array == NULL)
        return (0);
    while (array[i] != NULL)
        i++;
    return (i);
}

int my_array_biggest_len(char **array)
{
    int biggest = 0;

    if (array == NULL)
        return (0);
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strlen(array[i]) > biggest)
            biggest = my_strlen(array[i]);
    }
    return (biggest);
}
