/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Functions to check button states and change settings
*/

#include "rpg.h"
#include "settings.h"

static void reset_texture_rect(sfSprite *sprite)
{
    const sfTexture *texture = sfSprite_getTexture(sprite);
    sfVector2u size = sfTexture_getSize(texture);

    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, size.x / 3, size.y});
}

void update_settings(game_t *g, buttons_t *b, sfTexture *states[2], bool *end)
{
    settings_t *s = g->settings;
    sfTexture *on = states[0];
    sfTexture *off = states[1];
    const sfTexture *texture = sfSprite_getTexture(b->sprite);

    if (b->type == BUTTON_FULLSCREEN) {
        s->fullscreen = (texture == on);
        sfSprite_setTexture(b->sprite, s->fullscreen ? off : on, sfFalse);
        switch_fullscreen(g, s);
    }
    if (b->type == BUTTON_VSYNC) {
        s->vsync = (texture == on);
        sfSprite_setTexture(b->sprite, s->vsync ? off : on, sfFalse);
        sfRenderWindow_setVerticalSyncEnabled(g->window, s->vsync);
    }
    if (b->type == BUTTON_BACK)
        *end = true;
    reset_texture_rect(b->sprite);
}

void apply_settings(game_t *game)
{
    settings_t *settings = game->settings;
    sfVector2u size = {settings->width, settings->height};

    sfRenderWindow_setFramerateLimit(game->window, settings->framerate);
    sfRenderWindow_setSize(game->window, size);
}
