/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** main
*/

#include "sokoban.h"

int main(int argc, char **argv)
{
    bool won = true;
    char **map = NULL;
    char **base = NULL;

    if (check_errors(argc, argv))
        return (84);
    map = load_map_from_file(argv[1]);
    base = load_map_from_file(argv[1]);
    won = sokoban(map, base);
    my_free_2d_array(map);
    my_free_2d_array(base);
    return (won) ? 0 : 1;
}
