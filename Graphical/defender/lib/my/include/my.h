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

char *my_nb_to_str(unsigned int nb);

char **my_strsplit(char *str, char delim);

#endif /* !LIBMY_H */
