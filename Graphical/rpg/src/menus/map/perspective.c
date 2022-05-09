/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Perspective for collisions
*/

#include "maps.h"
#include "rpg.h"

static void draw_npcs_before(game_t *game)
{
    list_t *npc = game->npcs;
    npc_t *tmp = NULL;

    while (npc != NULL) {
        tmp = npc->data;
        tmp->drawn = false;
        if (game->player->map_y - 2 > tmp->pos->y) {
            sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
            tmp->drawn = true;
        }
        npc = npc->next;
    }
}

void draw_mobs_before(game_t *game)
{
    list_t *mob = game->mobs;
    mob_t *tmp = NULL;

    while (mob != NULL) {
        tmp = mob->data;
        tmp->drawn = false;
        if (game->player->map_y > tmp->pos->y) {
            sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
            tmp->drawn = true;
        }
        mob = mob->next;
    }
    draw_npcs_before(game);
}
