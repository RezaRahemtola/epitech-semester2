/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Core game functions
*/

#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "score.h"
#include "my_arrays.h"
#include "mylist.h"

static game_t *init_game(param_t *param, list_t *list)
{
    game_t *game = malloc(sizeof(game_t));

    game->param = param;
    game->tetriminos = filter_tetriminos(list, param->map_cols,
    param->map_rows);
    game->tetri = get_random_tetri(game->tetriminos, param->map_cols);
    game->next = get_random_tetri(game->tetriminos, param->map_cols);
    game->map = my_array_allocfill(param->map_rows, param->map_cols, ' ');
    game->key = -1;
    game->scores = init_scores(param->level);
    game->timer = init_timer(CLOCKS_PER_SEC * 0.70);
    game->is_end = false;
    return (game);
}

static void destroy_game(game_t *game)
{
    mylist_destroy(game->tetriminos, true, &free_tetrimino);
    free_tetrimino(game->tetri);
    free_tetrimino(game->next);
    free(game->scores->timer);
    free(game->scores);
    free(game->timer);
    my_free_2d_array(game->map);
    free(game);
}

static void game_turn(game_t *game)
{
    if (is_time_elapsed(game->timer)) {
        display_map(game);
        display_next(game);
        display_scores(game);
        if (!make_piece_move(game->tetri, game->map, DOWN, true))
            get_new_tetrimino(game);
    }
}

static void init_colors(void)
{
    init_pair(' ', COLOR_WHITE, COLOR_BLACK);
    init_pair('0', 0, COLOR_BLACK);
    init_pair('1', 1, COLOR_BLACK);
    init_pair('2', 2, COLOR_BLACK);
    init_pair('3', 3, COLOR_BLACK);
    init_pair('4', 4, COLOR_BLACK);
    init_pair('5', 5, COLOR_BLACK);
    init_pair('6', 6, COLOR_BLACK);
    init_pair('7', 7, COLOR_BLACK);
}

void play(param_t *param, list_t *list)
{
    game_t *game = init_game(param, list);

    initscr();
    start_color();
    init_colors();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);
    curs_set(0);
    while (game->key != param->key_quit && !game->is_end) {
        game->is_end = handle_resize(game);
        game_turn(game);
        game->key = getch();
        handle_inputs(game);
        if (is_time_elapsed(game->scores->timer))
            display_scores(game);
    }
    print_result(game->scores->score, param->key_quit);
    endwin();
    destroy_game(game);
}
