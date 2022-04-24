/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** Parsing header
*/

#pragma once

#include "lemin.h"

// Core
lemin_t *parsing(void);

// Initining and destroying
room_t *init_room(char *name, int x, int y);
void destroy_room(void *room);
lemin_t *init_lemin(void);
void destroy_lemin(lemin_t *lemin);

// Acquisition
void acquire_rooms(lemin_t *lemin, char ***lines);
char *acquire_tunnels(lemin_t *lemin, char ***lines);

// Utils
void display_parsing(lemin_t *lemin, char *tunnels_output);
void remove_first_line(char ***array);
void remove_comments(char **lines);
bool is_parsing_incomplete(lemin_t *lemin);
