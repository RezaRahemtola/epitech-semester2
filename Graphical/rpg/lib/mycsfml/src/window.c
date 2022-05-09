/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Window functions
*/

#include <stddef.h>
#include "mycsfml_window.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height,
const char *title, unsigned int framerate)
{
    sfRenderWindow *window;
    sfVideoMode mode = {width, height, 32};

    window = sfRenderWindow_create(mode, title, sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return (window);
}

bool is_mouse_on_sprite(sfRenderWindow *win, sfSprite *sprite,
int width, int height)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2u size = sfRenderWindow_getSize(win);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    mouse.x *= (float) width / size.x;
    mouse.y *= (float) height/ size.y;
    return sfFloatRect_contains(&bounds, mouse.x, mouse.y);
}
