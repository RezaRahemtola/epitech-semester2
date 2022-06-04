/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Window functions
*/

#include <stddef.h>
#include "mycsfml_window.h"

bool is_mouse_on_sprite(sfRenderWindow *win, sfSprite *sprite,
int width, int height)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    mouse.x *= (float) width / size.x;
    mouse.y *= (float) height / size.y;
    return sfFloatRect_contains(&bounds, mouse.x, mouse.y);
}
