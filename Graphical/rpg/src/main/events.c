/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Events handling
*/

#include "rpg.h"
#include "mycsfml_events.h"

void handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        check_closing_event(game->window, event);
    }
}
