/*
** EPITECH PROJECT, 2022
** dante solver
** File description:
** Error handling
*/

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"
#include "solver.h"

static bool start_finish_occupied(char **map)
{
    int width = strlen(map[0]) - 1;
    int height = my_arraylen(map) - 1;

    if (map[0][0] != '*')
        return (true);
    if (map[height][width] != '*')
        return (true);
    return (false);
}

bool solver_check_map(char **map)
{
    bool invalid = false;
    int line_len = 0;

    if (map == NULL)
        return (true);
    line_len = my_strlen(map[0]);
    for (int i = 0; map[i] != NULL && !invalid; i++) {
        for (int j = 0; map[i][j] != '\0' && !invalid; j++)
            invalid = !my_charinstr(map[i][j], "X*\n") ? true : invalid;
    }
    for (int i = 0; map[i] != NULL && !invalid; i++) {
        if (i > 0 && my_strlen(map[i]) != line_len)
            invalid = true;
        line_len = my_strlen(map[i]);
    }
    invalid = start_finish_occupied(map) ? true : invalid;
    return (invalid);
}

bool solver_has_errors(int argc, char **argv)
{
    (void) argv;
    if (argc != 2) {
        my_puterror("Error: Incorrect number of arguments.\n");
        return (true);
    }
    return (false);
}
