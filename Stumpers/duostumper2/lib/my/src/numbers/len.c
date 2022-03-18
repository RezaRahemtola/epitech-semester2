/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to measure numbers length
*/

int my_nbrlen(int nb)
{
    int len = 1;

    while (nb % 10 != 0) {
        nb -= (nb % 10);
        len++;
    }
    return (len);
}
