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
char *my_stringf(const char *format, ...);

char **my_strsplit(char *str, char delim);
char **str_to_word_array(char *str);

#endif /* !LIBMY_H */
