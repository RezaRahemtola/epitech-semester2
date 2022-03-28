/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Functions to make an imperfect maze
*/

#include <stdlib.h>
#include "generator.h"

static void add_cluster(maze_t *maze)
{
    int mod_x = maze->width - 5;
    int mod_y = maze->height - 5;
    int x = rand() % ((mod_x <= 0) ? 1 : mod_x);
    int y = rand() % ((mod_y <= 0) ? 1 : mod_y);
    char *cluster[6] = {"*****", "*XXX*", "*X*X*", "*XXX*", "*****", NULL};

    for (int i = y; i < y + 5; i++)
        for (int j = x; j < x + 5; j++)
            maze->grid[i][j] = cluster[i - y][j - x];
}

void place_random_clusters(maze_t *maze)
{
    size_t size_in_clusters = (maze->width * maze->height) / 25;
    size_t clusters_nb = size_in_clusters * CLUSTERS_PERCENTAGE;

    if (maze->height < 5 || maze->width < 5)
        return;
    clusters_nb = (clusters_nb == 0) ? 1 : clusters_nb;
    for (size_t i = 0; i < clusters_nb; i++)
        add_cluster(maze);
}
