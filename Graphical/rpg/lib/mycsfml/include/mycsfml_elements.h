/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Elements.h
*/

#pragma once

#include <SFML/Graphics.h>

void disp_texture(const sfTexture *texture, sfRenderWindow *window);
void move_spriterect(sfSprite *sprite, unsigned int offset);
sfSprite *create_sprite(sfTexture *texture, sfVector2f pos);
void csfml_destroyer(const char *format, ...);
