/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Scenes header
*/

#pragma once

#include <SFML/Graphics.h>
#include "configuration.h"
#include "mycsfml_audio.h"
#include "mycsfml_buttons.h"

typedef struct map_menu {
    sfTexture *map_texture;
    sfTexture *offset_texture;
    sfTexture *objects_texture;
    sfSprite *map_sprite;
    sfSprite *offset_sprite;
    sfSprite *objects_sprite;
    sfClock *zoom;
    sfClock *move;
    sfClock *anim;
    char **map_collisions;
    sfVector2i *map_size;
    sfVector2i *map_default_pos;
    sfVector2i *offset_pos;
    sound_t *music;
} map_menu_t;

typedef struct main_menu {
    sfSprite *bg_sprite;
    sfTexture *bg_texture;
    sfTexture *button_texture;
    sfText **texts;
    sfFont *font;
    buttons_t *buttons;
} main_menu_t;

typedef struct bar {
    sfRectangleShape *box;
    sfRectangleShape *progress;
    sfRectangleShape *offset;
    sfClock *clock;
} bar_t;

typedef struct hud {
    bool open;
    sfTexture *box_texture;
    sfTexture *close_texture;
    sfTexture *icon_texture;
    sfTexture *level_texture;
    sfTexture *points_texture;
    sfFont *font;
    sfSprite *box_sprite;
    sfSprite *close_sprite;
    sfSprite *icon_sprite;
    sfSprite *level_sprite;
    sfSprite *points_sprite;
    sfText *health_text;
    sfText *xp_text;
    sfText *level_text;
    sfText *points_text;
    bar_t *health;
    bar_t *xp;
    buttons_t *stats_buttons;
    sfText **stats_texts;
} hud_t;
