/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Tests - tetriminos loading
*/

#include <criterion/criterion.h>
#include "tetris.h"

Test(load_tetri_errors, no_directory)
{
    list_t *list = get_tetriminos("nodir");

    cr_assert_null(list);
}

Test(load_tetri_errors, dir_is_file)
{
    list_t *list = get_tetriminos("tests/src/tests_load_tetri.c");

    cr_assert_null(list);
}

Test(load_tetri_errors, valid_tetri)
{
    tetriminos_t *tetri = get_tetrimino("valid.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, false);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, no_piece)
{
    tetriminos_t *tetri = get_tetrimino("no_piece.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, no_piece_no_newline)
{
    tetriminos_t *tetri = get_tetrimino("no_piece_no_newline.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, no_color)
{
    tetriminos_t *tetri = get_tetrimino("no_color.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, no_size)
{
    tetriminos_t *tetri = get_tetrimino("no_size.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, no_info)
{
    tetriminos_t *tetri = get_tetrimino("no_info.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, no_info_no_newline)
{
    tetriminos_t *tetri = get_tetrimino("no_info_no_newline.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, empty)
{
    tetriminos_t *tetri = get_tetrimino("empty.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, negative_size)
{
    tetriminos_t *tetri = get_tetrimino("negative_size.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, size_zero)
{
    tetriminos_t *tetri = get_tetrimino("size_zero.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, width_too_big)
{
    tetriminos_t *tetri = get_tetrimino("width_too_big.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}

Test(load_tetri_errors, middle_empty_line)
{
    tetriminos_t *tetri = get_tetrimino("middle_empty_line.tetrimino", "tests/samples/");

    cr_assert_eq(tetri->has_error, true);
    free_tetrimino(tetri);
}
