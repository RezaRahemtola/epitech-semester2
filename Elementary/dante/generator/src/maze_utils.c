/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Maze utils
*/

#include "generator.h"

bool is_valid_cell(pos_t const position, maze_t *maze)
{
    bool is_x_valid = 0 <= position[X] && position[X] <= maze->width - 1;
    bool is_y_valid = 0 <= position[Y] && position[Y] <= maze->height - 1;

    return is_x_valid && is_y_valid;
}

bool is_uncarved_cell(pos_t const position, maze_t *maze)
{
    return maze->grid[position[Y]][position[X]] == WALL;
}

bool is_solution_rounded(maze_t *maze)
{
    if (maze->height < 3 || maze->width < 3)
        return false;
    return maze->grid[maze->height - 2][maze->width - 1] == WALL &&
           maze->grid[maze->height - 1][maze->width - 2] == WALL;
}
