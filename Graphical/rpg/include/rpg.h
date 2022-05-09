/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Header
*/

#pragma once

#include <stdbool.h>
#include "mobs.h"
#include "player.h"
#include "scenes.h"

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

typedef struct settings {
    int width;
    int height;
    bool fullscreen;
    bool vsync;
    int framerate;
    float volume;
} settings_t;

typedef struct global {
    int *xp;
    int *points;
    int def_hp;
    int def_points;
    int level_max;
    char **mobs;
    char **npcs;
} global_t;

typedef struct game {
    sfRenderWindow *window;
    settings_t *settings;
    global_t *config;
    main_menu_t *main_menu;
    hud_t *hud;
    player_t *player;
    list_t *mob_types;
    list_t *mobs;
    list_t *npcs;
    sound_t *click_sound;
    bool playing;
} game_t;

// Core
void game_loop(game_t *game);

// Init
bool init_game(game_t *game);
void init_entities(game_t *game);

// Destroy
void destroy_game_content(game_t *game);
void destroy_bar(bar_t *bar);

// Window management
sfRenderWindow *init_window(settings_t *settings);
void handle_events(game_t *game);

// Settings management
bool switch_fullscreen(game_t *game, settings_t *settings);

// Global config
void add_xp(game_t *game, int xp);
int get_needed_xp(game_t *game);

// Image manipulation
void scale_background(sfRenderWindow *window, sfSprite *sprite);
void add_button(buttons_t **list, buttons_t *button);
