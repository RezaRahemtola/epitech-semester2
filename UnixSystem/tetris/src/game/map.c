/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions to play with the map
*/

#include <ncurses.h>
#include <stdlib.h>
#include "game.h"
#include "my_strings.h"

void add_tetri_in_map(tetriminos_t *tetri, char **map)
{
    char tetri_char = ' ';
    char map_char = ' ';

    if (tetri == NULL)
        return;
    for (int i = 0; i < tetri->height; i++) {
        for (int j = 0; j < tetri->width; j++) {
            tetri_char = tetri->piece[i][j];
            map_char = map[tetri->pos->y + i][tetri->pos->x + j];
            map[tetri->pos->y + i][tetri->pos->x + j] = (tetri_char == '*') ?
tetri->color + '0' : map_char;
        }
    }
}

static WINDOW *get_map_win(int width, int height)
{
    static WINDOW *map_win = NULL;

    if (map_win == NULL)
        map_win = newwin(height + 2, width + 2, 1, 23);
    return (map_win);
}

static void switch_lines(char **map, int row, int width)
{
    char *tmp = map[row];

    if (my_strcount(map[row], " ") != width)
        return;
    for (int j = row; j > 0; j--)
        map[j] = map[j - 1];
    map[0] = tmp;
}

static void remove_full_lines(game_t *game)
{
    int height = game->param->map_rows;
    int width = game->param->map_cols;
    int nb_lines = 0;

    for (int i = 0; i < height; i++) {
        if (my_strcount(game->map[i], " ") == 0) {
            free(game->map[i]);
            game->map[i] = my_str_allocfill(width + 1, ' ');
            game->map[i][width] = '\0';
            nb_lines++;
        }
    }
    game->scores->lines += nb_lines;
    game->scores->score += SCORE_LINE * nb_lines;
    if (nb_lines >= 4)
        game->scores->score += SCORE_LINE * nb_lines;
    for (int i = 0; i < height; i++)
        switch_lines(game->map, i, width);
    update_level(game);
}

void display_map(game_t *game)
{
    WINDOW *mapscr = get_map_win(game->param->map_cols, game->param->map_rows);
    char c = ' ';

    wclear(mapscr);
    box(mapscr, 0, 0);
    remove_full_lines(game);
    for (int i = 0; i < game->param->map_rows; i++) {
        for (int j = 0; j < game->param->map_cols; j++) {
            c = (game->map[i][j] == ' ') ? ' ' : '*';
            mvwaddch(mapscr, i + 1, j + 1, c | COLOR_PAIR(game->map[i][j]));
        }
    }
    display_tetri(game->tetri, mapscr);
    display_preview(game, mapscr);
    wrefresh(mapscr);
}
