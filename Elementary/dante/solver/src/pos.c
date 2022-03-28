/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Functions to play with list positions
*/

#include <stdlib.h>
#include "solver.h"

pos_t *get_last_pos(list_t *pos_list)
{
    pos_t *pos = NULL;

    if (pos_list == NULL)
        return (NULL);
    while (pos_list->next != NULL)
        pos_list = pos_list->next;
    pos = pos_list->data;
    return (pos);
}

void remove_last_pos(list_t **pos_list)
{
    list_t *list = *pos_list;
    list_t *tmp = NULL;

    if (list == NULL || list->next == NULL)
        return;
    while (list->next->next != NULL)
        list = list->next;
    tmp = list->next;
    list->next = NULL;
    obj_destroy(tmp, true, &free);
}
