/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Function to replace a given pattern in a string by another
*/

#include "my.h"

static int get_replaced_len(char *src, const char *old, const char *new)
{
    int replaced_len = 1;
    int old_len = my_strlen(old);
    int new_len = my_strlen(new);

    while (src[0] != '\0') {
        if (my_strncmp(src, old, old_len) == 0) {
            src += old_len;
            replaced_len += new_len;
        } else {
            src++;
            replaced_len++;
        }
    }
    return (replaced_len);
}

char *my_streplace(char *src, const char *old, char *new_p)
{
    char *str = my_str_allocfill(get_replaced_len(src, old, new_p), '\0');
    int old_len = my_strlen(old);

    while (src[0] != '\0') {
        if (my_strncmp(src, old, old_len) == 0) {
            src += old_len;
            my_strcat(str, new_p, false);
        } else {
            str[my_strlen(str)] = src[0];
            src++;
        }
    }
    return (str);
}
