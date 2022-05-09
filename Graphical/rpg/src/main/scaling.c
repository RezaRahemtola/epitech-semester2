/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Scaling operations
*/

#include "rpg.h"

void scale_background(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2f scale = { 1, 1 };
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2u texture = sfTexture_getSize(sfSprite_getTexture(sprite));

    scale.x = (float) size.x / (float) texture.x;
    scale.y = (float) size.y / (float) texture.y;
    sfSprite_setScale(sprite, scale);
}
