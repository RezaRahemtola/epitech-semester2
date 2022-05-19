/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Functions header
*/

#pragma once

#include <stdbool.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))


int my_arraylen(char * const *array);

bool my_str_starts(char const *str, char const *pattern);
int my_strlen(char const *str);
char **my_strsplit(char const *, char);
char *my_substr(char const *, int, int);
char *my_substr_size(char const *, int, int, int);

void my_free_arrays(int size, ...);
