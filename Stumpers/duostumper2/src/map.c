/*
** EPITECH PROJECT, 2022
** duo stumper 1
** File description:
** Functions to use the map
*/

#include <stdlib.h>
#include "my.h"

char **create_map(int width, int height)
{
    char **map = malloc(sizeof(char *) * (height + 1));

    if (map == NULL)
        return (NULL);
    for (int i = 0; i < height; i++) {
        map[i] = my_str_allocfill(sizeof(char) * (width + 1), '.');
        if (map[i] == NULL)
            return (NULL);
        map[i][width] = '\0';
    }
    map[height] = NULL;
    return (map);
}

void display_map(char **map)
{
    int border_len = my_strlen(map[0]) + 2;

    for (int i = 0; i < border_len; i++)
        my_putchar('+');
    my_putchar('\n');
    for (int i = 0; map[i] != NULL; i++)
        my_printf("|%s|\n", map[i]);
    for (int i = 0; i < border_len; i++)
        my_putchar('+');
    my_putchar('\n');
}

void place_piece(char piece, char **map, int column)
{
    int row = 0;
    int col = column - 1;

    for (; map[row] != NULL && map[row][col] == '.'; row++);
    row = (row == 0) ? 0 : row - 1;
    map[row][col] = piece;
}

bool is_map_full(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        if (my_charinstr('.', map[i]))
            return (false);
    return (true);
}
