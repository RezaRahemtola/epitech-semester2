/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Malloc a 2d array
*/

#include <stdlib.h>

char **my_malloc_2d_array(int nb_rows, int nb_cols)
{
    char **new_array = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++)
        new_array[i] = malloc(sizeof(char) * nb_cols);
    return (new_array);
}

void my_free_2d_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
