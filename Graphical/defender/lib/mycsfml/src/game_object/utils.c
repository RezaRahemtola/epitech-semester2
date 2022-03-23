/*
** EPITECH PROJECT, 2021
** CSFML Utils
** File description:
** Second temp file for game_obj functions
*/

#include "mycsfml_game_obj.h"

void move_and_disp_obj(game_obj_t *obj, void (*check_pos)(game_obj_t *),
int elapsed_millisec, sfRenderWindow *window)
{
    move_obj(obj, check_pos, elapsed_millisec);
    disp_obj(window, obj);
}

void move_and_disp_objects(game_obj_t *list, void (*check_pos)(game_obj_t *),
int elapsed_millisec, sfRenderWindow *window)
{
    move_objects(list, check_pos, elapsed_millisec);
    disp_objects(window, list);
}
