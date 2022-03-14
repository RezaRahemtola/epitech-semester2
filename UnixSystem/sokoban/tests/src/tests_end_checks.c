/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Tests end checks
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(end_checks, end_true)
{
    bool result = false;
    char **map = load_map_from_file("tests/samples/endgame_true");
    char **base = load_map_from_file("tests/samples/valid_map");

    result = is_endgame(map, base);
    my_free_2d_array(map);
    my_free_2d_array(base);
    cr_assert(result);
}

Test(end_checks, end_false)
{
    bool result = true;
    char **map = load_map_from_file("tests/samples/endgame_false");
    char **base = load_map_from_file("tests/samples/valid_map");

    result = is_endgame(map, base);
    my_free_2d_array(map);
    my_free_2d_array(base);
    cr_assert(!result);
}

Test(end_checks, player_on_storage)
{
    bool result = true;
    char **map = load_map_from_file("tests/samples/endgame_player_on_storage");
    char **base = load_map_from_file("tests/samples/valid_map");

    result = is_endgame(map, base);
    my_free_2d_array(map);
    my_free_2d_array(base);
    cr_assert(!result);
}

Test(end_checks, box_stuck)
{
    bool result = false;
    char **map = load_map_from_file("tests/samples/endgame_box_stuck");
    char **base = load_map_from_file("tests/samples/valid_map");

    result = is_endgame(map, base);
    my_free_2d_array(map);
    my_free_2d_array(base);
    cr_assert(!result);
}
