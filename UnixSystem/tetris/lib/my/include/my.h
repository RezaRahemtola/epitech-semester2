/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Header
*/

#ifndef LIBMY_H
    #define LIBMY_H
    #include <stdarg.h>
    #include "my_arrays.h"
    #include "my_numbers.h"
    #include "my_strings.h"

int my_getnbr(char const *str);

char *my_nb_to_str(unsigned int nb);

char *my_strstr(char const *str, char const *to_find);
char *int_to_base(unsigned long long int nb, char *base);

// printf
int my_printf(const char *format, ...);
char *my_stringf(const char *format, ...);
void upper_s_flag(char *str);
void hash_formatting(va_list args, char **str_ptr);
void l_ll_formatting(va_list args, char **str_ptr);

char **my_strsplit(char *str, char delim);

#endif /* !LIBMY_H */
