/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Stats HUD management
*/

#pragma once

#include <stdbool.h>
#include "mycsfml_buttons.h"
#include "rpg.h"

typedef enum stats_types {
    ATTACK,
    DEFENSE,
    SPEED,
    HEALTH
} stats_types_t;

void draw_hud(hud_t *hud, game_t *game);
void draw_health_bar(bar_t *bar, game_t *game);
void draw_xp_bar(bar_t *bar, game_t *game);

void handle_hud_events(game_t *game, sfEvent *event);

bool init_hud(hud_t *hud, game_t *game);
void init_health_bar(hud_t *hud);
void init_xp_bar(hud_t *hud);
bool init_stats(hud_t *hud);

void destroy_hud(hud_t *hud);

void listen_health(game_t *game);
void listen_xp(game_t *game);
void listen_level(game_t *game);
void listen_stats(game_t *game);
void stats_attack(game_t *game);
void stats_defense(game_t *game);
void stats_speed(game_t *game);
void stats_health(game_t *game);
