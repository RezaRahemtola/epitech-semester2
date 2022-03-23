/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** .h
*/

#ifndef MYCSFML_DRAW_H_
    #define MYCSFML_DRAW_H_
    #include <SFML/Graphics/Color.h>
    #include <SFML/System/Vector2.h>
    #include "mycsfml_framebuffer.h"

typedef struct circle_s {
    int x;
    int y;
    sfVector2i center;
    int radius;
} circle_t;

void draw_circle(framebuffer_t *fb, sfVector2i center, int radius, sfColor);
void draw_line(framebuffer_t *fb, sfVector2i a, sfVector2i b, sfColor color);

#endif /* !MYCSFML_DRAW_H_ */
