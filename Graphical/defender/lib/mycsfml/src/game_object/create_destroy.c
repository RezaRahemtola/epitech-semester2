/*
** EPITECH PROJECT, 2021
** CSFML Utils
** File description:
** Game objects functions
*/

#include "mycsfml_game_obj.h"

game_obj_t *create_game_obj(sfTexture *texture, sfVector2f pos,
sfVector2f speed, sfIntRect rect)
{
    game_obj_t *game_obj = malloc(sizeof(game_obj_t));
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return (NULL);
    if (texture == NULL)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    game_obj->sprite = sprite;
    game_obj->pos = pos;
    sfSprite_setPosition(game_obj->sprite, game_obj->pos);
    game_obj->rect = rect;
    sfSprite_setTextureRect(game_obj->sprite, game_obj->rect);
    game_obj->speed = speed;
    game_obj->clock = clock_create();
    return (game_obj);
}

void destroy_object_list(game_obj_t *head)
{
    game_obj_t *current = head;
    game_obj_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        sfSprite_destroy(tmp->sprite);
        clock_destroy(tmp->clock);
        free(tmp);
    }
}
