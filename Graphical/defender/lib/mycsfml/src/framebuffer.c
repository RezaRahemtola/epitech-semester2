/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Framebuffer functions
*/

#include <stdlib.h>
#include "mycsfml_framebuffer.h"

framebuffer_t *framebuffer_create(int width, int height, int bpp)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));

    fb->width = width;
    fb->height = height;
    fb->bpp = bpp;
    fb->pixels = malloc(width * height * bpp / 8);
    return (fb);
}

void framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixels);
    free(fb);
}

void framebuffer_fill(framebuffer_t *fb, sfColor color)
{
    for (unsigned int i = 0; i < fb->width; i++) {
        for (unsigned int j = 0; j < fb->height; j++)
            put_pixel(fb, i, j, color);
    }
}

void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor col)
{
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8)] = col.r;
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 1] = col.g;
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 2] = col.b;
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 3] = col.a;
}

sfColor get_pixel(framebuffer_t *fb, unsigned int x, unsigned int y)
{
    sfColor color;

    color.r = fb->pixels[(y * fb->width + x) * (fb->bpp / 8)];
    color.g = fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 1];
    color.b = fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 2];
    color.a = fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 3];
    return (color);
}
