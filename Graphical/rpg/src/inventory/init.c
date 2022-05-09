/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Functions to initialize the inventory
*/

#include <stdlib.h>
#include "mycsfml_elements.h"
#include "inventory.h"

item_t *create_inventory_item(char *texture_path, int amount)
{
    item_t *item = malloc(sizeof(item_t));
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite *sprite = create_sprite(texture, (sfVector2f) {0, 0});

    if (item == NULL || texture == NULL || sprite == NULL)
        return (NULL);
    item->sprite = sprite;
    item->texture = texture;
    item->amount = amount;
    return (item);
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfTexture *bin = sfTexture_createFromFile("assets/bin.png", NULL);

    if (inventory == NULL)
        return (NULL);
    inventory->bin = create_sprite(bin, (sfVector2f){1600, 750});
    inventory->dragged = NULL;
    return (inventory);
}
