/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Arrays manipulation functions
*/

#include <stddef.h>

int my_arraylen(char * const *array)
{
    int size = 0;

    for (size = 0; array[size] != NULL; size++);
    return (size);
}
