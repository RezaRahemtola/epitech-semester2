/*
** EPITECH PROJECT, 2021
** CSFML Utils
** File description:
** Functions to move game objects
*/

#include "mycsfml_game_obj.h"

void move_obj(game_obj_t *obj, void (*check_pos)(game_obj_t *),
int elapsed_millisec)
{
    clock_update_time(obj->clock);
    if (sfTime_asMilliseconds(obj->clock->time) >= elapsed_millisec) {
        obj->pos.x += obj->speed.x;
        obj->pos.y += obj->speed.y;
        sfSprite_setPosition(obj->sprite, obj->pos);
        if (check_pos != NULL)
            check_pos(obj);
        sfClock_restart(obj->clock->clock);
    }
}

void move_objects(game_obj_t *list, void (*check_pos)(game_obj_t *),
int elapsed_millisec)
{
    game_obj_t *obj = list;

    while (obj != NULL) {
        move_obj(obj, check_pos, elapsed_millisec);
        obj = obj->next;
    }
}
