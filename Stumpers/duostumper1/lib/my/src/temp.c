/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** Task07
*/

#include "my.h"

char *my_nb_to_str(unsigned int nb)
{
    int nbrlen = my_nbrlen(nb);
    char *str = my_str_allocfill(sizeof(char) * nbrlen, '\0');

    if (nb == 0) {
        str[0] = '0';
        return (str);
    }
    for (int i = 0; nb > 0; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    return (my_revstr(str));
}
