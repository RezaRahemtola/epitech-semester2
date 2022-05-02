/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** String operation functions
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int size = 0;

    for (size = 0; str[size] != '\0'; size++);
    return (size);
}

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++) {
        str[i] = src[i];
    }
    str[size] = '\0';
    return (str);
}

void my_strfill(char *array, int size, char def)
{
    for (int i = 0; i < size - 1; i++) {
        array[i] = def;
    }
    array[size - 1] = '\0';
}
