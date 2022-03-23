/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions to handle events
*/

#include <stdbool.h>
#include "mycsfml_all.h"

buttons_t *handle_menu_events(sfRenderWindow *window, buttons_t *buttons)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        change_buttons_state(buttons, &event, window);
        if (event.type == sfEvtMouseButtonReleased)
            return (get_clicked_button(buttons, &event));
    }
    return (NULL);
}

bool handle_key_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        if (event.type == sfEvtKeyPressed)
            return (true);
    }
    return (false);
}
