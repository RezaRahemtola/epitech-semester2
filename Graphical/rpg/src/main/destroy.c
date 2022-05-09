/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Functions to destroy structures
*/

#include <stdlib.h>
#include "hud.h"
#include "main_menu.h"

static void destroy_config(game_t *game)
{
    my_free_arrays(1, game->config->mobs);
    my_free_arrays(1, game->config->npcs);
    free(game->config->xp);
    free(game->config->points);
    free(game->config);
}

static void free_npc_list(list_t *list)
{
    list_t *current = list;
    list_t *tmp = NULL;
    npc_t *npc = NULL;

    while (current != NULL) {
        tmp = current->next;
        npc = current->data;
        destroy_npc(npc);
        free(current);
        current = tmp;
    }
}

static void free_mob_types_list(list_t *list)
{
    list_t *current = list;
    list_t *tmp = NULL;
    mob_type_t *type = NULL;

    while (current != NULL) {
        tmp = current->next;
        type = current->data;
        destroy_mob_type(type);
        free(current);
        current = tmp;
    }
}

static void free_mob_list(list_t *list)
{
    list_t *current = list;
    list_t *tmp = NULL;
    mob_t *mob = NULL;

    while (current != NULL) {
        tmp = current->next;
        mob = current->data;
        destroy_mob(mob);
        free(current);
        current = tmp;
    }
}

void destroy_game_content(game_t *game)
{
    free_main_menu(game->main_menu);
    sfRenderWindow_destroy(game->window);
    destroy_player(game->player);
    destroy_hud(game->hud);
    sound_destroy(game->click_sound);
    free_mob_types_list(game->mob_types);
    free_mob_list(game->mobs);
    free_npc_list(game->npcs);
    destroy_config(game);
    free(game->settings);
}
