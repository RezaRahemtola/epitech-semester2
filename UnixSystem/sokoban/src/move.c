/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Functions to move map elements
*/

#include <ncurses.h>
#include "sokoban.h"

static coords_t *get_next_coords(int key, int row, int col, int max_row)
{
    coords_t *coords = malloc(sizeof(coords_t));

    coords->row = row;
    coords->col = col;
    if (key == KEY_RIGHT)
        coords->col = col + 1;
    if (key == KEY_LEFT)
        coords->col = col - 1;
    if (key == KEY_UP)
        coords->row = row - 1;
    if (key == KEY_DOWN)
        coords->row = row + 1;
    coords->row = (coords->row < 0) ? 0 : coords->row;
    coords->row = (coords->row > max_row) ? max_row : coords->row;
    return (coords);
}

static bool is_available_space(char c)
{
    return (c == ' ' || c == 'O');
}

static void move_box(char **map, coords_t *box, int key)
{
    coords_t *next = NULL;

    if (map[box->row][box->col] != 'X')
        return;
    next = get_next_coords(key, box->row, box->col, my_arraylen(map) - 1);
    if (is_available_space(map[next->row][next->col])) {
        map[box->row][box->col] = ' ';
        map[next->row][next->col] = 'X';
    }
    free(next);
}

void move_player(char **map, int k)
{
    int row = 0;
    int col = 0;
    coords_t *next = NULL;

    if (k != KEY_RIGHT && k != KEY_LEFT && k != KEY_UP && k != KEY_DOWN)
        return;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            row = (map[i][j] == 'P') ? i : row;
            col = (map[i][j] == 'P') ? j : col;
        }
    }
    next = get_next_coords(k, row, col, my_arraylen(map) - 1);
    move_box(map, next, k);
    if (is_available_space(map[next->row][next->col])) {
        map[row][col] = ' ';
        map[next->row][next->col] = 'P';
    }
    free(next);
}
