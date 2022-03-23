/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Start menu functions
*/

#include "defender.h"

static void how_to_play(info_t *info, sfRenderWindow *window,
textures_t *textures)
{
    sfTexture *img = sfTexture_createFromFile("assets/how_bg.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, img, sfTrue);
    while (sfRenderWindow_isOpen(window) && !handle_key_event(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    csfml_destroyer("ts", img, sprite);
    start_menu(info, window, textures);
}

static buttons_t *create_start_buttons(textures_t *t)
{
    sfVector2f pos_p = { 875, 400 };
    sfVector2f pos_e = { 875, 700 };
    sfVector2f pos_h = { 800, 550 };
    buttons_t *list = create_button(t->play, pos_p, BUTTON_PLAY);

    list->next = create_button(t->exit, pos_e, BUTTON_EXIT);
    list->next->next = create_button(t->how_play, pos_h, BUTTON_HOW_PLAY);
    return (list);
}

void start_menu(info_t *info, sfRenderWindow *window, textures_t *textures)
{
    buttons_t *buttons = create_start_buttons(textures);
    buttons_t *clicked = NULL;
    sfTexture *bg = sfTexture_createFromFile("assets/start_bg.png", NULL);
    int type = -1;

    while (sfRenderWindow_isOpen(window) && clicked == NULL) {
        clicked = handle_menu_events(window, buttons);
        sfRenderWindow_clear(window, sfBlack);
        disp_texture(bg, window);
        display_buttons(buttons, window);
        sfRenderWindow_display(window);
    }
    type = clicked == NULL ? -1 : clicked->type;
    destroy_buttons(buttons, sfFalse);
    sfTexture_destroy(bg);
    if (type == BUTTON_PLAY)
        play(info, window, textures);
    if (type == BUTTON_HOW_PLAY)
        how_to_play(info, window, textures);
}
