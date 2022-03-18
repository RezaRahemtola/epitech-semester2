/*
** EPITECH PROJECT, 2022
** duo stumper
** File description:
** Function for all the win checks
*/

#include <stddef.h>
#include "connect.h"
#include "my.h"

static bool check_horizontal(char **map, param_t *param, char player)
{
    int consecutive = 0;
    int row = 0;
    int col = 0;

    for (; map[row] != NULL && consecutive != 4; row++) {
        consecutive = 0;
        col = 0;
        for (; map[row][col] != '\0' && consecutive != 4; col++)
            consecutive = (map[row][col] == player) ? consecutive + 1 : 0;
    }
    if (consecutive == 4) {
        row--;
        col--;
        for (int i = col; i > col - 4; i--)
            map[row][i] = param->referee;
        return (true);
    }
    return (false);
}

static bool check_vertical(char **map, param_t *param, char player)
{
    int consecutive = 0;
    int row = 0;
    int col = 0;

    for (; map[row][col] != '\0' && consecutive != 4; col++) {
        consecutive = 0;
        row = 0;
        for (; map[row] != NULL && consecutive != 4; row++) {
            consecutive = (map[row][col] == player) ? consecutive + 1 : 0;
        }
        row--;
    }
    if (consecutive == 4) {
        col--;
        for (int i = row; i > row - 4; i--)
            map[i][col] = param->referee;
        return (true);
    }
    return (false);
}

static bool check_diagonal_line(char **map, param_t *param, char player)
{
    int consecutive = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; map[0][i] != '\0' && consecutive != 4; i++) {
        consecutive = 0;
        row = 0;
        col = i;
        while (row < param->height && col < param->width && consecutive != 4) {
            consecutive = (map[row][col] == player) ? consecutive + 1 : 0;
            row++;
            col++;
        }
    }
    if (consecutive == 4) {
        edit_map(map, row, col, param->referee);
        return (true);
    }
    return (false);
}

static bool check_diagonal_col(char **map, param_t *param, char player)
{
    int consecutive = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; map[i] != NULL && consecutive != 4; i++) {
        consecutive = 0;
        col = 0;
        row = i;
        while (row < param->height && col < param->width && consecutive != 4) {
            consecutive = (map[row][col] == player) ? consecutive + 1 : 0;
            row++;
            col++;
        }
    }
    if (consecutive == 4) {
        edit_map(map, row, col, param->referee);
        return (true);
    }
    return (false);
}

bool check_player_win(char **map, param_t *param, char player)
{
    bool result = false;

    result = check_horizontal(map, param, player);
    result = check_vertical(map, param, player) ? true : result;
    result = check_diagonal_line(map, param, player) ? true : result;
    result = check_diagonal_col(map, param, player) ? true : result;

    if (result) {
        display_map(map);
        my_printf("Congrats, player %c won!\n", player);
    }
    return (result);
}
