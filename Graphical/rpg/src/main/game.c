/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Game loop
*/

#include "hud.h"
#include "maps.h"

void game_loop(game_t *game)
{
    char *map = "assets/maps/map_begin.png";
    char *conf = "assets/maps/map_begin.conf";
    char *text = "assets/maps/map_begin.txt";
    char *offset = "assets/maps/map_begin_offset.png";
    char *objects = "assets/maps/map_begin_objects.png";
    char *files[5] = { map, conf, text, offset, objects };

    game->player->health = (float) game->config->def_hp;
    game->player->max_health = (float) game->config->def_hp;
    game->player->points = game->config->def_points;
    listen_health(game);
    listen_stats(game);
    display_map(game, files);
}
