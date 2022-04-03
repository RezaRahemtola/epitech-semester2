/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Game functions header
*/

#pragma once

#include <ncurses.h>
#include "tetris.h"

#define SCORE_LINE 100
#define SCORE_LEVEL 200
#define SCORE_DROP 2

#define MAX(x, y) (((x) < (y)) ? (y) : (x))

typedef enum direction_s {
    LEFT,
    RIGHT,
    DOWN
} direction_t;

// Timer
typedef struct time_clock_s {
    float start;
    size_t delay;
    size_t elapsed;
} time_clock_t;

time_clock_t *init_timer(size_t delay);
bool is_time_elapsed(time_clock_t *timer);

// Scores
typedef struct scores_s {
    time_clock_t *timer;
    int level;
    int lines;
    int score;
    int high_score;
} scores_t;

scores_t *init_scores(int level);
char *get_timer_str(size_t time);

// Game
typedef struct game_s {
    param_t *param;
    list_t *tetriminos;
    tetriminos_t *tetri;
    tetriminos_t *next;
    scores_t *scores;
    char **map;
    int key;
    time_clock_t *timer;
    bool is_end;
} game_t;

// Core
void play(param_t *param, list_t *tetriminos);

// Tetri
void get_new_tetrimino(game_t *game);
void display_tetri(tetriminos_t *tetri, WINDOW *mapscr);
void add_tetri_in_map(tetriminos_t *tetri, char **map);

// Move
bool make_piece_move(tetriminos_t *tetri, char **map, int dir,
bool check_next);
void rotate_piece(tetriminos_t *tetri, param_t *param);

// Input
void handle_inputs(game_t *game);

// Display
void display_next(game_t *game);
pos_t *get_nextwin_size(list_t *tetriminos);
void display_map(game_t *game);
void display_scores(game_t *game);
void display_preview(game_t *game, WINDOW *scr);
void update_level(game_t *game);
WINDOW *get_scores_win(int width, int height);
bool handle_resize(game_t *game);
