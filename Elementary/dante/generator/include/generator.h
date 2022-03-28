/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generation module header file
*/

#ifndef GENERATOR_H
    #define GENERATOR_H

    #include <stdbool.h>

    #define X 0
    #define Y 1

    #define PATH '*'
    #define WALL 'X'
    #define CLUSTERS_PERCENTAGE 0.2

typedef enum direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
} dir_t;

typedef struct maze {
    char **grid;
    int height;
    int width;
} maze_t;

typedef int pos_t[2];

maze_t *generate_maze(int height, int width, bool perfect);
void free_maze(maze_t *maze);
bool check_args(int argc, char **argv);
void carve_from(pos_t position, maze_t *maze);
void print_maze(maze_t *maze);
bool is_valid_cell(pos_t const position, maze_t *maze);
bool is_uncarved_cell(pos_t const position, maze_t *maze);
void place_random_clusters(maze_t *maze);
bool is_solution_rounded(maze_t *maze);
void bruteforce_finish(maze_t *maze);

#endif /* !GENERATOR_H */
