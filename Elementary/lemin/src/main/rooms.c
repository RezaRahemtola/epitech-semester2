/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Rooms management
*/

#include "lemin.h"
#include "mylist.h"
#include "my_strings.h"

void link_rooms(room_t *room, room_t *room2)
{
    if (room == room2)
        return;
    mylist_append(room2, &room->tunnels);
    mylist_append(room, &room2->tunnels);
}

room_t *get_room_from_name(list_t *rooms, char *name)
{
    room_t *room = NULL;

    while (rooms != NULL) {
        room = rooms->data;
        if (my_strcmp(room->name, name) == 0)
            return (room);
        rooms = rooms->next;
    }
    return (NULL);
}
