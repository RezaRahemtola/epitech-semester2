/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Mobs header
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "scenes.h"

typedef struct mob_type {
    sfTexture *texture;
    int rects;
    char *name;
    int base_hp;
    int base_attack;
    int base_defense;
    int base_speed;
    int xp;
} mob_type_t;

typedef struct mob {
    sfSprite *sprite;
    sfVector2f *pos;
    sfClock *anim;
    sfClock *move;
    mob_type_t *type;
    int health;
    int attack;
    int defense;
    int speed;
    bool drawn;
} mob_t;

typedef struct npc {
    sfTexture *left;
    sfTexture *right;
    sfSprite *sprite;
    sfClock *anim;
    sfVector2f *pos;
    sfVector2u *traj;
    int rects;
    char *name;
    bool side;
    bool drawn;
} npc_t;

mob_type_t *create_mob_type(char *config_path);
mob_t *create_mob(mob_type_t *type, int level, sfVector2f pos);
npc_t *create_npc(char *config_path);

void move_npc(npc_t *npc, map_menu_t *map);

void destroy_mob_type(mob_type_t *mob_type);
void destroy_mob(mob_t *mob);
void destroy_npc(npc_t *mob);
