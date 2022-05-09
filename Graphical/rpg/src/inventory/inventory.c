/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Functions for the inventory
*/

#include "mycsfml_buttons.h"
#include "mycsfml_elements.h"
#include "mycsfml_events.h"
#include "inventory.h"

static bool handle_inventory_events(game_t *game, inventory_t *invent,
list_t **items)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        check_closing_event(game->window, event);
        if (event.type == sfEvtMouseButtonPressed)
            invent->dragged = get_clicked_sprite(&event, *items);
        if (event.type == sfEvtMouseButtonReleased)
            drop_inventory_item(invent, items, game->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return (true);
    }
    return (false);
}

static void disp_inventory_items(list_t *items, sfRenderWindow *window)
{
    item_t *item = NULL;

    while (items != NULL) {
        item = items->data;
        if (item == NULL || item->sprite == NULL || item->texture == NULL)
            return;
        sfRenderWindow_drawSprite(window, item->sprite, NULL);
        items = items->next;
    }
}

void inventory(game_t *game, list_t **items)
{
    sfTexture *bg = sfTexture_createFromFile("assets/bg.png", NULL);
    inventory_t *invent = init_inventory();
    bool end = false;

    while (sfRenderWindow_isOpen(game->window) && !end) {
        sfRenderWindow_clear(game->window, sfBlack);
        end = handle_inventory_events(game, invent, items);
        disp_texture(bg, game->window);
        move_dragged_sprite(invent->dragged, game->window);
        sfRenderWindow_drawSprite(game->window, invent->bin, NULL);
        disp_inventory_items(*items, game->window);
        sfRenderWindow_display(game->window);
    }
    csfml_destroyer("t", bg);
}
