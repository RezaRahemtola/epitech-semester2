/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions related to the next tetrimino of the game
*/

#include <stdlib.h>
#include "game.h"

static WINDOW *get_next_win(int width, int height, int pos_x)
{
    static WINDOW *next_win = NULL;

    if (next_win == NULL)
        next_win = newwin(height + 2, width + 2, 1, pos_x);
    return (next_win);
}

pos_t *get_nextwin_size(list_t *tetriminos)
{
    pos_t *size = malloc(sizeof(pos_t));
    tetriminos_t *tetri = NULL;

    size->x = 0;
    size->y = 0;
    while (tetriminos->next != NULL) {
        tetri = tetriminos->data;
        size->x = (tetri->width > size->x) ? tetri->width : size->x;
        size->y = (tetri->height > size->y) ? tetri->height : size->y;
        tetriminos = tetriminos->next;
    }
    return (size);
}

void display_next(game_t *game)
{
    pos_t *size = get_nextwin_size(game->tetriminos);
    int pos_x = game->param->map_cols + 25;
    WINDOW *nextscr = get_next_win(size->x, size->y, pos_x);
    char **piece = game->next->piece;
    int color = game->next->color + '0';

    wclear(nextscr);
    box(nextscr, 0, 0);
    for (int i = 0; piece[i] != NULL; i++)
        for (int j = 0; piece[i][j] != '\0'; j++)
            mvwaddch(nextscr, i + 1, j + 1, piece[i][j] | COLOR_PAIR(color));
    wrefresh(nextscr);
    free(size);
}
