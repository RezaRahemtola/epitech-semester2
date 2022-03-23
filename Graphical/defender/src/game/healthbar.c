/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions to display healthbars for enemis
*/

#include "defender.h"

void display_healthbar(enemy_t *current, sfSprite *healthbar,
sfSprite *background, sfRenderWindow *window)
{
    int missing_health = current->type->health - current->health;
    sfVector2f pos = sfSprite_getPosition(current->sprite);
    sfIntRect rect = {0, 0, 70, 10};
    sfVector2f scale = sfSprite_getScale(current->sprite);

    pos.x -= (sfSprite_getTextureRect(current->sprite).width * scale.x) / 2;
    pos.y -= (sfSprite_getTextureRect(current->sprite).height * scale.y) / 2;
    rect.width -= (missing_health * 100 / current->type->health);
    sfSprite_setTextureRect(healthbar, rect);
    sfSprite_setPosition(healthbar, pos);
    sfSprite_setPosition(background, pos);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawSprite(window, healthbar, NULL);
}
