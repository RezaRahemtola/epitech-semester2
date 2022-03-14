/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to perferm mathematical operations
*/

int my_sqrt(int nb)
{
    int result = 0;

    if (nb < 0)
        return (0);
    for (int i = 1; nb > 0; i += 2) {
        nb -= i;
        result++;
    }
    return (nb == 0) ? result : 0;
}

int my_pow(int nb, int p)
{
    if (p == 1)
        return (nb);
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    return (nb * my_pow(nb, p - 1));
}
