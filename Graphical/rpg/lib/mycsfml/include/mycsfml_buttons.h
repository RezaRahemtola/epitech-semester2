/*
** EPITECH PROJECT, 2022
** CSFML utils
** File description:
** Header file
*/

#pragma once

#include <SFML/Graphics.h>

typedef struct buttons {
    int type;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    struct buttons *next;
} buttons_t;

void change_buttons_state(buttons_t *button, sfEvent *event,
sfRenderWindow *window);
buttons_t *create_button(sfTexture *texture, sfVector2f pos, int type);
buttons_t *get_clicked_button(sfRenderWindow *window, buttons_t *buttons);
void display_buttons(buttons_t *list, sfRenderWindow *window);
void destroy_buttons(buttons_t *head, sfBool destroy_texture);
