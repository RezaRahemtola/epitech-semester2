/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to copy strings
*/

#include <stdlib.h>
#include "my_strings.h"

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (src == NULL)
        return (dest);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *new_str = malloc(sizeof(char) * my_strlen(src) + 1);

    if (new_str == NULL)
        return (NULL);
    my_strcpy(new_str, src);
    return (new_str);
}
