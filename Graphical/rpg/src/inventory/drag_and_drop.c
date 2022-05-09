/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Functions to handle inventory drag and drop
*/

#include "mycsfml_events.h"
#include "inventory.h"

sfSprite *get_clicked_sprite(sfEvent *event, list_t *inventory)
{
    item_t *item = NULL;

    if (inventory == NULL)
        return (NULL);
    while (inventory != NULL) {
        item = inventory->data;
        if (item == NULL || item->texture == NULL || item->sprite == NULL)
            return (NULL);
        if (is_click_on_sprite(event, item->sprite))
            return (item->sprite);
        inventory = inventory->next;
    }
    return (NULL);
}

void move_dragged_sprite(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = {mouse.x, mouse.y};
    sfVector2u size = {0, 0};

    if (sprite != NULL) {
        size = sfTexture_getSize(sfSprite_getTexture(sprite));
        pos = (sfVector2f){pos.x - size.x / 2, pos.y - size.y / 2};
        sfSprite_setPosition(sprite, pos);
    }
}

void drop_inventory_item(inventory_t *invent, list_t **items,
sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(invent->bin);

    if (invent->dragged == NULL || items == NULL || *items == NULL)
        return;
    if (sfFloatRect_contains(&bounds, pos.x, pos.y))
        *items = NULL;
    invent->dragged = NULL;
}
