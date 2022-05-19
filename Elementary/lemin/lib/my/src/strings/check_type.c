/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to check if a string match a type of char
*/

#include <stdbool.h>

bool my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}
