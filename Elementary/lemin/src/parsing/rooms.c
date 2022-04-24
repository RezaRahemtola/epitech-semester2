/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Functions to parse rooms
*/

#include "parsing.h"
#include "my.h"

static bool is_special_room(char *line, bool *is_start, bool *is_end)
{
    if (my_strcmp(line, "##start") == 0)
        *is_start = true;
    if (my_strcmp(line, "##end") == 0)
        *is_end = true;
    return (*is_start || *is_end);
}

static bool add_room(lemin_t *lemin, room_t *room, bool is_start, bool is_end)
{
    if ((is_start && lemin->start != NULL) || (is_end && lemin->end != NULL)) {
        destroy_room(room);
        return (false);
    }
    mylist_append(room, &lemin->rooms);
    if (!is_start && !is_end)
        return (true);
    if (is_start)
        lemin->start = room;
    else if (is_end)
        lemin->end = room;
    return (true);
}

static room_t *get_room_from_line(char *line)
{
    char **elems = my_strsplit(line, ' ');
    bool is_valid = true;
    room_t *room = NULL;

    if (my_arraylen(elems) != 3)
        is_valid = false;
    if (is_valid && (!my_str_isnum(elems[1]) || !my_str_isnum(elems[2])))
        is_valid = false;
    if (is_valid)
        room = init_room(elems[0], my_getnbr(elems[1]), my_getnbr(elems[2]));
    my_free_2d_array(elems);
    return (room);
}

static bool acquire_room(lemin_t *lemin, char ***lines)
{
    room_t *room = NULL;
    bool is_start = false;
    bool is_end = false;

    if (*lines == NULL || (*lines)[0] == NULL)
        return (false);
    if (is_special_room((*lines)[0], &is_start, &is_end))
        remove_first_line(lines);
    room = get_room_from_line((*lines)[0]);
    if (room == NULL)
        return (false);
    remove_first_line(lines);
    return (add_room(lemin, room, is_start, is_end));
}

void acquire_rooms(lemin_t *lemin, char ***lines)
{
    while (acquire_room(lemin, lines));
}
