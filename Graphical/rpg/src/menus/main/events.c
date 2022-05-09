/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main menu event handler
*/

#include "mycsfml_buttons.h"
#include "main_menu.h"
#include "rpg.h"
#include "settings.h"
#include "how_to_play.h"

static void handle_click(game_t *game, buttons_t *button)
{
    if (button->type == BUTTON_PLAY)
        game_loop(game);
    if (button->type == BUTTON_SETTINGS)
        settings_menu(game);
    if (button->type == BUTTON_TUTORIAL)
        how_to_play(game->window);
    if (button->type == BUTTON_EXIT)
        sfRenderWindow_close(game->window);
}

void handle_main_menu_events(game_t *game)
{
    buttons_t *button = NULL;
    buttons_t *main_buttons = game->main_menu->buttons;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        change_buttons_state(game->main_menu->buttons, &event, game->window);
        button = get_clicked_button(game->window, main_buttons);
        if (button != NULL && event.type == sfEvtMouseButtonReleased) {
            sfSound_play(game->click_sound->sound);
            handle_click(game, button);
        }
    }
}
