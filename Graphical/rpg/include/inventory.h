/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Inventory
*/

#pragma once

#include "rpg.h"

typedef struct inventory_s {
    sfSprite *dragged;
    sfSprite *bin;
    buttons_t *buttons;
} inventory_t;

// Core
void inventory(game_t *game, list_t **items);

// Drag and drop
sfSprite *get_clicked_sprite(sfEvent *event, list_t *inventory);
void drop_inventory_item(inventory_t *invent, list_t **items,
sfRenderWindow *window);
void move_dragged_sprite(sfSprite *sprite, sfRenderWindow *window);

// Init and destroy
inventory_t *init_inventory(void);
item_t *create_inventory_item(char *texture_path, int amount);
