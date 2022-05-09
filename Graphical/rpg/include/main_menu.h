/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main menu header
*/

#pragma once

#include "my.h"
#include "rpg.h"

typedef enum {
    BUTTON_PLAY,
    BUTTON_TUTORIAL,
    BUTTON_SETTINGS,
    BUTTON_EXIT
} main_menu_buttons_types_t;

// Main menu core
void main_menu(game_t *game);
void handle_main_menu_events(game_t *game);

// Main menu resizes
void resize_main_menu(main_menu_t *menu, sfRenderWindow *window);

// Main menu struct
main_menu_t *init_main_menu(game_t *game);
void free_main_menu(main_menu_t *main_menu);
