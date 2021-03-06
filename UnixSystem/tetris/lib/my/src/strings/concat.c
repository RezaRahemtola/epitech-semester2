/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to concatenate strings
*/

#include <stdlib.h>
#include "my_strings.h"

static char *my_strcat(char *dest, char *src, bool free_src)
{
    int i = 0;
    int len_dest = my_strlen(dest);

    if (src == NULL)
        return (dest);
    while (src[i] != '\0') {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i] = '\0';
    if (free_src)
        free(src);
    return (dest);
}

char *my_newstrcat(char *str1, char *str2, bool free1, bool free2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *new_str = my_str_allocfill(sizeof(char) * len + 1, '\0');

    my_strcpy(new_str, str1);
    if (free1)
        free(str1);
    my_strcat(new_str, str2, free2);
    return (new_str);
}
