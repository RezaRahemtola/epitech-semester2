/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions related to tetriminos
*/

#include <stdlib.h>
#include "tetris.h"
#include "my_strings.h"
#include "my_arrays.h"

tetriminos_t *init_tetrimino(char *name)
{
    tetriminos_t *tetri = malloc(sizeof(tetriminos_t));
    pos_t *pos = malloc(sizeof(pos_t));

    *pos = (pos_t){0, 0};
    tetri->name = my_strdup(name);
    tetri->piece = NULL;
    tetri->color = 0;
    tetri->width = 0;
    tetri->height = 0;
    tetri->has_error = false;
    tetri->pos = pos;
    return (tetri);
}

tetriminos_t *dup_tetrimino(tetriminos_t *src)
{
    tetriminos_t *new = malloc(sizeof(tetriminos_t));
    pos_t *pos = malloc(sizeof(pos_t));

    *pos = (pos_t){src->pos->x, src->pos->y};
    new->name = my_strdup(src->name);
    new->piece = my_arraydup(src->piece);
    new->color = src->color;
    new->width = src->width;
    new->height = src->height;
    new->has_error = src->has_error;
    new->pos = pos;
    return (new);
}

list_t *filter_tetriminos(list_t *list, int width, int height)
{
    list_t *new = NULL;
    tetriminos_t *tetri = NULL;

    while (list != NULL) {
        tetri = list->data;
        tetri->has_error = (tetri->width > width || tetri->height > height) ?
        true : tetri->has_error;
        if (!tetri->has_error)
            mylist_append(dup_tetrimino(tetri), &new);
        list = list->next;
    }
    return (new);
}

tetriminos_t *get_random_tetri(list_t *list, int map_width)
{
    int len = mylist_len(list);
    int rand_nb = rand() % len;
    tetriminos_t *tetri = NULL;

    for (int i = 0; i < rand_nb; i++)
        list = list->next;
    tetri = dup_tetrimino((tetriminos_t *)list->data);
    tetri->pos->x = map_width / 2 - tetri->width / 2;
    return (tetri);
}

void free_tetrimino(void *tetri)
{
    tetriminos_t *tmp = tetri;

    if (tmp == NULL)
        return;
    free(tmp->name);
    my_free_2d_array(tmp->piece);
    free(tmp->pos);
    free(tetri);
}
