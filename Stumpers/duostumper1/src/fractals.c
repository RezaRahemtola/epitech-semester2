/*
** EPITECH PROJECT, 2022
** duostumper1
** File description:
** main.c
*/

#include "my.h"
#include "fractals.h"

void fractals(int nb, char *pattern, char *arg_points)
{
    char **base = my_strsplit(pattern, '@');
    char **result = my_strsplit(pattern, '@');
    char **points = my_strsplit(arg_points, '@');

    for (int i = 0; i < nb - 1; i++) {
        result = calc_next(base, result, points);
        points = new_points(points, my_arraylen(base));
    }
    for (int i = 0; result[i] != NULL; i++)
        my_printf("%s\n", result[i]);
    my_free_2d_array(base);
    my_free_2d_array(result);
    my_free_2d_array(points);
}
