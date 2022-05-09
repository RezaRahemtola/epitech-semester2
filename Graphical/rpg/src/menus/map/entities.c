/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Entities management
*/

#include "mycsfml_elements.h"
#include "my_list.h"
#include "rpg.h"

void refresh_mob(mob_t *mob, map_menu_t *menu)
{
    sfVector2f pos = sfSprite_getPosition(menu->map_sprite);
    sfVector2f scale = sfSprite_getScale(menu->map_sprite);
    sfVector2u size = sfTexture_getSize(menu->map_texture);
    float x = (float) size.x / (float) menu->map_size->x * scale.x;
    float y = (float) size.y / (float) menu->map_size->y * scale.y;

    pos.x += mob->pos->x * x;
    pos.y += mob->pos->y * y;
    scale.x += 1;
    scale.y += 1;
    sfSprite_setPosition(mob->sprite, pos);
    sfSprite_setScale(mob->sprite, scale);
}

void refresh_npc(npc_t *npc, map_menu_t *menu)
{
    sfVector2f pos = sfSprite_getPosition(menu->map_sprite);
    sfVector2f scale = sfSprite_getScale(menu->map_sprite);
    sfVector2u size = sfTexture_getSize(menu->map_texture);
    sfVector2u npc_size = sfTexture_getSize(npc->left);
    float x = (float) size.x / (float) menu->map_size->x * scale.x;
    float y = (float) size.y / (float) menu->map_size->y * scale.y;

    pos.x += npc->pos->x * x;
    pos.y += npc->pos->y * y;
    scale.x += 80.0f / ((float) npc_size.x / (float) npc->rects);
    scale.y += 80.0f / (float) npc_size.y;
    sfSprite_setPosition(npc->sprite, pos);
    sfSprite_setScale(npc->sprite, scale);
}

void refresh_mobs(game_t *game, map_menu_t *menu)
{
    list_t *mob = game->mobs;
    list_t *npc = game->npcs;
    mob_t *tmp_mob = NULL;
    npc_t *tmp_npc = NULL;

    while (mob != NULL) {
        tmp_mob = mob->data;
        refresh_mob(tmp_mob, menu);
        mob = mob->next;
    }
    while (npc != NULL) {
        tmp_npc = npc->data;
        refresh_npc(tmp_npc, menu);
        npc = npc->next;
    }
}

static void draw_npcs(game_t *game, map_menu_t *menu)
{
    long millis = 0;
    sfVector2u size;
    list_t *npc = game->npcs;
    npc_t *tmp = NULL;

    while (npc != NULL) {
        tmp = npc->data;
        if (!tmp->drawn) {
            sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        }
        millis = sfClock_getElapsedTime(tmp->anim).microseconds;
        if (millis > 200000) {
            move_npc(tmp, menu);
            size = sfTexture_getSize(tmp->left);
            move_spriterect(tmp->sprite, size.x / tmp->rects);
            sfClock_restart(tmp->anim);
        }
        npc = npc->next;
    }
}

void draw_mobs(game_t *game, map_menu_t *menu)
{
    long millis = 0;
    sfVector2u size;
    list_t *mob = game->mobs;
    mob_t *tmp = NULL;

    while (mob != NULL) {
        tmp = mob->data;
        if (!tmp->drawn) {
            sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        }
        millis = sfClock_getElapsedTime(tmp->anim).microseconds;
        if (millis > 1000000 / tmp->speed) {
            size = sfTexture_getSize(tmp->type->texture);
            move_spriterect(tmp->sprite, size.x / tmp->type->rects);
            sfClock_restart(tmp->anim);
        }
        mob = mob->next;
    }
    draw_npcs(game, menu);
}
