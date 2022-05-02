/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strcmp function
*/

#include "my_string.h"

static int check_size(char const *str, int size, int n)
{
    char result = 0;

    if (size <= n)
        result = str[size];
    return (result);
}

int my_strcmp(char const *s1, char const *s2)
{
    int size = my_strlen(s1);
    int size2 = my_strlen(s2);
    int result = 0;

    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && result == 0; i++) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
        }
    }
    if (result == 0 && size > size2) {
        result = check_size(s1, size2, size);
    } else if (result == 0 && size < size2) {
        result = check_size(s2, size, size) * -1;
    }
    return (result);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;

    for (int i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i] && result == 0) {
            result = s1[i] - s2[i];
        }
    }
    if (result == 0 ){
        result = check_size(s1, my_strlen(s2), n);
    }
    return (result);
}
