/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Malloc a 2d array
*/

#include <stdlib.h>
#include "my_strings.h"

char **my_malloc_2d_array(int nb_rows, int nb_cols)
{
    char **array = malloc(sizeof(char *) * (nb_rows + 1));

    if (array == NULL)
        return (NULL);
    for (int i = 0; i < nb_rows; i++)
        array[i] = my_str_allocfill(sizeof(char) * (nb_cols + 1), '\0');
    array[nb_rows] = NULL;
    return (array);
}

char **my_array_allocfill(int nb_rows, int nb_cols, char c)
{
    char **array = my_malloc_2d_array(nb_rows, nb_cols);

    if (array == NULL)
        return (NULL);
    for (int i = 0; i < nb_rows; i++)
        for (int j = 0; j < nb_cols; j++)
            array[i][j] = c;
    return (array);
}

void my_free_2d_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
