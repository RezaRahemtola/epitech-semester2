/*
** EPITECH PROJECT, 2022
** duo stumper 2
** File description:
** Core game functions
*/

#include <stddef.h>
#include "connect.h"
#include "my.h"

static bool is_win(char **map, param_t *param)
{
    if (check_player_win(map, param, param->player_one))
        return (true);
    if (check_player_win(map, param, param->player_two))
        return (true);
    return (false);
}

static bool is_endgame(char **map, param_t *param)
{
    if (is_win(map, param)) {
        return (true);
    }
    if (is_map_full(map)) {
        my_putstr("It's a tie, nobody wins.\n");
        return (true);
    }
    return (false);
}

void play(param_t *param)
{
    char **map = create_map(param->width, param->height);
    int turn = 1;
    int column = 0;
    char player = param->player_one;
    bool won = false;

    if (map == NULL)
        return;
    while (!is_endgame(map, param) && !won) {
        column = get_input(param, player, map);
        if (column == -1)
            break;
        place_piece(player, map, column);
        won = is_win(map, param);
        if (!won)
            display_map(map);
        turn *= -1;
        player = (turn == 1) ? param->player_one : param->player_two;
    }
    my_free_2d_array(map);
}
