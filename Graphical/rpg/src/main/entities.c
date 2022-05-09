/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Entities management
*/

#include "mobs.h"
#include "rpg.h"

static void init_npcs(game_t *game)
{
    char *format = "assets/npcs/%s.conf";
    char *path = NULL;
    npc_t *npc = NULL;

    game->npcs = NULL;
    for (int i = 0; game->config->npcs[i] != NULL; i++) {
        path = my_stringf(format, game->config->npcs[i]);
        if (path == NULL) {
            continue;
        }
        npc = create_npc(path);
        if (npc == NULL) {
            my_dprintf(2, "Error: Can't create %s\n", game->config->npcs[i]);
            free(path);
            continue;
        }
        my_list_add(&game->npcs, npc);
        free(path);
    }
}

void init_entities(game_t *game)
{
    char *format = "assets/enemies/%s.conf";
    char *path = NULL;
    mob_type_t *type = NULL;

    game->mob_types = NULL;
    game->mobs = NULL;
    for (int i = 0; game->config->mobs[i] != NULL; i++) {
        path = my_stringf(format, game->config->mobs[i]);
        if (path == NULL)
            continue;
        type = create_mob_type(path);
        if (type == NULL) {
            my_dprintf(2, "Error: Can't create %s\n", game->config->mobs[i]);
            free(path);
            continue;
        }
        my_list_add(&game->mob_types, type);
        free(path);
    }
    init_npcs(game);
}

void destroy_mob_type(mob_type_t *mob_type)
{
    sfTexture_destroy(mob_type->texture);
    free(mob_type->name);
    free(mob_type);
}

void destroy_mob(mob_t *mob)
{
    sfSprite_destroy(mob->sprite);
    sfClock_destroy(mob->anim);
    sfClock_destroy(mob->move);
    free(mob->pos);
    free(mob);
}

void destroy_npc(npc_t *npc)
{
    sfTexture_destroy(npc->left);
    sfTexture_destroy(npc->right);
    sfSprite_destroy(npc->sprite);
    sfClock_destroy(npc->anim);
    free(npc->pos);
    free(npc->traj);
    free(npc->name);
    free(npc);
}
