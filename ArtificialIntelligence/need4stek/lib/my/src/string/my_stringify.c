/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_stringify function
*/

#include <stdlib.h>

char *my_stringify(char c)
{
    char *str = malloc(sizeof(char) * 2);

    if (str == NULL) {
        return (NULL);
    }
    str[0] = c;
    str[1] = '\0';
    return (str);
}
