/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** Memory manipulation utilities
*/

#include <stdint-gcc.h>
#include <stddef.h>

void my_memset(void *pointer, int value, size_t size)
{
    uint8_t *workable_pointer = (uint8_t *) pointer;

    for (size_t i = 0; i < size; i++)
        workable_pointer[i] = (uint8_t) value;
}

void my_memcpy(void *dest, const void *src, size_t size)
{
    uint8_t *workable_dest = (uint8_t *) dest;
    uint8_t *workable_src = (uint8_t *) src;

    for (size_t i = 0; i < size; i++)
        workable_dest[i] = workable_src[i];
}
