/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Backtracker algorithm's home
*/

#include <stddef.h>
#include <stdlib.h>
#include "generator.h"

void get_new_position(pos_t const position, pos_t new_pos, dir_t direction)
{
    new_pos[X] = position[X];
    new_pos[Y] = position[Y];
    switch (direction) {
        case NORTH:
            new_pos[Y]--;
            break;
        case SOUTH:
            new_pos[Y]++;
            break;
        case EAST:
            new_pos[X]++;
            break;
        case WEST:
            new_pos[X]--;
            break;
        default:
            break;
    }
}

bool check_neighbours(pos_t const current, dir_t except_dir, maze_t *maze)
{
    pos_t checked_position;
    bool condition;

    for (dir_t direction = 0; direction < 4; ++direction) {
        get_new_position(current, checked_position, direction);
        condition = direction != except_dir;
        condition &= is_valid_cell(checked_position, maze);
        if (condition && !is_uncarved_cell(checked_position, maze))
            return false;
    }
    return true;
}

bool can_carve(pos_t position, maze_t *maze, dir_t from)
{
    if (!is_valid_cell(position, maze) || !is_uncarved_cell(position, maze))
        return false;
    return check_neighbours(position, from, maze);
}

void shuffle_directions(dir_t directions[4], dir_t opposite_directions[4])
{
    size_t new_index;
    dir_t cache;

    for (size_t index = 0; index < 3; ++index) {
        new_index = index + rand() / (RAND_MAX / (4 - index) + 1);
        cache = directions[new_index];
        directions[new_index] = directions[index];
        directions[index] = cache;
        cache = opposite_directions[new_index];
        opposite_directions[new_index] = opposite_directions[index];
        opposite_directions[index] = cache;
    }
}

void carve_from(pos_t position, maze_t *maze)
{
    pos_t new_position = {0, 0};
    dir_t directions[4] = {NORTH, SOUTH, EAST, WEST};
    dir_t opposite_directions[4] = {SOUTH, NORTH, WEST, EAST};

    shuffle_directions(directions, opposite_directions);
    for (size_t i = 0; i < 4; i++) {
        get_new_position(position, new_position, directions[i]);
        if (can_carve(new_position, maze, opposite_directions[i])) {
            maze->grid[new_position[Y]][new_position[X]] = PATH;
            carve_from(new_position, maze);
        }
    }
}
