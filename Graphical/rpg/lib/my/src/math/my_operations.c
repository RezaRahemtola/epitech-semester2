/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Math operations
*/

int my_llog(long lnbr, int x)
{
    int result = 0;

    if (lnbr < 1 || x < 1) {
        return (0);
    }
    for (int i = 0; lnbr >= x; i++) {
        result++;
        lnbr /= x;
    }
    return (result);
}
