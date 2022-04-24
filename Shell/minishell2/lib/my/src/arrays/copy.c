/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to copy and duplicate arrays
*/

#include <stdlib.h>
#include "my_arrays.h"
#include "my_strings.h"

char **my_arraydup(char **array)
{
    char **new = NULL;
    int len = my_arraylen(array);

    if (array == NULL)
        return (NULL);
    new = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; i < len; i++)
        new[i] = my_strdup(array[i]);
    new[len] = NULL;
    return (new);
}
