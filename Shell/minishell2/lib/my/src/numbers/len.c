/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to measure numbers length
*/

int my_nbrlen(int nb)
{
    int len = 1;

    while (nb > 9) {
        len++;
        nb /= 10;
    }
    return (len);
}
