/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Elements.h
*/

#ifndef MYCSFML_ELEMENTS_H_
    #define MYCSFML_ELEMENTS_H_
    #include <SFML/Graphics.h>
    #include "mycsfml_framebuffer.h"

void disp_framebuffer(sfTexture *t, framebuffer_t *fb, sfRenderWindow *window);
void disp_texture(const sfTexture *texture, sfRenderWindow *window);
void move_spriterect(sfSprite *sprite, unsigned int offset);
sfSprite *create_sprite(sfTexture *texture, sfVector2f pos);
void csfml_destroyer(const char *format, ...);

#endif /* !MYCSFML_ELEMENTS_H_ */
