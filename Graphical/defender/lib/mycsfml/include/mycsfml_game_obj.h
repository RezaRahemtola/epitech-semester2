/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Game_OBJ.h
*/

#ifndef MYCSFML_GAME_OBJ_H_
    #define MYCSFML_GAME_OBJ_H_
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

void destroy_object_list(game_obj_t *head);

#endif /* !MYCSFML_GAME_OBJ_H_ */
