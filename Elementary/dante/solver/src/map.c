/*
** EPITECH PROJECT, 2022
** dante solver
** File description:
** Functions to interact with the map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"
#include "solver.h"

char **load_map_from_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer = NULL;
    char **map = NULL;

    if (fd == -1)
        return (NULL);
    if (stat(filepath, &sb) == -1)
        return (NULL);
    buffer = my_str_allocfill(sizeof(char) * (sb.st_size + 1), '\0');
    read(fd, buffer, sb.st_size);
    map = my_strsplit(buffer, '\n');
    free(buffer);
    close(fd);
    return (map);
}

maze_t *create_maze(char **map)
{
    maze_t *maze = malloc(sizeof(maze_t));
    int width = strlen(map[0]) - 1;
    int height = my_arraylen(map) - 1;

    maze->map = map;
    maze->height = height;
    maze->width = width;
    return (maze);
}

void display_solved_map(char **map, list_t *list)
{
    pos_t *pos = get_last_pos(list);

    map[pos->y][pos->x] = 'o';
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            map[i][j] = (map[i][j] == '-') ? '*' : map[i][j];
    for (int i = 0; map[i + 1] != NULL; i++) {
        write(1, map[i], my_strlen(map[i]));
        write(1, "\n", 1);
    }
    my_putstr(map[my_arraylen(map) - 1]);
}
