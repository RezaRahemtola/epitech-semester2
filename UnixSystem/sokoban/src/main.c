/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** main
*/

#include "sokoban.h"

static void disp_usage(void)
{
    my_printf("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file repres");
    my_printf("enting the warehouse map, containing '#' for walls, 'P' for ");
    my_printf("the player, 'X' for boxes and 'O' for storage locations.\n");
}

int main(int argc, char **argv)
{
    bool won = true;
    char **map = NULL;
    char **base = NULL;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        disp_usage();
        return (0);
    }
    if (check_errors(argc, argv))
        return (84);
    map = load_map_from_file(argv[1]);
    base = load_map_from_file(argv[1]);
    won = sokoban(map, base);
    my_free_2d_array(map);
    my_free_2d_array(base);
    return (won) ? 0 : 1;
}
