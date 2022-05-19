/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to check if strings meet criteria
*/

#include <stdbool.h>
#include <stddef.h>

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
