/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions to handle pieces falling
*/

#include "game.h"
#include "my_arrays.h"
#include "my_strings.h"

static bool check_move_left(tetriminos_t *tetri, pos_t pos, char **map)
{
    int map_x = tetri->pos->x + pos.x;
    int map_y = tetri->pos->y + pos.y;

    if (pos.x - 1 >= 0)
        if (tetri->piece[pos.y][pos.x - 1] == '*')
            return (true);
    if (map_x - 1 < 0)
        return (false);
    if (map[map_y][map_x - 1] != ' ')
        return (false);
    return (true);
}

static bool check_move_right(tetriminos_t *tetri, pos_t pos, char **map)
{
    int map_width = my_strlen(map[0]);
    int map_x = tetri->pos->x + pos.x;
    int map_y = tetri->pos->y + pos.y;

    if (pos.x + 1 < tetri->width)
        if (tetri->piece[pos.y][pos.x + 1] == '*')
            return (true);
    if (map_x + 1 >= map_width)
        return (false);
    if (map[map_y][map_x + 1] != ' ')
        return (false);
    return (true);
}

static bool check_move_down(tetriminos_t *tetri, pos_t pos, char **map)
{
    int map_height = my_arraylen(map);
    int map_x = tetri->pos->x + pos.x;
    int map_y = tetri->pos->y + pos.y;

    if (tetri->piece[pos.y][pos.x] == ' ')
        return (true);
    if (pos.y + 1 < tetri->height)
        if (tetri->piece[pos.y + 1][pos.x] == '*')
            return (true);
    if (map_y + 1 >= map_height)
        return (false);
    if (map[map_y + 1][map_x] != ' ')
        return (false);
    return (true);
}

static bool can_char_move(tetriminos_t *tetri, pos_t pos, char **map, int dir)
{
    if (dir == LEFT)
        return (check_move_left(tetri, pos, map));
    if (dir == RIGHT)
        return (check_move_right(tetri, pos, map));
    if (dir == DOWN)
        return (check_move_down(tetri, pos, map));
    return (false);
}

bool make_piece_move(tetriminos_t *tetri, char **map, int dir, bool check_next)
{
    bool can_move = true;

    if (tetri == NULL)
        return (false);
    for (int y = 0; tetri->piece[y] != NULL && can_move; y++)
        for (int x = 0; tetri->piece[y][x] != '\0' && can_move; x++)
            can_move = can_char_move(tetri, (pos_t){x, y}, map, dir);
    if (dir == LEFT && can_move)
        tetri->pos->x--;
    if (dir == RIGHT && can_move)
        tetri->pos->x++;
    if (dir == DOWN && can_move && check_next) {
        tetri->pos->y++;
        can_move = make_piece_move(tetri, map, DOWN, false);
    }
    return (can_move);
}
