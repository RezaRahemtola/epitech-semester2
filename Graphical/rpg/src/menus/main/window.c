/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main menu
*/

#include <stdlib.h>
#include "main_menu.h"

static void draw_content(sfRenderWindow *window, main_menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->bg_sprite, NULL);
    display_buttons(menu->buttons, window);
    for (int i = 0; menu->texts[i] != NULL; i++) {
        sfRenderWindow_drawText(window, menu->texts[i], NULL);
    }
}

void main_menu(game_t *game)
{
    resize_main_menu(game->main_menu, game->window);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        handle_main_menu_events(game);
        draw_content(game->window, game->main_menu);
        sfRenderWindow_display(game->window);
    }
}
