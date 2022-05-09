/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Header pause
*/

#pragma once

#include "rpg.h"

typedef enum {
    PAUSE_MENU,
    PAUSE_EXIT,
    PAUSE_SAVE,
    PAUSE_RESUME
} pause_actions_t;

// Functions
int pause_menu(game_t *game, sfSound *music);
