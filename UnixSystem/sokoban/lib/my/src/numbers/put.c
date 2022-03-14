/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to display numbers
*/

#include "my.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb *= -1;
    }
    if (nb <= 9) {
        my_putchar(nb + '0');
    } else {
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
}
