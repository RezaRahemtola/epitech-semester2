/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Functions to parse tunnels
*/

#include "parsing.h"
#include "my.h"

static bool acquire_tunnel(lemin_t *lemin, char ***lines, char **tunnels)
{
    room_t *room1 = NULL;
    room_t *room2 = NULL;
    char **elems = my_strsplit((*lines)[0], '-');

    if (my_arraylen(elems) != 2) {
        my_free_2d_array(elems);
        return (false);
    }
    room1 = get_room_from_name(lemin->rooms, elems[0]);
    room2 = get_room_from_name(lemin->rooms, elems[1]);
    if (room1 == NULL || room2 == NULL) {
        my_free_2d_array(elems);
        return (false);
    }
    *tunnels = my_newstrcat(*tunnels, (*lines)[0], true, false);
    *tunnels = my_newstrcat(*tunnels, "\n", true, false);
    remove_first_line(lines);
    link_rooms(room1, room2);
    my_free_2d_array(elems);
    return (true);
}

char *acquire_tunnels(lemin_t *lemin, char ***lines)
{
    char *tunnels = NULL;
    bool is_valid = true;

    while (is_valid) {
        if (*lines == NULL || (*lines)[0] == NULL)
            break;
        is_valid = acquire_tunnel(lemin, lines, &tunnels);
    }
    return (tunnels);
}
