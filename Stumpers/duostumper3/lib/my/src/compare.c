/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to compare strings
*/

#include <stddef.h>
#include "my_strings.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    if (s1 == NULL)
        return (-s2[0]);
    else if (s2 == NULL)
        return (s1[0]);
    while (s1[i] != '\0') {
        if (s2[i] == '\0')
            return (s1[i]);
        if (s2[i] != s1[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}
