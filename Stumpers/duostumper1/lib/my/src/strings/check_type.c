/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to check if a string match a type of char
*/

#include "my.h"

bool my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (true);
    return (false);
}

bool my_str_isalpha(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return (false);
    }
    return (true);
}

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

bool my_str_isalphanum(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_isalpha(str[i]) && !my_char_isnum(str[i]))
            return (false);
    }
    return (true);
}
