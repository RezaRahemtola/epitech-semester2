/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions to use the param structure
*/

#include <ncurses.h>
#include <getopt.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

const struct option LONG_OPT[] = {
        {"help", no_argument, NULL, 'h'},
        {"level", required_argument, NULL, 'L'},
        {"key-left", required_argument, NULL, 'l'},
        {"key-right", required_argument, NULL, 'r'},
        {"key-turn", required_argument, NULL, 't'},
        {"key-drop", required_argument, NULL, 'd'},
        {"key-quit", required_argument, NULL, 'q'},
        {"key-pause", required_argument, NULL, 'p'},
        {"map-size", required_argument, NULL, 'm'},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'D'},
        {NULL, 0, NULL, 0}
};

param_t *init_param(void)
{
    param_t *param = malloc(sizeof(param_t));

    param->level = 1;
    param->key_left = KEY_LEFT;
    param->key_right = KEY_RIGHT;
    param->key_turn = KEY_UP;
    param->key_drop = KEY_DOWN;
    param->key_quit = 'q';
    param->key_pause = ' ';
    param->map_rows = 20;
    param->map_cols = 10;
    param->with_next = true;
    param->debug = false;
    param->help = false;
    return (param);
}

static void update_key_param(param_t *param, char opt)
{
    if (opt == 'l')
        param->key_left = my_getnbr(optarg);
    if (opt == 'r')
        param->key_right = my_getnbr(optarg);
    if (opt == 't')
        param->key_turn = my_getnbr(optarg);
    if (opt == 'd')
        param->key_drop = my_getnbr(optarg);
    if (opt == 'q')
        param->key_quit = my_getnbr(optarg);
    if (opt == 'p')
        param->key_pause = my_getnbr(optarg);
}

static bool set_map(param_t *param)
{
    char **sizes = NULL;
    int rows = 0;
    int cols = 0;

    if (my_strcount(optarg, ",") != 1) {
        my_puterror("Invalid map size, retry with --help\n");
        return (true);
    }
    sizes = my_strsplit(optarg, ',');
    rows = my_getnbr(sizes[0]);
    cols = my_getnbr(sizes[1]);
    my_free_2d_array(sizes);
    if (rows <= 0 || cols <= 0) {
        my_puterror("Invalid map size, retry with --help\n");
        return (true);
    }
    param->map_rows = rows;
    param->map_cols = cols;
    return (false);
}

static bool check_option(char c, param_t *param)
{
    bool is_error = false;

    if (c == 'L')
        param->level = my_getnbr(optarg);
    if (c == 'l' || c == 'r' || c == 't' || c == 'd' || c == 'q' || c == 'p') {
        is_error = my_str_isnum(optarg) ? is_error : true;
        update_key_param(param, c);
    }
    if (c == 'm')
        is_error = set_map(param) ? true : is_error;
    if (c == 'w')
        param->with_next = false;
    if (c == 'D')
        param->debug = true;
    if (c == 'h')
        param->help = true;
    if (c == ':' || c == '?' || param->level <= 0)
        is_error = true;
    return (is_error);
}

bool handle_options(int argc, char **argv, param_t *param)
{
    char c = '\0';
    bool is_error = false;
    char *optstring = "L:l:r:t:d:q:p:wD";
    int *arr = NULL;

    while (c != -1 && !is_error) {
        c = getopt_long(argc, argv, optstring, LONG_OPT, NULL);
        is_error = check_option(c, param);
    }
    arr = (int[6]){param->key_left, param->key_right, param->key_turn,
param->key_drop, param->key_quit, param->key_pause};
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            is_error = (arr[i] == arr[j] && i != j) ? true : is_error;
    return (is_error);
}
