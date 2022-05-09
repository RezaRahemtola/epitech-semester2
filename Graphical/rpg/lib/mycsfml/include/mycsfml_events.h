/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** .h
*/

#pragma once

#include <SFML/Graphics.h>

void check_closing_event(sfRenderWindow *window, sfEvent event);
sfBool is_click_on_sprite(sfEvent *event, sfSprite *sprite);
