/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Header file
*/

#ifndef TETRIS_H
    #define TETRIS_H
    #include <stdbool.h>
    #include "mylist.h"

// Positions
typedef struct pos_s {
    int x;
    int y;
} pos_t;

// Tetriminos
typedef struct tetriminos_s {
    char *name;
    char **piece;
    int width;
    int height;
    int color;
    bool has_error;
    pos_t *pos;
} tetriminos_t;

list_t *get_tetriminos(char *dirpath);
tetriminos_t *get_tetrimino(char *name, char *dirpath);
tetriminos_t *init_tetrimino(char *name);
tetriminos_t *dup_tetrimino(tetriminos_t *src);
tetriminos_t *get_random_tetri(list_t *list, int map_width);
list_t *filter_tetriminos(list_t *list, int width, int height);
void free_tetrimino(void *tetri);

// Params
typedef struct param_s {
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    int map_rows;
    int map_cols;
    bool with_next;
    bool debug;
    bool help;
} param_t;

param_t *init_param(void);
bool handle_options(int argc, char **argv, param_t *param);

// Debug
void disp_debug(param_t *param, list_t *tetriminos);

#endif /* !TETRIS_H */
