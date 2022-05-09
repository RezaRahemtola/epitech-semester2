/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Game_OBJ.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "mycsfml_clock.h"

typedef struct game_object {
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f speed;
    time_clock_t *clock;
    struct game_object *next;
} game_obj_t;

void move_obj(game_obj_t *obj, void (*check_pos)(game_obj_t *),
int elapsed_millisec);
void move_objects(game_obj_t *list, void (*check_pos)(game_obj_t *),
int elapsed_millisec);

void move_and_disp_obj(game_obj_t *obj, void (*check_pos)(game_obj_t *),
int elapsed_millisec, sfRenderWindow *window);
void move_and_disp_objects(game_obj_t *list, void (*check_pos)(game_obj_t *),
int elapsed_millisec, sfRenderWindow *window);

void disp_obj(sfRenderWindow *window, game_obj_t *obj);
void disp_objects(sfRenderWindow *window, game_obj_t *list);

game_obj_t *create_game_obj(sfTexture *texture, sfVector2f pos,
sfVector2f speed, sfIntRect rect);
void destroy_object_list(game_obj_t *head);
