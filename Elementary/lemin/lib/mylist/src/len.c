/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** Functions to measure the length of a list
*/

#include "mylist.h"

int mylist_len(list_t *list)
{
    int i = 0;

    while (list != NULL) {
        i++;
        list = list->next;
    }
    return (i);
}
