/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Settings header
*/

#pragma once

#include "rpg.h"
#include "mycsfml_buttons.h"

typedef enum {
    BUTTON_FRAMERATE,
    BUTTON_FULLSCREEN,
    BUTTON_VSYNC,
    BUTTON_VOLUME_UP,
    BUTTON_VOLUME_DOWN,
    BUTTON_BACK
} settings_button_t;

// Core
void settings_menu(game_t *game);

// Utils
void apply_settings(game_t *game);
void update_settings(game_t *g, buttons_t *b, sfTexture *states[2], bool *end);
