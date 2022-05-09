/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Experience management
*/

#include "hud.h"
#include "rpg.h"

int get_needed_xp(game_t *game)
{
    int level = game->player->level;

    if (level < 1 || level > game->config->level_max) {
        return (-1);
    }
    return (game->config->xp[level - 1]);
}

void add_xp(game_t *game, int xp)
{
    int needed = get_needed_xp(game);

    game->player->xp += xp;
    if (game->player->xp >= needed && needed != -1) {
        game->player->level += 1;
        game->player->points += game->config->points[game->player->level - 1];
        game->player->xp -= needed;
        listen_stats(game);
        listen_level(game);
    }
    listen_xp(game);
}
