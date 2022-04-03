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
int my_array_biggest_len(char **array);

// Memory
char **my_malloc_2d_array(int nb_rows, int nb_cols);
char **my_array_allocfill(int nb_rows, int nb_cols, char c);
void my_free_2d_array(char **array);

// Copy
char **my_arraydup(char **array);

#endif /* !LIBMY_ARRAYS_H */
