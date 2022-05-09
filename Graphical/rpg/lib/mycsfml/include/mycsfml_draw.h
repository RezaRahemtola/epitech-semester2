/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** .h
*/

#pragma once

#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include "mycsfml_framebuffer.h"

typedef struct circle {
    int x;
    int y;
    sfVector2i center;
    int radius;
} circle_t;

void draw_circle(framebuffer_t *fb, sfVector2i center, int radius, sfColor);
void draw_line(framebuffer_t *fb, sfVector2i a, sfVector2i b, sfColor color);
