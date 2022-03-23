/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Events
*/

#include "mycsfml_events.h"

void check_closing_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

sfBool is_click_on_sprite(sfEvent *event, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2f click = {event->mouseButton.x, event->mouseButton.y};

    return sfFloatRect_contains(&bounds, click.x, click.y);
}
