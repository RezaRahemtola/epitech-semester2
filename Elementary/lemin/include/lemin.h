/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Header
*/

#pragma once

#include "mylist.h"

// Core
typedef struct room_s {
    char *name;
    int x;
    int y;
    list_t *tunnels;
} room_t;

typedef struct lemin_s {
    int nb_ants;
    room_t *start;
    room_t *end;
    list_t *rooms;
} lemin_t;

int lemin(int argc, char **argv);

// Rooms
void link_rooms(room_t *room, room_t *room2);
room_t *get_room_from_name(list_t *rooms, char *name);
