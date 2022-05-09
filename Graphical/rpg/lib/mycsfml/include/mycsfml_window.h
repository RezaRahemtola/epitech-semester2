/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Window.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>

sfRenderWindow *create_window(unsigned int width, unsigned int height,
char const *title, unsigned int framerate);
bool is_mouse_on_sprite(sfRenderWindow *win, sfSprite *sprite,
int width, int height);
