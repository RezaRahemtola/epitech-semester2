/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Functions to draw elements
*/

#include <math.h>
#include "mycsfml_draw.h"

static void is_in_circle(circle_t circle, framebuffer_t *fb, sfColor c)
{
    int x_pow = pow(circle.x - circle.center.x, 2);
    int y_pow = pow(circle.y - circle.center.y, 2);

    if ((x_pow + y_pow) <= pow(circle.radius, 2))
        put_pixel(fb, circle.x, circle.y, c);
}

void draw_circle(framebuffer_t * fb, sfVector2i center, int radius, sfColor c)
{
    circle_t circle = {0, 0, center, radius};

    for (unsigned int x = 0; x < fb->width; x++) {
        for (unsigned int y = 0; y < fb->height; y++) {
            circle.x = x;
            circle.y = y;
            is_in_circle(circle, fb, c);
        }
    }
}

void draw_line(framebuffer_t *fb, sfVector2i point_a, sfVector2i point_b,
sfColor color)
{
    sfVector2i biggest = (point_a.x > point_b.x) ? (point_a) : (point_b);
    sfVector2i lowest = (point_a.x < point_b.x) ? (point_a) : (point_b);
    int dx = biggest.x - lowest.x;
    int dy = biggest.y - lowest.y;
    int y = 0;

    for (int x = lowest.x; x < biggest.x; x++) {
        y = lowest.y + dy * (x - lowest.x) / dx;
        put_pixel(fb, x, y, color);
    }
}
