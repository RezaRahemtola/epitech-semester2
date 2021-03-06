/*
** EPITECH PROJECT, 2022
** MYLIB
** File description:
** str to word array
*/

#include <stdlib.h>
#include "my_strings.h"

char **my_strsplit(char *str, char delim)
{
    int nb_words = my_strcount(str, (char [2]){delim, '\0'}) + 1;
    int nb_chars = 0;
    char **array = malloc(sizeof(char *) * (nb_words + 1));

    for (int i = 0; i < nb_words; i++) {
        while (str[nb_chars] != delim && str[nb_chars] != '\0')
            nb_chars++;
        array[i] = my_str_allocfill(sizeof(char) * (nb_chars + 1), '\0');
        my_strncpy(array[i], str, nb_chars);
        str += nb_chars + 1;
        nb_chars = 0;
    }
    array[nb_words] = NULL;
    return (array);
}

static int count_words(const char *str)
{
    int is_last_space = 1;
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_last_space == 1 && str[i] != ' ' && str[i] != '\t')
            words++;
        is_last_space = (str[i] == ' ' || str[i] == '\t') ? (1) : (0);
    }
    return (words);
}

char **str_to_word_array(char *str)
{
    int nb_words = count_words(str);
    int nb_chars = 0;
    char **array = NULL;

    if (nb_words == 0)
        return (NULL);
    array = malloc(sizeof(char *) * (nb_words + 1));
    for (int i = 0; i < nb_words; i++) {
        while (my_charinstr(str[nb_chars], " \t") && str[nb_chars] != '\0')
            str++;
        while (!my_charinstr(str[nb_chars], " \t") && str[nb_chars] != '\0')
            nb_chars++;
        array[i] = my_str_allocfill(sizeof(char) * (nb_chars + 1), '\0');
        my_strncpy(array[i], str, nb_chars);
        str += nb_chars;
        nb_chars = 0;
    }
    array[nb_words] = NULL;
    return (array);
}
