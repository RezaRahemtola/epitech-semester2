/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Tests error handling
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(error_handling, no_arg)
{
    int argc = 1;
    bool result = check_errors(argc, (char *[2]){"./my_sokoban", NULL});

    cr_assert(result);
}

Test(error_handling, invalid_chars)
{
    int argc = 2;
    char *map = "tests/samples/invalid_chars";
    bool result = check_errors(argc, (char *[3]){"./my_sokoban", map, NULL});

    cr_assert(result);
}

Test(error_handling, no_player)
{
    int argc = 2;
    char *map = "tests/samples/no_player";
    bool result = check_errors(argc, (char *[3]){"./my_sokoban", map, NULL});

    cr_assert(result);
}

Test(error_handling, inconsistent_box_storage)
{
    int argc = 2;
    char *map = "tests/samples/inconsistent_box_storage";
    bool result = check_errors(argc, (char *[3]){"./my_sokoban", map, NULL});

    cr_assert(result);
}

Test(error_handling, valid_map)
{
    int argc = 2;
    char *map = "tests/samples/valid_map";
    bool result = check_errors(argc, (char *[3]){"./my_sokoban", map, NULL});

    cr_assert(!result);
}
