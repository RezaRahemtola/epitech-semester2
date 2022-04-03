/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions to handle user input
*/

#include <stdlib.h>
#include "game.h"

static void handle_drop_input(game_t *game)
{
    if (game->key == game->param->key_drop) {
        if (!make_piece_move(game->tetri, game->map, DOWN, true))
            get_new_tetrimino(game);
        game->scores->score += SCORE_DROP;
        game->key = -1;
    }
}

static void handle_pause_input(game_t *game)
{
    int tmp = -1;

    if (game->key == game->param->key_pause) {
        while (tmp != game->param->key_pause)
            tmp = getch();
    }
}

void handle_inputs(game_t *game)
{
    if (game->key == -1)
        return;
    if (game->key == game->param->key_left) {
        make_piece_move(game->tetri, game->map, LEFT, false);
        game->key = -1;
    }
    if (game->key == game->param->key_right) {
        make_piece_move(game->tetri, game->map, RIGHT, false);
        game->key = -1;
    }
    if (game->key == game->param->key_turn) {
        rotate_piece(game->tetri, game->param);
        game->key = -1;
    }
    handle_drop_input(game);
    handle_pause_input(game);
    if (game->key == -1)
        display_map(game);
}

bool handle_resize(game_t *game)
{
    int key = -1;
    pos_t *next = get_nextwin_size(game->tetriminos);
    int size_x = game->param->map_cols + 2 + 22 + next->x + 2;
    int size_y = MAX(13, MAX(next->y, game->param->map_rows)) + 2;

    if (size_x < getmaxx(stdscr) && size_y < getmaxy(stdscr))
        return (false);
    clear();
    wprintw(stdscr, "Please enlarge your terminal\n");
    refresh();
    while (key != game->param->key_quit && (getmaxx(stdscr) <= size_x ||
    getmaxy(stdscr) <= size_y)) {
        key = getch();
    }
    free(next);
    clear();
    return (key == game->param->key_quit);
}
