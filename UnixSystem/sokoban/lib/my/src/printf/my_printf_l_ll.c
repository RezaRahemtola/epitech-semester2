/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** l and ll flags functions
*/

#include <stdarg.h>
#include "my.h"

static void l_formatting(va_list args, char **str_ptr, char next)
{
    if (next == 'd' || next == 'i' || next == 'u')
        my_putnbr(va_arg(args, long int));
    if (next == 'o')
        my_putstr(int_to_base(va_arg(args, long), "01234567"));
    if (next == 'x')
        my_putstr(int_to_base(va_arg(args, long), "0123456789abcdef"));
    if (next == 'X')
        my_putstr(int_to_base(va_arg(args, long), "0123456789ABCDEF"));
    (*str_ptr)++;
}

static void ll_formatting(va_list a, char **str_ptr, char next)
{
    if (next == 'd' || next == 'i' || next == 'u')
        my_putnbr(va_arg(a, long long int));
    if (next == 'o')
        my_putstr(int_to_base(va_arg(a, long long), "01234567"));
    if (next == 'x')
        my_putstr(int_to_base(va_arg(a, long long), "0123456789abcdef"));
    if (next == 'X')
        my_putstr(int_to_base(va_arg(a, long long), "0123456789ABCDEF"));
    (*str_ptr)++;
}

void l_ll_formatting(va_list args, char **str_ptr)
{
    char c = (*str_ptr)[0];

    if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X') {
        l_formatting(args, str_ptr, c);
    } else if (c == 'l') {
        (*str_ptr)++;
        ll_formatting(args, str_ptr, (*str_ptr)[0]);
    } else {
        my_putstr("%l");
    }
}
