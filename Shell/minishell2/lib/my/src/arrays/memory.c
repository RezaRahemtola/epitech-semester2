/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Malloc a 2d array
*/

#include <stdlib.h>
#include "my_strings.h"

void my_free_2d_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
