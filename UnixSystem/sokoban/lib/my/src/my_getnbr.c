/*
** EPITECH PROJECT, 2021
** MY_GET_NBR
** File description:
** Task05
*/

#include "my.h"

static int check_consecutive_negative(int i, char const *str)
{
    int nb = 0;

    while (i >= 0 && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-') {
            nb++;
        }
        i--;
    }
    return (nb);
}

static bool check_negative(int i, char const *str, int negative)
{
    if (negative == 1) {
        return (true);
    } else if (check_consecutive_negative(i - 1, str) % 2 == 1) {
        return (true);
    } else {
        return (false);
    }
}

static bool is_min_or_max(unsigned int nb, int negative)
{
    unsigned int max = 2147483647;

    if (negative == 0 && nb > max) {
        return (true);
    } else if (negative == 1 && nb > (max + 1)) {
        return (true);
    }
    return (false);
}

int my_getnbr(char const *str)
{
    unsigned int result = 0;
    int nb_value = 0;
    bool nb_found = false;
    int negative = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb_value = str[i] - '0';
        if (nb_value >= 0 && nb_value <= 9) {
            nb_found = true;
            negative = check_negative(i, str, negative);
            result = (result * 10) + nb_value;
        }
        if (is_min_or_max(result, negative))
            return (0);
        if ((nb_value < 0 || nb_value > 9) && nb_found)
            break;
    }
    return (negative == 1) ? -result : result;
}
