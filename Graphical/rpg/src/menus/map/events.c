/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Events handling
*/

#include "hud.h"
#include "inventory.h"
#include "mycsfml_events.h"
#include "pause.h"

static void handle_click_event(sfEvent *event, game_t *game)
{
    bool on_close = is_click_on_sprite(event, game->hud->close_sprite);

    if (event->mouseButton.button == sfMouseLeft && on_close) {
        game->hud->open = !game->hud->open;
    }
}

static void handle_key_event(sfEvent *event, game_t *game, sfSound *music)
{
    if (event->key.code == sfKeyEscape) {
        pause_menu(game, music);
        return;
    }
    if (event->key.code == sfKeyI) {
        inventory(game, &(game->player->inventory));
        return;
    } else if (event->key.code == sfKeyH) {
        game->hud->open = !game->hud->open;
    }
}

void handle_map_events(game_t *game, sfSound *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (event.type == sfEvtKeyPressed) {
            add_xp(game, 1);
            handle_key_event(&event, game, music);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            handle_click_event(&event, game);
        }
        if (game->player->level == 10) {
            game->player->level = 1;
            game->player->xp = 0;
            game->playing = false;
        }
        handle_hud_events(game, &event);
    }
}
