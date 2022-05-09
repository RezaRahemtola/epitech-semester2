/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** Functions for the settings menu
*/

#include "settings.h"
#include "mycsfml_events.h"
#include "mycsfml_elements.h"
#include "mycsfml_text.h"

static buttons_t *create_settings_btns(sfTexture *on, sfTexture *off,
sfTexture *back, settings_t *settings)
{
    sfVector2f fullscreen = { 400, 400 };
    sfVector2f vsync = { 1300, 400 };
    sfVector2f back_pos = { 880, 800 };
    sfTexture *full_state = (settings->fullscreen) ? on : off;
    sfTexture *vsync_state = (settings->vsync) ? off : on;
    buttons_t *list = create_button(full_state, fullscreen, BUTTON_FULLSCREEN);

    list->next = create_button(vsync_state, vsync, BUTTON_VSYNC);
    list->next->next = create_button(back, back_pos, BUTTON_BACK);
    return (list);
}

static void handle_settings_events(game_t *game, buttons_t *buttons,
sfTexture *states[2], bool *end)
{
    buttons_t *button = NULL;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        check_closing_event(game->window, event);
        change_buttons_state(buttons, &event, game->window);
        button = get_clicked_button(game->window, buttons);
        if (event.type == sfEvtMouseButtonReleased && button != NULL)
            update_settings(game, button, states, end);
    }
}

static void disp_texts(game_t *game)
{
    text_t *fulscr = text_create("Fullscreen", "assets/font.ttf", sfBlack, 45);
    text_t *vsync = text_create("Vsync", "assets/font.ttf", sfBlack, 45);

    sfText_setPosition(fulscr->text, (sfVector2f){400, 300});
    sfText_setPosition(vsync->text, (sfVector2f){1330, 300});
    sfRenderWindow_drawText(game->window, fulscr->text, NULL);
    sfRenderWindow_drawText(game->window, vsync->text, NULL);
    csfml_destroyer("TT", fulscr, vsync);
}

void settings_menu(game_t *game)
{
    sfTexture *bg = sfTexture_createFromFile("assets/bg.png", NULL);
    sfTexture *on = sfTexture_createFromFile("assets/on.png", NULL);
    sfTexture *off = sfTexture_createFromFile("assets/off.png", NULL);
    sfTexture *back = sfTexture_createFromFile("assets/back.png", NULL);
    buttons_t *buttons = create_settings_btns(on, off, back, game->settings);
    bool end = false;

    while (sfRenderWindow_isOpen(game->window) && !end) {
        sfRenderWindow_clear(game->window, sfBlack);
        handle_settings_events(game, buttons, (sfTexture *[2]){on, off}, &end);
        disp_texture(bg, game->window);
        display_buttons(buttons, game->window);
        disp_texts(game);
        sfRenderWindow_display(game->window);
    }
    destroy_buttons(buttons, sfFalse);
    csfml_destroyer("tttt", bg, on, off, back);
}
