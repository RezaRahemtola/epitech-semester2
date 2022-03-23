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
