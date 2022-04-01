/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to check if a string match a type of char
*/

#include <stdbool.h>

bool my_char_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (true);
    return (false);
}
