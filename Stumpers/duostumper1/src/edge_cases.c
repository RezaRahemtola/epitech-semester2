/*
** EPITECH PROJECT, 2022
** duostumper1
** File description:
** Functions for fractal edge cases
*/

#include <stdbool.h>
#include "my.h"

static void fractal_zero(void)
{
    my_putstr("#\n");
}

static void fractal_one(char *pattern)
{
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '@')
            my_putchar('\n');
        else
            my_putchar(pattern[i]);
    }
    my_putchar('\n');
}

bool edge_cases(char *nb, char *pattern1, char *pattern2)
{
    int number = my_getnbr(nb);

    (void) pattern2;
    if (number == 0) {
        fractal_zero();
        return (true);
    }
    if (number == 1) {
        fractal_one(pattern1);
        return (true);
    }
    return (false);
}
