/*
** EPITECH PROJECT, 2021
** CSFML Utils
** File description:
** Functions to display game objects
*/

#include "mycsfml_game_obj.h"
#include "mycsfml_elements.h"

void disp_obj(sfRenderWindow *window, game_obj_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    disp_texture(sfSprite_getTexture(obj->sprite), window);
}

void disp_objects(sfRenderWindow *window, game_obj_t *list)
{
    game_obj_t *tmp = list;

    while (tmp != NULL) {
        disp_obj(window, tmp);
        tmp = tmp->next;
    }
}
