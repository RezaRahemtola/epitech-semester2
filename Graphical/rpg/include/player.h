/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Player management header
*/

#pragma once

#include <SFML/Graphics.h>
#include "my_list.h"

typedef struct item {
    sfSprite *sprite;
    sfTexture *texture;
    int amount;
    int attack;
    int defense;
    int speed;
    int health;
} item_t;

typedef struct player {
    sfTexture **textures;
    sfSprite *sprite;
    int points;
    int level;
    int xp;
    float max_health;
    float health;
    int attack;
    int defense;
    int speed;
    int life;
    list_t *inventory;
    float map_x;
    float map_y;
} player_t;

bool init_player(player_t *player);
void destroy_player(player_t *player);

int get_total_attack(player_t *player);
int get_total_defense(player_t *player);
int get_total_speed(player_t *player);
int get_total_health(player_t *player);
