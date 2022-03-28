/*
** EPITECH PROJECT, 2022
** dante solver
** File description:
** Tests error handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "solver.h"

Test(error_handling_solver, no_arg, .init=cr_redirect_stderr)
{
    int argc = 1;
    bool result = solver_has_errors(argc, (char *[2]){"./solver", NULL});

    cr_assert(result);
}

Test(error_handling_solver, number_args_ok)
{
    int argc = 2;
    bool result = solver_has_errors(argc, (char *[3]){"./solver", "arg", NULL});

    cr_assert(!result);
}

Test(error_handling_solver, not_file)
{
    char **map = load_map_from_file("arg");

    cr_assert(map == NULL);
}


Test(error_handling_solver, invalid_char)
{
    char **map = load_map_from_file("tests/samples/solver_invalid_char");
    bool result = solver_check_map(map);

    cr_assert(result);
}

Test(error_handling_solver, not_rectangular)
{
    char **map = load_map_from_file("tests/samples/solver_not_rectangular");
    bool result = solver_check_map(map);

    cr_assert(result);
}

Test(error_handling_solver, start_occupied)
{
    char **map = load_map_from_file("tests/samples/solver_start_occupied");
    bool result = solver_check_map(map);

    cr_assert(result);
}

Test(error_handling_solver, finish_occupied)
{
    char **map = load_map_from_file("tests/samples/solver_finish_occupied");
    bool result = solver_check_map(map);

    cr_assert(result);
}

Test(error_handling_solver, both_occupied)
{
    char **map = load_map_from_file("tests/samples/solver_both_occupied");
    bool result = solver_check_map(map);

    cr_assert(result);
}

Test(error_handling_solver, empty_file)
{
    char **map = load_map_from_file("tests/samples/empty_file");
    bool result = solver_check_map(map);

    cr_assert(result);
}
