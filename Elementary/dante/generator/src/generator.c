/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generation module entrypoint
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generator.h"
#include "my_arrays.h"
#include "my_strings.h"

void free_maze(maze_t *maze)
{
    if (maze != NULL)
        my_free_2d_array(maze->grid);
    free(maze);
}

void print_maze(maze_t *maze)
{
    for (size_t i = 0; maze->grid[i] != NULL; ++i) {
        my_putstr(maze->grid[i]);
        if (maze->grid[i + 1] != NULL)
            my_putchar('\n');
    }
}

char **get_init_grid(int height, int width)
{
    char **grid = malloc(sizeof(char *) * (height + 1));

    if (grid == NULL)
        return NULL;
    for (int i = 0; i < height; ++i) {
        grid[i] = malloc(sizeof(char) * (width + 1));
        if (grid[i] == NULL) {
            my_free_2d_array(grid);
            return NULL;
        }
        memset(grid[i], WALL, sizeof(char) * width);
        grid[i][width] = '\0';
    }
    grid[height] = NULL;
    return grid;
}

maze_t *get_init_maze(char **grid, int height, int width)
{
    maze_t *result = malloc(sizeof(maze_t));

    if (result == NULL || grid == NULL)
        return NULL;
    result->height = height;
    result->width = width;
    result->grid = grid;

    return result;
}

maze_t *generate_maze(int height, int width, bool perfect)
{
    maze_t *maze = get_init_maze(get_init_grid(height, width), height, width);

    maze->grid[0][0] = PATH;
    srand((unsigned) time(NULL));
    carve_from((pos_t) {0, 0}, maze);
    if (!perfect)
        place_random_clusters(maze);
    if (is_solution_rounded(maze))
        bruteforce_finish(maze);
    else
        maze->grid[height - 1][width - 1] = PATH;
    return maze;
}
