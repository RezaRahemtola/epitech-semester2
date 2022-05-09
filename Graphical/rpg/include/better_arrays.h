/*
** EPITECH PROJECT, 2022
** BetterArrays Template Library
** File description:
** Library main header file
*/

// NEEDS `my-next` LIBRARY

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

#define barray(type)    \
    struct {            \
        size_t size;    \
        type *data;     \
    }
#define new_barray(type, size) my_calloc(size, sizeof(barray(type)))
#define destroy_barray(array)                                               \
    free(array->data);                                                      \
    free(array);
#define get_barray_size(array) array->size
#define get_barray_element_size(array) sizeof(*array->data)
#define get_barray_data(array, index) &array->data[index]
#define set_barray_data(array, index, value) array->data[index] = value
#define add_barray_element(array, value)                                    \
    ({                                                                      \
        array->data = my_reallocarray(array->data, array->size + 1,         \
        array->size, get_barray_element_size(array));                       \
        array->data[array->size++] = value;                                 \
    })
#define foreach_barray_element(array, element_name)                         \
    for (typeof(array->data) element_name = &array->data[0];                \
    element_name < &array->data[array->size]; element_name++)
#define find_barray_element(array, return_value, predicate)                 \
    ({                                                                      \
        foreach_barray_element(array, element)                              \
            if (predicate(element)) {                                       \
                return_value = element;                                     \
                break;                                                      \
            }                                                               \
    })
#define find_barray_element_cmp(array, return_value, comparator, compare)   \
    ({                                                                      \
        foreach_barray_element(array, element)                              \
            if (comparator(element, compare)) {                             \
                return_value = element;                                     \
                break;                                                      \
            }                                                               \
    })
