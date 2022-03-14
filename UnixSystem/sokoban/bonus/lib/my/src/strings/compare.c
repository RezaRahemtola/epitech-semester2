/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** Functions to compare strings
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    if (s1 == NULL)
        return (-s2[0]);
    else if (s2 == NULL)
        return (s1[0]);
    while (s1[i] != '\0') {
        if (s2[i] == '\0')
            return (s1[i]);
        if (s2[i] != s1[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    if (s1 == NULL)
        return (-s2[0]);
    else if (s2 == NULL)
        return (s1[0]);
    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (i < n) ? (s1[i] - s2[i]) : (0);
}

int my_strcount(const char *str, const char *pattern)
{
    int count = 0;
    int len_pattern = my_strlen(pattern);

    if (str == NULL || pattern == NULL)
        return (0);
    while (str[0] != '\0') {
        if (my_strncmp(str, pattern, len_pattern) == 0) {
            str += len_pattern;
            count++;
        } else {
            str++;
        }
    }
    return (count);
}
