/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions for stringf (fork of printf to return a string)
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static char *check_flag(char **str_ptr, char *curr, va_list args)
{
    char *new = NULL;

    if (my_strncmp(*str_ptr, "%%", 2) == 0)
        new = my_newstrcat(curr, "%", true, false);
    if (my_strncmp(*str_ptr, "%s", 2) == 0)
        new = my_newstrcat(curr, va_arg(args, char *), true, false);
    if (my_strncmp(*str_ptr, "%d", 2) == 0)
        new = my_newstrcat(curr, my_nb_to_str(va_arg(args, int)), true, true);
    if (new != NULL) {
        (*str_ptr) += 2;
    } else {
        new = my_newstrcat(curr, (char [2]){(*str_ptr)[0], '\0'}, true, false);
        (*str_ptr)++;
    }
    return (new);
}

char *my_stringf(const char *format, ...)
{
    va_list args;
    char *result = my_str_allocfill(sizeof(char) * 2, '\0');
    char *str = my_strdup(format);
    char **str_ptr = &str;
    int len = my_strlen(str);

    va_start(args, format);
    while (my_strlen(str) > 0) {
        result = check_flag(&str, result, args);
    }
    va_end(args);
    (*str_ptr) -= len;
    free(str);
    return (result);
}
