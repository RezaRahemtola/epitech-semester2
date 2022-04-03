/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions to handle tetri preview
*/

#include "game.h"

static void display_preview_line(tetriminos_t *tetri, int row, WINDOW *scr)
{
    char **piece = tetri->piece;

    for (int j = 0; piece[row][j] != '\0'; j++) {
        if (piece[row][j] == '*')
            mvwaddch(scr, tetri->pos->y + row + 1, tetri->pos->x + j + 1,
piece[row][j] | COLOR_PAIR(1));
    }
}

void display_preview(game_t *game, WINDOW *scr)
{
    tetriminos_t *preview = dup_tetrimino(game->tetri);

    while (make_piece_move(preview, game->map, DOWN, true));
    init_pair(1, preview->color, preview->color);
    for (int i = 0; preview->piece[i] != NULL; i++)
        display_preview_line(preview, i, scr);
    free_tetrimino(preview);
}
