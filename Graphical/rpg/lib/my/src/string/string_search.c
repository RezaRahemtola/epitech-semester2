/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** String search utilities
*/

#include <stddef.h>

char *my_strchr(char *str, char c)
{
    for (; *str != '\0'; str++)
        if (*str == c)
            return str;
    return NULL;
}
