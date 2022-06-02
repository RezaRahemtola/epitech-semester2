/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to transform strings
*/

#include "my_strings.h"

char *my_revstr(char *str)
{
    int end = my_strlen(str) - 1;
    char temp = 0;

    for (int start = 0; end - start >= 0; start++) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
    }
    return (str);
}
