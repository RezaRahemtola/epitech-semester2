/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** NPC movement
*/

#include "mycsfml_elements.h"
#include "maps.h"
#include "mobs.h"

void move_npc(npc_t *npc, map_menu_t *menu)
{
    sfVector2u size = sfTexture_getSize(npc->left);
    sfIntRect rect = { 0, 0, size.x / npc->rects, size.y };

    if (npc->side) {
        npc->pos->x += 0.2f;
        if (npc->pos->x >= npc->traj->y) {
            npc->side = false;
            sfSprite_setTexture(npc->sprite, npc->left, sfTrue);
            sfSprite_setTextureRect(npc->sprite, rect);
        }
        refresh_npc(npc, menu);
        return;
    }
    npc->pos->x -= 0.2f;
    if (npc->pos->x <= npc->traj->x) {
        npc->side = true;
        sfSprite_setTexture(npc->sprite, npc->right, sfTrue);
        sfSprite_setTextureRect(npc->sprite, rect);
    }
    refresh_npc(npc, menu);
}
