/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to play with strings memory
*/

#include "my.h"

char *my_str_fill(char *str, char c)
{
    if (str == NULL)
        return (str);
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = c;
    return (str);
}

char *my_str_allocfill(int nb_char, char c)
{
    char *str = malloc(sizeof(char) * nb_char);

    if (str == NULL)
        return (NULL);
    for (int i = 0; i < nb_char; i++)
        str[i] = c;
    return (str);
}
