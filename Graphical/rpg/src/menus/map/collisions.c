/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Collisions management
*/

#include "maps.h"

static bool check_npc_collisions(game_t *game, sfVector2f *check)
{
    float dist_x = 0;
    float dist_y = 0;
    list_t *npc = game->npcs;
    npc_t *tmp = NULL;

    while (npc != NULL) {
        tmp = npc->data;
        dist_x = (check->x - 2) - (tmp->pos->x);
        dist_y = (check->y - 2) - (tmp->pos->y);
        if (dist_x <= 0.5 && dist_x >= -0.5 && dist_y <= 0.5 && dist_y >= -0.5)
            return (false);
        npc = npc->next;
    }
    return (true);
}

static bool check_mobs_collisions(game_t *game, sfVector2f *check)
{
    float dist_x = 0;
    float dist_y = 0;
    list_t *mob = game->mobs;
    npc_t *tmp = NULL;

    while (mob != NULL) {
        tmp = mob->data;
        dist_x = (check->x - 2) - (tmp->pos->x);
        dist_y = (check->y - 2) - (tmp->pos->y);
        if (dist_x <= 0.5 && dist_x >= -0.5 && dist_y <= 0.5 && dist_y >= -0.5)
            return (false);
        mob = mob->next;
    }
    return (check_npc_collisions(game, check));
}

bool check_collisions(game_t *game, map_menu_t *menu, sfVector2f pos, \
float speed)
{
    float posi = 0.25f * speed;
    float nega = -0.25f * speed;
    float x = 0;
    float y = 0;
    int x_pos = 0;
    int y_pos = 0;
    bool mobs = false;
    sfVector2f check = { 0, 0 };

    x = (pos.x == 0 ? 0 : (pos.x > 0 ? posi : nega)) + game->player->map_x;
    y = (pos.y == 0 ? 0 : (pos.y > 0 ? posi : nega)) + game->player->map_y;
    x_pos = (int) x;
    y_pos = (int) y;
    check.x = x;
    check.y = y;
    mobs = check_mobs_collisions(game, &check);
    return (menu->map_collisions[y_pos][x_pos] != '.' && mobs);
}
