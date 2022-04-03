/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to play with strings memory
*/

#include <stdlib.h>
#include <stddef.h>

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

void *my_realloc(void *ptr, size_t size)
{
    void *new = malloc(size);

    if (ptr == NULL && new != NULL)
        return (new);
    if (new == NULL) {
        free(ptr);
        return (NULL);
    }
    for (size_t i = 0; i < size - 1; i++)
        ((char *)new)[i] = ((char *)ptr)[i];
    free(ptr);
    return (new);
}
