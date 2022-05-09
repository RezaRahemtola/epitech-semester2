/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Framebuffer.h
*/

#pragma once

#include <SFML/Graphics/Color.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
    int bpp;
} framebuffer_t;

framebuffer_t *framebuffer_create(int width, int height, int bpp);
void framebuffer_destroy(framebuffer_t *fb);
void framebuffer_fill(framebuffer_t *fb, sfColor color);
void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor c);
sfColor get_pixel(framebuffer_t *fb, unsigned int x, unsigned int y);
