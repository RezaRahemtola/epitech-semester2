/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** Functions to add elements to a list
*/

#include <stddef.h>
#include <stdlib.h>
#include "mylist.h"

void mylist_append(void *data, list_t **dest)
{
    list_t *list = *dest;
    list_t *obj = malloc(sizeof(list_t));

    obj->data = data;
    obj->next = NULL;

    if (list == NULL) {
        *dest = obj;
        return;
    }
    while (list->next != NULL)
        list = list->next;
    list->next = obj;
}
