/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to check if strings meet criteria
*/

#include "my.h"

bool my_str_islower(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return (false);
    }
    return (true);
}

bool my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return (false);
    }
    return (true);
}

bool my_str_isprintable(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 && str[i] != 127)
            return (false);
    }
    return (true);
}

bool my_charinstr(char c, const char *str)
{
    if (str == NULL)
        return (false);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (true);
    }
    return (false);
}
