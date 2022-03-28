/*
** EPITECH PROJECT, 2022
** dante solver
** File description:
** Core functions of the solver
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "solver.h"
#include "my_arrays.h"
#include "my_strings.h"

static void get_next(maze_t *maze, list_t *pos_list, char c)
{
    pos_t *next = malloc(sizeof(pos_t));
    pos_t *pos = get_last_pos(pos_list);

    *next = (pos_t){pos->x, pos->y};
    mylist_append(next, &pos_list);
    if (pos->y + 1 <= maze->height && maze->map[pos->y + 1][pos->x] == c) {
        next->y += 1;
        return;
    }
    if (pos->x + 1 <= maze->width && maze->map[pos->y][pos->x + 1] == c) {
        next->x += 1;
        return;
    }
    if (pos->y - 1 >= 0 && maze->map[pos->y - 1][pos->x] == c) {
        next->y -= 1;
        return;
    }
    if (pos->x - 1 >= 0 && maze->map[pos->y][pos->x - 1] == c)
        next->x -= 1;
}

static bool has_next(maze_t *maze, list_t *list, char c)
{
    pos_t *pos = get_last_pos(list);

    if (pos->y + 1 <= maze->height && maze->map[pos->y + 1][pos->x] == c)
        return true;
    if (pos->x + 1 <= maze->width && maze->map[pos->y][pos->x + 1] == c)
        return true;
    if (pos->y - 1 >= 0 && maze->map[pos->y - 1][pos->x] == c)
        return true;
    if (pos->x - 1 >= 0 && maze->map[pos->y][pos->x - 1] == c)
        return true;
    return false;
}

static bool is_on_finish(maze_t *maze, list_t *pos_list)
{
    pos_t *pos = get_last_pos(pos_list);

    return (pos->x == maze->width && pos->y == maze->height);
}

static bool move_back(maze_t *maze, list_t *list)
{
    pos_t *pos = get_last_pos(list);

    while (!is_on_finish(maze, list) && !has_next(maze, list, '*')) {
        if (!has_next(maze, list, 'o'))
            return (true);
        pos = get_last_pos(list);
        maze->map[pos->y][pos->x] = '-';
        remove_last_pos(&list);
    }
    return (false);
}

void solver(char **map)
{
    maze_t *maze = create_maze(map);
    pos_t *pos = malloc(sizeof(pos_t));
    list_t *list = NULL;
    bool stuck = false;

    *pos = (pos_t){0, 0};
    mylist_append(pos, &list);
    while (!is_on_finish(maze, list) && !stuck) {
        while (!is_on_finish(maze, list) && has_next(maze, list, '*')) {
            pos = get_last_pos(list);
            maze->map[pos->y][pos->x] = 'o';
            get_next(maze, list, '*');
        }
        stuck = move_back(maze, list);
    }
    if (!stuck)
        display_solved_map(maze->map, list);
    else
        my_putstr("no solution found");
    mylist_destroy(list, true, &free);
}
