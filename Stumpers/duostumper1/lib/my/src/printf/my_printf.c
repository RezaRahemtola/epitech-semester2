/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Main file
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void get_flag(char **str_ptr, char *flag)
{
    if ((*str_ptr)[0] == '%' && my_strlen(*str_ptr) > 1) {
        flag[0] = (*str_ptr)[0];
        flag[1] = (*str_ptr)[1];
        (*str_ptr) += 2;
    } else {
        flag[0] = '\0';
    }
}

static void handle_flag2(char *flag, va_list args, char **str_ptr)
{
    if (my_strcmp(flag, "%S") == 0)
        upper_s_flag(va_arg(args, char *));
    if (my_strcmp(flag, "%#") == 0)
        hash_formatting(args, str_ptr);
    if (my_strcmp(flag, "%l") == 0)
        l_ll_formatting(args, str_ptr);
}

static void handle_flag(char *flag, va_list args, char **str_ptr)
{
    if (my_strcmp(flag, "%s") == 0)
        my_putstr(va_arg(args, char *));
    if (my_strcmp(flag, "%d") == 0 || my_strcmp(flag, "%i") == 0)
        my_putnbr(va_arg(args, int));
    if (my_strcmp(flag, "%u") == 0)
        my_putnbr(va_arg(args, int));
    if (my_strcmp(flag, "%%") == 0)
        my_putchar('%');
    if (my_strcmp(flag, "%c") == 0)
        my_putchar(va_arg(args, int));
    if (my_strcmp(flag, "%o") == 0)
        my_putstr(int_to_base(va_arg(args, int), "01234567"));
    if (my_strcmp(flag, "%x") == 0)
        my_putstr(int_to_base(va_arg(args, int), "0123456789abcdef"));
    if (my_strcmp(flag, "%X") == 0)
        my_putstr(int_to_base(va_arg(args, int), "0123456789ABCDEF"));
    if (my_strcmp(flag, "%b") == 0)
        my_putstr(int_to_base(va_arg(args, int), "01"));
    handle_flag2(flag, args, str_ptr);
}

int my_printf(const char *format, ...)
{
    va_list args;
    char flag[3] = "\0";
    char *str = my_strdup(format);
    int len = my_strlen(str);
    char **str_ptr = &str;

    va_start(args, format);
    while (my_strlen(str) > 0) {
        get_flag(str_ptr, flag);
        if (my_strlen(flag) == 2) {
            handle_flag(flag, args, str_ptr);
        } else {
            my_putchar((*str_ptr)[0]);
            (*str_ptr)++;
        }
    }
    va_end(args);
    (*str_ptr) -= len;
    free(str);
    return (0);
}
