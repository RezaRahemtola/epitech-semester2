/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Enemy and towers constructors
*/

#include "defender.h"

static enemy_type_t *new_enemy(char *texture, int health, int dmg, int speed)
{
    enemy_type_t *type = malloc(sizeof(enemy_type_t));

    type->texture = sfTexture_createFromFile(texture, NULL);
    type->health = health;
    type->damage = dmg;
    type->speed = speed;
    return (type);
}

static tower_type_t *new_tower(char *texture, int *info)
{
    tower_type_t *type = malloc(sizeof(tower_type_t));

    type->texture = sfTexture_createFromFile(texture, NULL);
    type->dmg_type = info[0];
    type->damage = info[1];
    type->cost = info[2];
    type->range = info[3];
    type->speed = info[4];
    return (type);
}

void generate_types(info_t *i)
{
    int type_one[5] = { SINGLE_DMG, 15, 100, 8, 5 };
    int type_two[5] = { ZONE_DMG, 10, 500, 4, 2 };
    int type_three[5] = { SLOW, 2, 250, 5, 3 };
    int type_four[5] = { MID, 50, 200, 6, 3 };

    i->enemy_types = malloc(sizeof(enemy_type_t *) * 5);
    i->enemy_types[0] = new_enemy("assets/blue_ene.png", 70, 10, 5);
    i->enemy_types[1] = new_enemy("assets/red_ene.png", 90, 8, 2);
    i->enemy_types[2] = new_enemy("assets/green_ene.png", 60, 15, 8);
    i->enemy_types[3] = new_enemy("assets/purple_ene.png", 40, 12, 15);
    i->enemy_types[4] = NULL;
    i->tower_types = malloc(sizeof(tower_type_t *) * 5);
    i->tower_types[0] = new_tower("assets/fire_tow.png", type_one);
    i->tower_types[1] = new_tower("assets/poison_tow.png", type_two);
    i->tower_types[2] = new_tower("assets/ice_tow.png", type_three);
    i->tower_types[3] = new_tower("assets/mid_tow.png", type_four);
    i->tower_types[4] = NULL;
}

void free_types(info_t *info)
{
    for (int i = 0; info->enemy_types[i] != NULL; i++) {
        sfTexture_destroy(info->enemy_types[i]->texture);
        free(info->enemy_types[i]);
    }
    free(info->enemy_types);
    for (int i = 0; info->tower_types[i] != NULL; i++) {
        sfTexture_destroy(info->tower_types[i]->texture);
        free(info->tower_types[i]);
    }
    free(info->tower_types);
}

tower_type_t *find_type(const sfTexture *texture, info_t *info)
{
    for (int i = 0; info->tower_types[i] != NULL; i++) {
        if (info->tower_types[i]->texture == texture) {
            return info->tower_types[i];
        }
    }
    return (NULL);
}
