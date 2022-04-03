/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** Functions linked with the debug mode
*/

#include <ncurses.h>
#include "tetris.h"
#include "my.h"

static void disp_piece(char **piece)
{
    for (int i = 0; piece[i] != NULL; i++) {
        my_printf("%s\n", piece[i]);
    }
}

static void disp_tetriminos(list_t *list)
{
    tetriminos_t *tetri = NULL;

    my_printf("Number of tetriminos: %d\n", mylist_len(list));
    while (list != NULL) {
        tetri = list->data;
        my_printf("Tetriminos '%s': ", tetri->name);
        if (tetri->has_error == true) {
            my_printf("error\n");
        } else {
            my_printf("size %d*%d, ", tetri->width, tetri->height);
            my_printf("color %d\n", tetri->color);
            disp_piece(tetri->piece);
        }
        list = list->next;
    }
}

void disp_debug(param_t *p, list_t *tetriminos)
{
    my_printf("Key left: %s (%d)\n", keyname(p->key_left), p->key_left);
    my_printf("Key right: %s (%d)\n", keyname(p->key_right), p->key_right);
    my_printf("Key turn: %s (%d)\n", keyname(p->key_turn), p->key_turn);
    my_printf("Key drop: %s (%d)\n", keyname(p->key_drop), p->key_drop);
    my_printf("Key quit: %s (%d)\n", keyname(p->key_quit), p->key_quit);
    my_printf("Key pause: %s (%d)\n", keyname(p->key_pause), p->key_pause);
    my_printf("Next: %s\n", p->with_next ? "Yes" : "No");
    my_printf("Level: %d\n", p->level);
    my_printf("Size: %d*%d\n\n", p->map_rows, p->map_cols);
    disp_tetriminos(tetriminos);
}
