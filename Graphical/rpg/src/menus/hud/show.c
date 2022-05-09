/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** HUD appear/disappear
*/

#include <SFML/Graphics.h>
#include "hud.h"

void draw_hud(hud_t *hud, game_t *game)
{
    if (!hud->open) {
        return;
    }
    sfRenderWindow_drawSprite(game->window, hud->box_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, hud->close_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, hud->icon_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, hud->level_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, hud->points_sprite, NULL);
    draw_health_bar(hud->health, game);
    draw_xp_bar(hud->xp, game);
    sfRenderWindow_drawText(game->window, hud->health_text, NULL);
    sfRenderWindow_drawText(game->window, hud->xp_text, NULL);
    sfRenderWindow_drawText(game->window, hud->level_text, NULL);
    sfRenderWindow_drawText(game->window, hud->points_text, NULL);
    display_buttons(hud->stats_buttons, game->window);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(game->window, hud->stats_texts[i], NULL);
    }
}

void handle_hud_events(game_t *game, sfEvent *event)
{
    int *stats[4] = { &game->player->attack, &game->player->defense, \
    &game->player->speed, &game->player->life };
    buttons_t *button = NULL;

    change_buttons_state(game->hud->stats_buttons, event, game->window);
    if (event->type != sfEvtMouseButtonPressed) {
        return;
    }
    button = get_clicked_button(game->window, game->hud->stats_buttons);
    if (button == NULL || game->player->points < 1) {
        return;
    }
    *stats[button->type] += 1;
    game->player->points -= 1;
    listen_stats(game);
}
