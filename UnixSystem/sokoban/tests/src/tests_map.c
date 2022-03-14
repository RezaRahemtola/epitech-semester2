/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Tests end checks
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(map_has_size_for_window, win_low_rows)
{
    bool result = true;
    char **map = load_map_from_file("tests/samples/endgame_true");

    result = map_has_size_for_window(map, 100, 1);
    my_free_2d_array(map);
    cr_assert(!result);
}

Test(map_has_size_for_window, win_low_cols)
{
    bool result = true;
    char **map = load_map_from_file("tests/samples/endgame_true");

    result = map_has_size_for_window(map, 1, 100);
    my_free_2d_array(map);
    cr_assert(!result);
}

Test(map_has_size_for_window, win_ok)
{
    bool result = false;
    char **map = load_map_from_file("tests/samples/endgame_true");

    result = map_has_size_for_window(map, 100, 100);
    my_free_2d_array(map);
    cr_assert(result);
}
