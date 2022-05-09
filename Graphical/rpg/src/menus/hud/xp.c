/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Experience management
*/

#include "hud.h"

static void init_xp_text(hud_t *hud)
{
    sfVector2f pos = { 150, 750 };

    hud->xp_text = sfText_create();
    sfText_setFont(hud->xp_text, hud->font);
    sfText_setCharacterSize(hud->xp_text, 20);
    sfText_setColor(hud->xp_text, sfWhite);
    sfText_setPosition(hud->xp_text, pos);
}

static void init_xp_colors(hud_t *hud)
{
    sfColor box = { 5, 15, 120, 255 };
    sfColor progress = { 50, 90, 180, 255 };
    sfColor offset = { 90, 100, 230, 255 };

    sfRectangleShape_setOutlineColor(hud->xp->box, sfBlack);
    sfRectangleShape_setFillColor(hud->xp->box, box);
    sfRectangleShape_setFillColor(hud->xp->progress, progress);
    sfRectangleShape_setFillColor(hud->xp->offset, offset);
}

void init_xp_bar(hud_t *hud)
{
    sfVector2f box_size = { 300, 25 };
    sfVector2f progress_size = { 294, 19 };
    sfVector2f box_pos = { 40, 845 };
    sfVector2f progress_pos = { 43, 848 };

    hud->xp->box = sfRectangleShape_create();
    hud->xp->progress = sfRectangleShape_create();
    hud->xp->offset = sfRectangleShape_create();
    hud->xp->clock = sfClock_create();
    sfRectangleShape_setSize(hud->xp->box, box_size);
    sfRectangleShape_setSize(hud->xp->progress, progress_size);
    progress_size.x = 0;
    sfRectangleShape_setSize(hud->xp->offset, progress_size);
    sfRectangleShape_setPosition(hud->xp->box, box_pos);
    sfRectangleShape_setPosition(hud->xp->progress, progress_pos);
    sfRectangleShape_setPosition(hud->xp->offset, progress_pos);
    sfRectangleShape_setOutlineThickness(hud->xp->box, 3);
    init_xp_colors(hud);
    init_xp_text(hud);
}

static void refresh_xp_bar(bar_t *bar)
{
    int diff = 0;
    sfVector2f size = sfRectangleShape_getSize(bar->progress);
    sfVector2f offset = sfRectangleShape_getSize(bar->offset);
    long millis = sfClock_getElapsedTime(bar->clock).microseconds;

    if (millis > 100000 && offset.x != size.x) {
        diff = (int) size.x - (int) offset.x;
        offset.x += (float) (size.x > offset.x ? MIN(5, diff) : -20);
        if (offset.x < 0) {
            offset.x = 0;
        }
        sfRectangleShape_setSize(bar->offset, offset);
        sfClock_restart(bar->clock);
    }
}

void draw_xp_bar(bar_t *bar, game_t *game)
{
    refresh_xp_bar(bar);
    sfRenderWindow_drawRectangleShape(game->window, bar->box, NULL);
    sfRenderWindow_drawRectangleShape(game->window, bar->progress, NULL);
    sfRenderWindow_drawRectangleShape(game->window, bar->offset, NULL);
}
