/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** Functions to destroy list elements
*/

#include <stdlib.h>
#include "mylist.h"

void obj_destroy(list_t *obj, bool free_data, void (*fptr)(void *data))
{
    if (free_data)
        (*fptr)(obj->data);
    free(obj);
}

void mylist_destroy(list_t *list, bool free_data, void (*fptr)(void *data))
{
    list_t *tmp = NULL;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        obj_destroy(tmp, free_data, fptr);
    }
}
