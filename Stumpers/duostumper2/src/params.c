/*
** EPITECH PROJECT, 2022
** connect4
** File description:
** Functions to handle option params
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "connect.h"
#include "my.h"

param_t *init_param(void)
{
    param_t *new = malloc(sizeof(param_t));

    if (new == NULL)
        return (NULL);
    new->width = 7;
    new->height = 6;
    new->player_one = 'X';
    new->player_two = 'O';
    new->referee = '#';
    return (new);
}

static bool handle_size_options(char optchar, param_t *param)
{
    int size = my_getnbr(optarg);

    if (size < 1)
        return (true);
    if (optchar == 'w')
        param->width = size;
    else if (optchar == 'h')
        param->height = size;
    return (false);
}

static bool handle_char_options(char optchar, param_t *param)
{
    if (my_strlen(optarg) != 1)
        return (true);
    if (optchar == 'a')
        param->referee = optarg[0];
    if (optchar == '1')
        param->player_one = optarg[0];
    if (optchar == '2')
        param->player_two = optarg[0];
    return (false);
}

static bool check_option(char optchar, param_t *param)
{
    bool is_error = false;

    if (optchar == 'w' || optchar == 'h')
        is_error = handle_size_options(optchar, param) ? true : is_error;
    if (optchar == 'a' || optchar == '1' || optchar == '2')
        is_error = handle_char_options(optchar, param) ? true : is_error;
    if (optchar == ':' || optchar == '?')
        is_error = true;
    return (is_error);
}

bool handle_options(int argc, char **argv, param_t *param)
{
    char optchar = '\0';
    bool is_error = false;
    char *optstring = "w:h:1:2:a:";

    while (optchar != -1 && !is_error) {
        optchar = getopt(argc, argv, optstring);
        is_error = check_option(optchar, param);
    }
    return (is_error);
}
