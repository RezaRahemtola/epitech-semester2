/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Main file
*/

#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "my.h"

static void disp_help(char *binary_name)
{
    my_printf("Usage: %s [options]\nOptions:\n--help\tDisplay this help "
    "\n-L --level={num}\tStart Tetris at level num (def: 1)\n-l --key-left={K}"
    "\tMove the tetrimino LEFT using the K key (def: left arrow)\n-r "
    "--key-right={K}\tMove the tetrimino RIGHT using the K key (def: right "
    "arrow)\n-t --key-turn={K}\tTURN the tetrimino clockwise 90d using the K "
    "key (def: top arrow)\n-d --key-drop={K}\tDROP the tetrimino using the K "
    "key (def: down arrow)\n-q --key-quit={K}\tQUIT the game using the K key "
    "(def: 'q' key)\n-p --key-pause={K}\tPAUSE/RESTART the game using the K "
    "key (def: space bar)\n--map-size={row,col}\tSet the numbers of rows and "
    "columns of the map (def: 20,10)\n-w --without-next\tHide next tetrimino "
    "(def: false)\n-D --debug\tDebug mode (def: false)\n", binary_name);
}

static bool is_tetri_error(list_t *list)
{
    tetriminos_t *tetri = NULL;

    if (list == NULL)
        return (true);
    while (list != NULL) {
        tetri = list->data;
        if (tetri->has_error == false)
            return (false);
        list = list->next;
    }
    return (true);
}

int main(int argc, char **argv)
{
    param_t *param = init_param();
    list_t *tetriminos = get_tetriminos("tetriminos/");
    bool is_error = handle_options(argc, argv, param);

    srand(time(NULL));
    if (!is_error && param->help) {
        disp_help(argv[0]);
        free(param);
        mylist_destroy(tetriminos, true, &free_tetrimino);
        return (0);
    }
    if (!is_error && param->debug) {
        disp_debug(param, tetriminos);
        is_error = is_tetri_error(tetriminos);
    }
    if (!is_error && !param->debug)
        play(param, tetriminos);
    free(param);
    mylist_destroy(tetriminos, true, &free_tetrimino);
    return is_error ? 84 : 0;
}
