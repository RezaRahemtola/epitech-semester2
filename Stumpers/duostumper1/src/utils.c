/*
** EPITECH PROJECT, 2022
** duostumper1
** File description:
** main.c
*/

#include "my.h"

static char **concat_array_cols(char **arr1, char **arr2)
{
    int len = my_arraylen(arr1);
    char **result = malloc(sizeof(char *) * (len + 1));

    if (arr1 == NULL)
        return (arr2);
    if (arr2 == NULL)
        return (arr1);
    for (int i = 0; i < len; i++) {
        result[i] = my_newstrcat(arr1[i], arr2[i], false, false);
    }
    result[len] = NULL;
    return (result);
}

static char **concat_array_rows(char **arr1, char **arr2)
{
    int len = my_arraylen(arr1) + my_arraylen(arr2);
    int len_arr1 = my_arraylen(arr1);
    char **result = malloc(sizeof(char *) * (len + 1));

    if (arr1 == NULL)
        return (arr2);
    if (arr2 == NULL)
        return (arr1);
    for (int i = 0; arr1[i] != NULL; i++) {
        result[i] = my_strdup(arr1[i]);
    }
    for (int i = 0; arr2[i] != NULL; i++) {
        result[i + len_arr1] = my_strdup(arr2[i]);
    }
    result[len] = NULL;
    return (result);
}

static char **calc_line(char *pattern, char **precedent, char **points)
{
    char **result = NULL;

    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '#')
            result = concat_array_cols(result, precedent);
        if (pattern[i] == '.')
            result = concat_array_cols(result, points);
    }
    return (result);
}

char **calc_next(char **pattern, char **precedent, char **points)
{
    char **result = NULL;
    char **tmp = NULL;

    for (int i = 0; pattern[i] != NULL; i++) {
        tmp = calc_line(pattern[i], precedent, points);
        result = concat_array_rows(result, tmp);
    }
    my_free_2d_array(precedent);
    return (result);
}

char **new_points(char **actual, int len)
{
    char **line = NULL;
    char **result = NULL;

    for (int i = 0; i < len; i++) {
        line = concat_array_cols(line, actual);
    }
    for (int i = 0; i < len; i++) {
        result = concat_array_rows(result, line);
    }
    my_free_2d_array(actual);
    return (result);
}
