/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** HUD initialization
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "hud.h"

static bool init_level(hud_t *hud)
{
    sfVector2u size;
    sfVector2f scale;
    sfVector2f pos = { 85, 765 };
    sfTexture *txt = sfTexture_createFromFile("assets/hud/level.png", NULL);

    hud->level_texture = txt;
    if (hud->level_texture == NULL)
        return (false);
    hud->level_sprite = sfSprite_create();
    hud->level_text = sfText_create();
    size = sfTexture_getSize(hud->level_texture);
    scale.x = 80.0f / (float) size.x;
    scale.y = 80.0f / (float) size.y;
    sfSprite_setTexture(hud->level_sprite, hud->level_texture, sfFalse);
    sfSprite_setScale(hud->level_sprite, scale);
    sfSprite_setPosition(hud->level_sprite, pos);
    sfText_setFont(hud->level_text, hud->font);
    sfText_setCharacterSize(hud->level_text, 20);
    sfText_setColor(hud->level_text, sfBlack);
    return (true);
}

static bool init_icon(hud_t *hud)
{
    sfVector2u size;
    sfVector2f scale;
    sfVector2f pos = { 40, 715 };
    sfTexture *txt = sfTexture_createFromFile("assets/hud/icon.png", NULL);

    hud->icon_texture = txt;
    if (hud->icon_texture == NULL) {
        return (false);
    }
    hud->icon_sprite = sfSprite_create();
    size = sfTexture_getSize(hud->icon_texture);
    scale.x = 100.0f / (float) size.x;
    scale.y = 100.0f / (float) size.y;
    sfSprite_setTexture(hud->icon_sprite, hud->icon_texture, sfFalse);
    sfSprite_setScale(hud->icon_sprite, scale);
    sfSprite_setPosition(hud->icon_sprite, pos);
    return (true);
}

static bool init_hud_close(hud_t *hud)
{
    sfVector2u size;
    sfVector2f scale;
    sfVector2f pos = { 345, 710 };

    hud->close_texture = sfTexture_createFromFile("assets/hud/exit.png", NULL);
    if (hud->close_texture == NULL) {
        return (false);
    }
    hud->close_sprite = sfSprite_create();
    size = sfTexture_getSize(hud->close_texture);
    scale.x = 25.0f / (float) size.x;
    scale.y = 25.0f / (float) size.y;
    sfSprite_setTexture(hud->close_sprite, hud->close_texture, sfFalse);
    sfSprite_setScale(hud->close_sprite, scale);
    sfSprite_setPosition(hud->close_sprite, pos);
    return (true);
}

static bool init_hud_box(hud_t *hud)
{
    sfVector2u size;
    sfVector2f scale;
    sfVector2f pos = { 0, 680 };

    hud->box_texture = sfTexture_createFromFile("assets/hud/box.png", NULL);
    if (hud->box_texture == NULL) {
        return (false);
    }
    hud->box_sprite = sfSprite_create();
    size = sfTexture_getSize(hud->box_texture);
    scale.x = 400.0f / (float) size.x;
    scale.y = 400.0f / (float) size.y;
    sfSprite_setTexture(hud->box_sprite, hud->box_texture, sfFalse);
    sfSprite_setScale(hud->box_sprite, scale);
    sfSprite_setPosition(hud->box_sprite, pos);
    return (true);
}

bool init_hud(hud_t *hud, game_t *game)
{
    hud->open = true;
    hud->health = malloc(sizeof(bar_t));
    hud->xp = malloc(sizeof(bar_t));
    hud->font = sfFont_createFromFile("assets/hud/font.ttf");
    if (hud->health == NULL || hud->xp == NULL || hud->font == NULL) {
        return (false);
    } else if (!init_hud_box(hud) || !init_hud_close(hud) || !init_icon(hud)) {
        return (false);
    }
    if (!init_level(hud) || !init_stats(hud)) {
        return (false);
    }
    init_health_bar(hud);
    init_xp_bar(hud);
    listen_health(game);
    listen_xp(game);
    listen_level(game);
    listen_stats(game);
    return (true);
}
