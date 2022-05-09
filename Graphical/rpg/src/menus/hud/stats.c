/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Stats listener
*/

#include "hud.h"
#include "my_string.h"
#include "my.h"

void stats_attack(game_t *game)
{
    int size = 0;
    int base = game->player->attack - 1;
    int total = get_total_attack(game->player) - 1;
    char *text = NULL;
    sfVector2f pos = { 60, 955 };

    if (base != total) {
        text = my_stringf("%d (+ %d)", base, total - base);
    } else {
        text = my_stringf("%d", base);
    }
    size = my_strlen(text);
    pos.x -= ((float) size / 2) * 10;
    sfText_setString(game->hud->stats_texts[ATTACK], text);
    sfText_setPosition(game->hud->stats_texts[ATTACK], pos);
    free(text);
}

void stats_defense(game_t *game)
{
    int size = 0;
    int base = game->player->defense - 1;
    int total = get_total_defense(game->player) - 1;
    char *text = NULL;
    sfVector2f pos = { 150, 955 };

    if (base != total) {
        text = my_stringf("%d (+ %d)", base, total - base);
    } else {
        text = my_stringf("%d", base);
    }
    size = my_strlen(text);
    pos.x -= ((float) size / 2) * 10;
    sfText_setString(game->hud->stats_texts[DEFENSE], text);
    sfText_setPosition(game->hud->stats_texts[DEFENSE], pos);
    free(text);
}

void stats_speed(game_t *game)
{
    int size = 0;
    int base = game->player->speed - 1;
    int total = get_total_speed(game->player) - 1;
    char *text = NULL;
    sfVector2f pos = { 240, 955 };

    if (base != total) {
        text = my_stringf("%d (+ %d)", base, total - base);
    } else {
        text = my_stringf("%d", base);
    }
    size = my_strlen(text);
    pos.x -= ((float) size / 2) * 10;
    sfText_setString(game->hud->stats_texts[SPEED], text);
    sfText_setPosition(game->hud->stats_texts[SPEED], pos);
    free(text);
}

void stats_health(game_t *game)
{
    int size = 0;
    int base = game->player->life;
    int total = get_total_health(game->player);
    char *text = NULL;
    sfVector2f pos = { 330, 955 };

    if (base != total) {
        text = my_stringf("%d (+ %d)", base, total - base);
    } else {
        text = my_stringf("%d", base);
    }
    size = my_strlen(text);
    pos.x -= ((float) size / 2) * 10;
    sfText_setString(game->hud->stats_texts[HEALTH], text);
    sfText_setPosition(game->hud->stats_texts[HEALTH], pos);
    free(text);
}
