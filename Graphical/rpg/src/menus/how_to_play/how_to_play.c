/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Functions for the how to play menu
*/

#include <stdbool.h>
#include "mycsfml_elements.h"
#include "mycsfml_events.h"
#include "how_to_play.h"

static bool handle_how_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        if (event.type == sfEvtKeyPressed)
            return (false);
    }
    return (true);
}

void how_to_play(sfRenderWindow *window)
{
    sfTexture *img = sfTexture_createFromFile("assets/how_bg.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, img, sfTrue);
    while (sfRenderWindow_isOpen(window) && handle_how_events(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    csfml_destroyer("st", sprite, img);
}
