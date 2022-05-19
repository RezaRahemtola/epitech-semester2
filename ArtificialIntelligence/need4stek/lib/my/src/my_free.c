/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_free function
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

static void free_array(void **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
}

void my_free_arrays(int number, ...)
{
    va_list list;
    void **element;

    va_start(list, number);
    for (int i = 0; i < number; i++) {
        element = va_arg(list, void **);
        if (element != NULL) {
            free_array(element);
        }
        free(element);
    }
    va_end(list);
}
