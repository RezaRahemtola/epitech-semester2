/*
** EPITECH PROJECT, 2021
** SoloStumper
** File description:
** Lib
*/

#include <stdlib.h>

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *new_str = NULL;
    int strlen = 0;

    while (src[strlen] != '\0')
        strlen++;
    new_str = malloc(sizeof(char) * (strlen + 1));
    my_strcpy(new_str, src);
    return (new_str);
}

char *my_malloc_str(size_t nb_char, char c)
{
    char *str = malloc(sizeof(char) * nb_char);

    if (str == NULL) return (NULL);
    for (size_t i = 0; i < nb_char; i++)
        str[i] = c;
    return (str);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s2[i] == '\0')
            return (s1[i]);
        if (s2[i] != s1[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int strlen = 0;

    while (src[n - 1] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (src[strlen] != '\0')
        strlen++;
    if (n > strlen)
        dest[i] = '\0';
    return (dest);
}
