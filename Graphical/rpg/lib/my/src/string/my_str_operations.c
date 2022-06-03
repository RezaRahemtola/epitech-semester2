/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** String operation functions
*/

#include "my_string.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int size = 0;

    for (size = 0; str[size] != '\0'; size++);
    return (size);
}

char *my_strdup(char const *str)
{
    int size = my_strlen(str);
    char *new = malloc(sizeof(char) * (size + 1));

    if (new == NULL) {
        return (NULL);
    }
    for (int i = 0; i < size; i++) {
        new[i] = str[i];
    }
    new[size] = '\0';
    return (new);
}

void my_strfill(char *array, int size, char def)
{
    for (int i = 0; i < size - 1; i++) {
        array[i] = def;
    }
    array[size - 1] = '\0';
}

char *my_strndup(char const *str, size_t n)
{
    char *result = malloc(sizeof(char) * (n + 1));

    if (result == NULL)
        return NULL;
    my_strncpy(result, str, n);
    result[n] = '\0';
    return result;
}
