/*
** EPITECH PROJECT, 2022
** MYLIB
** File description:
** str to word array
*/

#include <stdlib.h>
#include "my.h"

static int count_splits(const char *str, char delim)
{
    int is_last_space = 1;
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_last_space == 1 && str[i] != delim)
            words++;
        is_last_space = (str[i] == delim) ? (1) : (0);
    }
    return (words);
}

char **my_strsplit(char *str, char delim)
{
    int nb_words = count_splits(str, delim);
    int nb_chars = 0;
    char **array = malloc(sizeof(char *) * (nb_words + 1));

    for (int i = 0; i < nb_words; i++) {
        while (str[nb_chars] != delim && str[nb_chars] != '\0')
            nb_chars++;
        array[i] = my_str_allocfill(sizeof(char) * (nb_chars + 1), '\0');
        my_strncpy(array[i], str, nb_chars);
        str += nb_chars;
        while (str[0] == delim)
            str++;
        nb_chars = 0;
    }
    array[nb_words] = NULL;
    return (array);
}
