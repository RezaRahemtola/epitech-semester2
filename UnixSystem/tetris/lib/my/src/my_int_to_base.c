/*
** EPITECH PROJECT, 2021
** my_int_to_base
** File description:
** Converts an int to a string number in a given base
*/

#include <stddef.h>
#include "my_strings.h"
#include "my_numbers.h"

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
