/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Health management
*/

#include "hud.h"

static void init_health_text(hud_t *hud)
{
    sfVector2f pos = { 210, 775 };

    hud->health_text = sfText_create();
    sfText_setFont(hud->health_text, hud->font);
    sfText_setCharacterSize(hud->health_text, 20);
    sfText_setColor(hud->health_text, sfWhite);
    sfText_setPosition(hud->health_text, pos);
}

static void init_health_colors(hud_t *hud)
{
    sfColor progress = { 180, 0, 0, 255 };
    sfColor offset = { 230, 180, 30, 255 };

    sfRectangleShape_setFillColor(hud->health->box, sfBlack);
    sfRectangleShape_setFillColor(hud->health->progress, progress);
    sfRectangleShape_setFillColor(hud->health->offset, offset);
}

void init_health_bar(hud_t *hud)
{
    sfVector2f box_size = { 180, 30 };
    sfVector2f progress_size = { 174, 24 };
    sfVector2f box_pos = { 160, 745 };
    sfVector2f progress_pos = { 163, 748 };

    hud->health->box = sfRectangleShape_create();
    hud->health->progress = sfRectangleShape_create();
    hud->health->offset = sfRectangleShape_create();
    hud->health->clock = sfClock_create();
    sfRectangleShape_setSize(hud->health->box, box_size);
    sfRectangleShape_setSize(hud->health->progress, progress_size);
    progress_size.x = 0;
    sfRectangleShape_setSize(hud->health->offset, progress_size);
    sfRectangleShape_setPosition(hud->health->box, box_pos);
    sfRectangleShape_setPosition(hud->health->progress, progress_pos);
    sfRectangleShape_setPosition(hud->health->offset, progress_pos);
    init_health_colors(hud);
    init_health_text(hud);
}

static void refresh_health_bar(bar_t *bar)
{
    sfVector2f size = sfRectangleShape_getSize(bar->progress);
    sfVector2f offset = sfRectangleShape_getSize(bar->offset);
    long millis = sfClock_getElapsedTime(bar->clock).microseconds;

    if (millis > 100000 && offset.x > size.x) {
        offset.x -= 1;
        sfRectangleShape_setSize(bar->offset, offset);
        sfClock_restart(bar->clock);
    }
}

void draw_health_bar(bar_t *bar, game_t *game)
{
    refresh_health_bar(bar);
    sfRenderWindow_drawRectangleShape(game->window, bar->box, NULL);
    sfRenderWindow_drawRectangleShape(game->window, bar->offset, NULL);
    sfRenderWindow_drawRectangleShape(game->window, bar->progress, NULL);
}
