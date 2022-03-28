/*
** EPITECH PROJECT, 2022
** dante solver
** File description:
** Header file
*/

#ifndef SOLVER_H
    #define SOLVER_H
    #include <stdbool.h>
    #include "mylist.h"

typedef struct maze_s {
    char **map;
    int height;
    int width;
} maze_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

// Error handling
bool solver_has_errors(int argc, char **argv);
bool solver_check_map(char **map);

// Map/maze
char **load_map_from_file(const char *filepath);
maze_t *create_maze(char **map);
void display_solved_map(char **map, list_t *list);

// Core functions
void solver(char **map);

// Pos
pos_t *get_last_pos(list_t *pos_list);
void remove_last_pos(list_t **pos_list);

#endif /* !SOLVER_H */
