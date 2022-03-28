/*
** EPITECH PROJECT, 2022
** dante solver
** File description:
** Main file
*/

#include <stddef.h>
#include "solver.h"
#include "my_arrays.h"

int main(int argc, char **argv)
{
    char **map = NULL;
    if (solver_has_errors(argc, argv))
        return (84);
    map = load_map_from_file(argv[1]);
    if (solver_check_map(map)) {
        my_free_2d_array(map);
        return (84);
    }
    solver(map);
    return (0);
}
