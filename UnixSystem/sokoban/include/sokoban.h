/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Header
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H
    #include <stdbool.h>
    #include "my.h"

typedef struct coords_s {
    int row;
    int col;
} coords_t;

// Error handling
bool check_errors(int argc, char **argv);

// Map
bool map_has_size_for_window(char **map, int x, int y);
char **load_map_from_file(char *filepath);

// Game
bool sokoban(char **map, char **base);
void move_player(char **map, int key);

// Checks
bool is_endgame(char **map, char **base);
bool all_boxes_on_storage(char **map, char **base);

#endif /* !SOKOBAN_H */
