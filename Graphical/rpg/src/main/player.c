/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Player management
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "inventory.h"
#include "player.h"

static void init_player_stats(player_t *player)
{
    player->points = 0;
    player->level = 1;
    player->xp = 0;
    player->max_health = 100.0f;
    player->health = 100.0f;
    player->attack = 1;
    player->defense = 1;
    player->speed = 1;
    player->life = 0;
    player->map_x = -1;
    player->map_y = -1;
}

static list_t *init_player_inventory(void)
{
    list_t *inventory = NULL;
    item_t *item = create_inventory_item("assets/medkit.png", 1);

    my_list_add(&inventory, item);
    return (inventory);
}

bool init_player(player_t *player)
{
    char *textures[4] = { "up", "down", "left", "right" };
    char *path = NULL;

    init_player_stats(player);
    player->inventory = init_player_inventory();
    player->textures = malloc(sizeof(sfTexture *) * 5);
    if (player->textures == NULL || player->inventory == NULL) {
        return (false);
    }
    player->sprite = sfSprite_create();
    for (int i = 0; i < 4; i++) {
        path = my_stringf("assets/player/%s.png", textures[i]);
        player->textures[i] = sfTexture_createFromFile(path, NULL);
        free(path);
        if (player->textures[i] == NULL) {
            return (false);
        }
    }
    player->textures[4] = NULL;
    return (true);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    for (int i = 0; player->textures[i] != NULL; i++) {
        sfTexture_destroy(player->textures[i]);
    }
    free(player->textures);
    free(player);
}
