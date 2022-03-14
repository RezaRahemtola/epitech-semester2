/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Functions to play with the map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

bool map_has_size_for_window(char **map, int x, int y)
{
    int map_x = 0;

    if (y < my_arraylen(map))
        return (false);
    for (int i = 0; map[i] != NULL; i++)
        map_x = (map_x < my_strlen(map[i])) ? my_strlen(map[i]) : map_x;
    if (x < map_x)
        return (false);
    return (true);
}

char **load_map_from_file(char *filepath)
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
