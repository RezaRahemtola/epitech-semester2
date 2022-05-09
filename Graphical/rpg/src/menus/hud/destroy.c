/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** HUD destroy
*/

#include "hud.h"

static void destroy_stats(hud_t *hud)
{
    destroy_buttons(hud->stats_buttons, true);
    for (int i = 0; i < 4; i++) {
        sfText_destroy(hud->stats_texts[i]);
    }
    free(hud->stats_texts);
}

void destroy_hud(hud_t *hud)
{
    sfTexture_destroy(hud->box_texture);
    sfTexture_destroy(hud->close_texture);
    sfTexture_destroy(hud->icon_texture);
    sfTexture_destroy(hud->level_texture);
    sfTexture_destroy(hud->points_texture);
    sfSprite_destroy(hud->box_sprite);
    sfSprite_destroy(hud->close_sprite);
    sfSprite_destroy(hud->icon_sprite);
    sfSprite_destroy(hud->level_sprite);
    sfSprite_destroy(hud->points_sprite);
    sfFont_destroy(hud->font);
    sfText_destroy(hud->health_text);
    sfText_destroy(hud->xp_text);
    sfText_destroy(hud->level_text);
    sfText_destroy(hud->points_text);
    destroy_bar(hud->health);
    destroy_bar(hud->xp);
    destroy_stats(hud);
    free(hud);
}

void destroy_bar(bar_t *bar)
{
    sfRectangleShape_destroy(bar->box);
    sfRectangleShape_destroy(bar->progress);
    sfRectangleShape_destroy(bar->offset);
    sfClock_destroy(bar->clock);
    free(bar);
}
