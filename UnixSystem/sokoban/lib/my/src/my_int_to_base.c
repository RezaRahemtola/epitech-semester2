/*
** EPITECH PROJECT, 2021
** my_int_to_base
** File description:
** Converts an int to a string number in a given base
*/

#include "my.h"

char *int_to_base(unsigned long long int nb, char *base)
{
    char *result = NULL;
    int len = 0;
    unsigned long long int tmp = nb;
    char test[2] = {'\0', '\0'};

    if (nb == 0) {
        test[0] = base[0];
        return (my_strdup(test));
    }
    for (int i = 1; tmp != 0; i++) {
        tmp /= my_strlen(base);
        len++;
    }
    result = my_str_allocfill(sizeof(char) * (len + 1), '\0');
    for (int i = 1; nb != 0; nb /= my_strlen(base), i++) {
        result[i - 1] = base[nb % my_strlen(base)];
    }
    return (my_revstr(result));
}

static int get_char_pos(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (i);
    }
    return (0);
}

int base_to_int(char *nb, char *base)
{
    int base_len = my_strlen(base);
    int nb_len = my_strlen(nb) - 1;
    int result = 0;

    for (int i = 0; nb[i] != '\0'; i++) {
        result += get_char_pos(nb[i], base) * my_pow(base_len, nb_len);
        nb_len--;
    }
    return (result);
}
