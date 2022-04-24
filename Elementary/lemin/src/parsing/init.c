/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Functions to initialize and destroy elements
*/

#include <stdlib.h>
#include "lemin.h"
#include "mylist.h"
#include "my_strings.h"

room_t *init_room(char *name, int x, int y)
{
    room_t *result = malloc(sizeof(room_t));

    if (result == NULL)
        return (NULL);
    result->name = my_strdup(name);
    result->x = x;
    result->y = y;
    result->tunnels = NULL;
    return (result);
}

void destroy_room(void *room)
{
    room_t *tmp = room;

    if (room == NULL)
        return;
    free(tmp->name);
    mylist_destroy(tmp->tunnels, false, NULL);
    free(tmp);
}

lemin_t *init_lemin(void)
{
    lemin_t *result = malloc(sizeof(lemin_t));

    if (result == NULL)
        return (NULL);
    result->nb_ants = -1;
    result->start = NULL;
    result->end = NULL;
    result->rooms = NULL;
    return (result);
}

void destroy_lemin(lemin_t *lemin)
{
    if (lemin == NULL)
        return;
    mylist_destroy(lemin->rooms, true, &destroy_room);
    free(lemin);
}
