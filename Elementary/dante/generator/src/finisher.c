/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Finish by bruteforce if the generator can't find a solution
*/

#include "generator.h"

void bruteforce_finish(maze_t *maze)
{
    pos_t current = {maze->height - 1, maze->width - 1};

    while (is_uncarved_cell(current, maze)) {
        maze->grid[current[Y]][current[X]] = PATH;
        current[Y]--;
    }
}
