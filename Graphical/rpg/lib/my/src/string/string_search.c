/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** String search utilities
*/

#include <string.h>
#include "my.h"

char *my_strchr(char *str, char c)
{
    for (; *str != '\0'; str++)
        if (*str == c)
            return str;
    return NULL;
}

char *my_strrchr(char *str, char c)
{
    char * result = NULL;

    for (; *str != '\0'; str++)
        if (*str == c)
            result = str;
    return result;
}
