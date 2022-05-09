/*
** EPITECH PROJECT, 2022
** CSFML utils
** File description:
** Functions to manipulate buttons
*/

#include <stdlib.h>
#include "mycsfml_buttons.h"
#include "mycsfml_window.h"

void change_buttons_state(buttons_t *button, sfEvent *event,
sfRenderWindow *window)
{
    sfBool on_sprite = sfFalse;
    sfIntRect rect;

    while (button != NULL) {
        on_sprite = is_mouse_on_sprite(window, button->sprite, 1920, 1080);
        rect = sfSprite_getTextureRect(button->sprite);
        rect.left = 0;
        if (event->type == sfEvtMouseMoved && on_sprite)
            rect.left = rect.width * 1;
        if (event->type == sfEvtMouseButtonPressed && on_sprite)
            rect.left = rect.width * 2;
        sfSprite_setTextureRect(button->sprite, rect);
        button = button->next;
    }
}

buttons_t *create_button(sfTexture *texture, sfVector2f pos, int type)
{
    buttons_t *button = malloc(sizeof(buttons_t));
    sfSprite *sprite = sfSprite_create();
    sfVector2u size = sfTexture_getSize(texture);
    sfIntRect rect = {0, 0, size.x / 3, size.y};

    if (sprite == NULL)
        return (NULL);
    if (texture == NULL)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    button->type = type;
    button->texture = texture;
    button->sprite = sprite;
    button->pos = pos;
    button->next = NULL;
    sfSprite_setPosition(button->sprite, button->pos);
    return (button);
}

void destroy_buttons(buttons_t *head, sfBool destroy_texture)
{
    buttons_t *current = head;
    buttons_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        if (destroy_texture)
            sfTexture_destroy(tmp->texture);
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
}

void display_buttons(buttons_t *list, sfRenderWindow *window)
{
    while (list != NULL) {
        sfRenderWindow_drawSprite(window, list->sprite, NULL);
        list = list->next;
    }
}

buttons_t *get_clicked_button(sfRenderWindow *window, buttons_t *buttons)
{
    while (buttons != NULL) {
        if (is_mouse_on_sprite(window, buttons->sprite, 1920, 1080))
            return (buttons);
        buttons = buttons->next;
    }
    return (NULL);
}
