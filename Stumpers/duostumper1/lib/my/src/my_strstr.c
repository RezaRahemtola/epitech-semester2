/*
** EPITECH PROJECT, 2021
** MY_STRSTR
** File description:
** Task05
*/

#include <stddef.h>
#include "my.h"

char *my_strstr(char const *str, char const *to_find)
{
    int i_to_find = 0;

    if (my_strlen(to_find) == 0)
        return ((char *)(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != to_find[i_to_find]) && (i == 0 || str[i] != str[i - 1]))
            i_to_find = 0;
        if (str[i] == to_find[i_to_find])
            i_to_find++;
        if (to_find[i_to_find] == '\0')
            return ((char *)(&str[i - i_to_find + 1]));
    }
    return (NULL);
}
