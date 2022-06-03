/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Linked list module header
*/

#pragma once

#include <stdbool.h>

typedef struct list {
    void *data;
    struct list *prev;
    struct list *next;
} list_t;

typedef bool (*equals_func)(void *obj1, void *obj2);
typedef void (*free_func)(void *obj);

void my_list_add(list_t **list, void *data);
