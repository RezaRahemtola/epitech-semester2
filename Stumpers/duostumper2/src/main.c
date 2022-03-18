/*
** EPITECH PROJECT, 2022
** duostumper2
** File description:
** main.c
*/

#include <stdlib.h>
#include "connect.h"
#include "my_arrays.h"

int main(int argc, char **argv)
{
    param_t *param = init_param();
    char **args = modify_argv(argc, argv);

    if (param == NULL || args == NULL)
        return (84);
    if (handle_options(argc, args, param) || invalid_option(param)) {
        free(param);
        my_free_2d_array(args);
        return (84);
    }
    play(param);
    free(param);
    my_free_2d_array(args);
    return (0);
}
