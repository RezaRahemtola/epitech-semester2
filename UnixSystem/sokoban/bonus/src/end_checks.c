/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Functions to check for game end
*/

#include <ncurses.h>
#include "sokoban.h"

bool all_boxes_on_storage(char **map, char **base)
{
    char current = '\0';
    bool in_pos = true;

    for (int i = 0; base[i] != NULL; i++) {
        for (int j = 0; base[i][j] != '\0'; j++) {
            current = map[i][j];
            in_pos = (base[i][j] == 'O' && current != 'X') ? false : in_pos;
        }
    }
    return (in_pos);
}

static char *get_wall_str(char **map, int row, int col)
{
    char *walls = my_str_allocfill(sizeof(char) * 6, '\0');
    char up = map[row - 1][col];
    char right = map[row][col + 1];
    char down = map[row + 1][col];
    char left = map[row][col - 1];

    walls[0] = (up == '#' || up == 'X') ? 'W' : ' ';
    walls[1] = (right == '#' || right == 'X') ? 'W' : ' ';
    walls[2] = (down == '#' || down == 'X') ? 'W' : ' ';
    walls[3] = (left == '#' || left == 'X') ? 'W' : ' ';
    walls[4] = (up == '#' || up == 'X') ? 'W' : ' ';
    return (walls);
}

static bool is_box_stuck(char **map, int row, int col)
{
    char *walls = NULL;
    bool result = false;

    if (map[row][col] != 'X')
        return (false);
    walls = get_wall_str(map, row, col);
    if (my_strcount(walls, "WW") > 0)
        result = true;
    free(walls);
    return (result);
}

static bool all_boxes_stuck(char **map)
{
    int nb_boxes = 0;
    int nb_stuck = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            nb_boxes += (map[i][j] == 'X') ? 1 : 0;
            nb_stuck += (is_box_stuck(map, i, j)) ? 1 : 0;
        }
    }
    return (nb_boxes == nb_stuck);
}

bool is_endgame(char **map, char **base)
{
    if (all_boxes_on_storage(map, base))
        return (true);
    if (all_boxes_stuck(map))
        return (true);
    return (false);
}
