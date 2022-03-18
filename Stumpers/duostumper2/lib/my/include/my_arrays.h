/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Arrays.h
*/

#ifndef LIBMY_ARRAYS_H
    #define LIBMY_ARRAYS_H

// Len
int my_arraylen(char **array);

// Memory
char **my_malloc_2d_array(int nb_rows, int nb_cols);
void my_free_2d_array(char **array);

#endif /* !LIBMY_ARRAYS_H */
