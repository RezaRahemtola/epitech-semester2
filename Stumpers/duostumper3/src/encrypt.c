/*
** EPITECH PROJECT, 2022
** stupmper3
** File description:
** decroypt ceasar
*/

#include <stdlib.h>
#include "my_strings.h"

static char check_overflow(char new_char, int key, char min, char origin)
{
    if (key < 0)
        key = 26 + key;
    new_char = min + ((origin - min) + key) % 26;
    return new_char;
}

static char get_char_from_key(char c, int key)
{
    char new_char = c + key;

    if (!my_char_isalpha(c))
        return c;
    if (c >= 'A' && c <= 'Z')
        new_char = check_overflow(new_char, key, 'A', c);
    else
        new_char = check_overflow(new_char, key, 'a', c);
    return new_char;
}

char *shift_string(char *str, int key)
{
    int len = my_strlen(str);
    char *buffer = malloc(sizeof(char) * (len + 1));

    if (buffer == NULL)
        return NULL;
    for (int i = 0; i <= len; ++i)
        buffer[i] = get_char_from_key(str[i], key);
    return buffer;
}
