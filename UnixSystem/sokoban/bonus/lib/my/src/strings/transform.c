/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to transform strings
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}

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

static bool to_capitalize(char *str, int i)
{
    bool lowletter = (str[i] >= 'a' && str[i] <= 'z') ? true : false;
    bool upletter = (str[i] >= 'A' && str[i] <= 'Z') ? true : false;

    if (i == 0)
        return (true);
    if (!lowletter && !upletter && (str[i - 1] < '0' || str[i - 1] > '9'))
        return (true);
    return (false);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') && to_capitalize(str, i))
            str[i] -= 32;
        if ((str[i] >= 'A' && str[i] <= 'Z') && !to_capitalize(str, i))
            str[i] += 32;
    }
    return (str);
}
