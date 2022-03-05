/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to check if numbers meet criteria
*/

#include "my.h"

bool my_nbr_isprime(int nb)
{
    if (nb <= 1)
        return (false);
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (false);
    }
    return (true);
}
