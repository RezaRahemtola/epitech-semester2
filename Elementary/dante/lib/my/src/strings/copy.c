/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to copy strings
*/

#include "my_strings.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (src[n - 1] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > my_strlen(src))
        dest[i] = '\0';
    return (dest);
}
