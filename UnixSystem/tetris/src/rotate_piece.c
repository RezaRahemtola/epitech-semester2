/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** rotate_piece
*/

#include <stdlib.h>
#include "game.h"
#include "my_arrays.h"
#include "my_strings.h"

void rotate_piece(tetriminos_t *tetri, param_t *param)
{
    char **new = my_array_allocfill(tetri->width, tetri->height, ' ');
    int tmp = 0;

    for (int i = 0; tetri->piece[i] != NULL; i++) {
        for (int j = 0; tetri->piece[i][j] != '\0'; j++) {
            new[j][tetri->height - 1 - i] = tetri->piece[i][j];
        }
    }
    if (tetri->pos->x + tetri->height <= param->map_cols &&
    tetri->pos->y + tetri->width <= param->map_rows) {
        my_free_2d_array(tetri->piece);
        tetri->piece = new;
        tmp = tetri->height;
        tetri->height = tetri->width;
        tetri->width = tmp;
    } else {
        my_free_2d_array(new);
    }
}
