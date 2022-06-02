/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to play with strings memory
*/

#include <stdlib.h>

char *my_str_allocfill(int nb_char, char c)
{
    char *str = malloc(sizeof(char) * nb_char);

    if (str == NULL)
        return (NULL);
    for (int i = 0; i < nb_char; i++)
        str[i] = c;
    return (str);
}
