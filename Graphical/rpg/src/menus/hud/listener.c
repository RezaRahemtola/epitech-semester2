/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Events listener
*/

#include "hud.h"
#include "my_math.h"
#include "my_string.h"
#include "my.h"

void listen_health(game_t *game)
{
    int h = (int) game->player->health;
    int mh = (int) game->player->max_health;
    int str = 0;
    char *health = my_stringf("%d/%d", h, mh);
    sfVector2f size = sfRectangleShape_getSize(game->hud->health->progress);
    sfVector2f offset = sfRectangleShape_getSize(game->hud->health->offset);
    sfVector2f pos = { 240, 780 };

    str = my_strlen(health);
    pos.x -= ((float) str / 2) * 10;
    size.x = game->player->health / game->player->max_health * 174;
    sfRectangleShape_setSize(game->hud->health->progress, size);
    sfText_setString(game->hud->health_text, health);
    sfText_setPosition(game->hud->health_text, pos);
    free(health);
    if (offset.x < size.x) {
        offset.x = size.x;
        sfRectangleShape_setSize(game->hud->health->offset, offset);
    }
}

void listen_xp(game_t *game)
{
    int x = game->player->xp;
    int mx = get_needed_xp(game);
    int str = 0;
    char *xp = my_stringf("%d/%d", x, mx);
    sfVector2f size = sfRectangleShape_getSize(game->hud->xp->progress);
    sfVector2f pos = { 190, 875 };

    str = my_strlen(xp);
    pos.x -= ((float) str / 2) * 10;
    size.x = (float) game->player->xp / (float) mx * 294;
    sfRectangleShape_setSize(game->hud->xp->progress, size);
    sfText_setString(game->hud->xp_text, xp);
    sfText_setPosition(game->hud->xp_text, pos);
    free(xp);
}

void listen_level(game_t *game)
{
    int size = my_nbrlen(game->player->level);
    char *level = my_stringf("%d", game->player->level);
    sfVector2f pos = { 120, 793 };

    for (int i = 1; i < size; i++) {
        pos.x -= 3;
        pos.y += 2;
    }
    sfText_setString(game->hud->level_text, level);
    sfText_setCharacterSize(game->hud->level_text, 22 - (size * 3));
    sfText_setPosition(game->hud->level_text, pos);
    free(level);
}

void listen_stats(game_t *game)
{
    int max = get_total_health(game->player);
    float gap = game->player->max_health - game->player->health;
    char *points = my_stringf("%d", game->player->points);

    sfText_setString(game->hud->points_text, points);
    free(points);
    stats_attack(game);
    stats_defense(game);
    stats_speed(game);
    stats_health(game);
    game->player->max_health = 100 + ((float) max * 10);
    game->player->health = game->player->max_health - gap;
    listen_health(game);
}
