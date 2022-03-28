/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Main file of the project's generation part
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "generator.h"

int main(int argc, char **argv)
{
    maze_t *maze;

    if (check_args(argc, argv)) {
        maze = generate_maze(atoi(argv[1]), atoi(argv[2]), argc == 4);
        if (maze == NULL) {
            fprintf(stderr, "Error: An unknown error has occurred.\n");
            return 84;
        } else {
            print_maze(maze);
            free_maze(maze);
        }
    } else {
        return 84;
    }
}
