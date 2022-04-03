/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Tests for params and options
*/

#include <criterion/criterion.h>
#include "tetris.h"

Test(params, no_arg)
{
    param_t *param = init_param();

    cr_assert_eq(handle_options(1, (char *[]){"./tetris", NULL}, param), false);
    free(param);
}

Test(params, help_alone)
{
    param_t *param = init_param();

    handle_options(2, (char *[]){"./tetris", "--help", NULL}, param);
    cr_assert_eq(param->help, true);
    free(param);
}

Test(params, subject_example)
{
    param_t *param = init_param();

    handle_options(7, (char *[]){"./tetris", "-d", "120", "-D", "--key-turn=32", "-p", "112", NULL}, param);
    cr_assert_eq(param->debug, true);
    cr_assert_eq(param->key_pause, 112);
    free(param);
}

Test(params, map_size)
{
    param_t *param = init_param();

    handle_options(3, (char *[]){"./tetris", "--map-size", "42,84", NULL}, param);
    cr_assert_eq(param->map_rows, 42);
    cr_assert_eq(param->map_cols, 84);
    free(param);
}

Test(params, others)
{
    param_t *param = init_param();

    handle_options(7, (char *[]){"./tetris", "-q", "21", "--key-left=42", "-r", "84", "--level=5", NULL}, param);
    cr_assert_eq(param->key_quit, 21);
    cr_assert_eq(param->key_left, 42);
    cr_assert_eq(param->key_right, 84);
    cr_assert_eq(param->level, 5);
    free(param);
}

Test(params, same_key)
{
    param_t *param = init_param();
    bool result = handle_options(5, (char *[]){"./tetris", "-q", "42", "-r", "42", NULL}, param);

    cr_assert_eq(param->key_quit, 42);
    cr_assert_eq(param->key_right, 42);
    cr_assert_eq(result, true);
    free(param);
}
