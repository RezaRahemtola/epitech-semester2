/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** Memory allocation utilities
*/

#include <stdlib.h>
#include "my.h"

void *my_calloc(size_t element_count, size_t element_size)
{
    void *result = NULL;

    if (element_count == 0 || element_size == 0)
        return NULL;
    result = malloc(element_count * element_size);
    if (result == NULL)
        return NULL;
    my_memset(result, 0, element_count * element_size);
    return result;
}

void *my_reallocarray(void *pointer, size_t count,
    size_t old_count, size_t size)
{
    void *result = NULL;

    if (pointer == NULL)
        return my_calloc(count, size);
    if (count == 0)
        return free(pointer), NULL;
    result = my_calloc(count, size);
    if (result == NULL)
        return NULL;
    my_memcpy(result, pointer, old_count * size);
    free(pointer);
    return result;
}
