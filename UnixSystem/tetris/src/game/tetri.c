/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions to handle tetrimino logic in the game
*/

#include <ncurses.h>
#include "game.h"

static bool is_tetri_stuck(game_t *game)
{
    char **piece = game->tetri->piece;
    char **map = game->map;
    pos_t *pos = game->tetri->pos;
    bool is_stuck = false;

    for (int i = 0; piece[i] != NULL && !is_stuck; i++) {
        for (int j = 0; piece[i][j] != '\0' && !is_stuck; j++) {
            is_stuck = (piece[i][j] == '*' &&
map[pos->y + i][pos->x + j] != ' ') ? true : is_stuck;
        }
    }
    return (is_stuck);
}

void get_new_tetrimino(game_t *game)
{
    add_tetri_in_map(game->tetri, game->map);
    free_tetrimino(game->tetri);
    game->tetri = game->next;
    game->is_end = is_tetri_stuck(game);
    game->next = get_random_tetri(game->tetriminos, game->param->map_cols);
}

static void display_tetri_line(tetriminos_t *tetri, WINDOW *mapscr, int i)
{
    int color = tetri->color + '0';

    for (int j = 0; j < tetri->width; j++) {
        if (tetri->piece[i][j] == '*')
            mvwaddch(mapscr, tetri->pos->y + i + 1, tetri->pos->x + j + 1,
tetri->piece[i][j] | COLOR_PAIR(color));
    }
}

void display_tetri(tetriminos_t *tetri, WINDOW *mapscr)
{
    for (int i = 0; i < tetri->height; i++) {
        display_tetri_line(tetri, mapscr, i);
    }
}
