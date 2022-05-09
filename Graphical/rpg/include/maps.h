/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Maps menu header
*/

#pragma once

#include "rpg.h"

typedef enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT
} directions_t;

static const float MIN_ZOOM = 1.5f;
static const float MAX_ZOOM = 3.0f;

bool init_map_menu(game_t *game, map_menu_t *menu, char *files[5]);
bool init_map_config(map_menu_t *menu, char *conf);
void display_map(game_t *game, char *files[5]);

void handle_map_events(game_t *game, sfSound *music);
bool handle_movement(map_menu_t *menu, game_t *game);
void handle_zoom(map_menu_t *menu, game_t *game);
void refresh_position(game_t *game, map_menu_t *menu);
void set_position(game_t *game, map_menu_t *menu, sfVector2f *pos);
void set_default_position(game_t *game, map_menu_t *menu);
void refresh_offset(map_menu_t *menu);
bool check_collisions(game_t *game, map_menu_t *menu, sfVector2f pos, \
float speed);

void refresh_mobs(game_t *game, map_menu_t *menu);
void refresh_npc(npc_t *npc, map_menu_t *menu);
void draw_mobs_before(game_t *game);
void draw_mobs(game_t *game, map_menu_t *menu);

sfVector2f *calc_center(sfSprite *sprite, sfRenderWindow *window);
void set_center(sfSprite *sprite, sfRenderWindow *window, sfVector2f *center);
