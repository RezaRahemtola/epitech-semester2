/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Framebuffer.h
*/

#ifndef MYCSFML_FRAMEBUFFER_H_
    #define MYCSFML_FRAMEBUFFER_H_
    #include <SFML/Graphics/Color.h>

typedef struct framebuffer_s {
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

#endif /* !MYCSFML_FRAMEBUFFER_H_ */
