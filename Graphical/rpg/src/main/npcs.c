/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** NPC management
*/

#include <stdlib.h>
#include "configuration.h"
#include "mobs.h"
#include "my_math.h"
#include "my_string.h"
#include "my.h"

static bool fetch_config(npc_t *npc, char *config_path)
{
    configuration_t *config = load_configuration(config_path, false);
    sfTexture *texts[2] = { NULL, NULL };

    if (config == NULL)
        return (false);
    texts[0] = sfTexture_createFromFile(GCVOR(config, "left", ""), NULL);
    texts[1] = sfTexture_createFromFile(GCVOR(config, "right", ""), NULL);
    if (texts[0] == NULL || texts[1] == NULL)
        return (false);
    npc->left = texts[0];
    npc->right = texts[1];
    npc->rects = my_getnbr(GCVOR(config, "rects", "1"));
    npc->name = my_strdup(GCVOR(config, "name", "Unknown"));
    npc->pos->y = (float) my_getnbr(GCVOR(config, "y", "0"));
    npc->traj->x = my_getnbr(GCVOR(config, "start-x", "0"));
    npc->traj->y = my_getnbr(GCVOR(config, "end-x", "0"));
    destroy_configuration(config);
    return (true);
}

static void init_npc_sprite(npc_t *npc)
{
    sfVector2u size = sfTexture_getSize(npc->right);
    sfIntRect rect = { 0, 0, size.x / npc->rects, size.y };

    npc->sprite = sfSprite_create();
    sfSprite_setTexture(npc->sprite, npc->right, sfTrue);
    sfSprite_setTextureRect(npc->sprite, rect);
}

npc_t *create_npc(char *config_path)
{
    npc_t *npc = malloc(sizeof(npc_t));
    sfVector2f *pos = malloc(sizeof(sfVector2f));
    sfVector2u *traj = malloc(sizeof(sfVector2i));

    if (npc == NULL || pos == NULL || traj == NULL) {
        return (NULL);
    }
    npc->pos = pos;
    npc->traj = traj;
    if (!fetch_config(npc, config_path)) {
        my_free(3, npc, pos, traj);
        return (NULL);
    }
    npc->anim = sfClock_create();
    npc->pos->x = (float) npc->traj->x;
    npc->side = true;
    init_npc_sprite(npc);
    return (npc);
}
