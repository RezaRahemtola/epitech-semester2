/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** Functions for the pause menu
*/

#include "mycsfml_buttons.h"
#include "mycsfml_events.h"
#include "mycsfml_elements.h"
#include "pause.h"

static int handle_pause_events(sfRenderWindow *window, buttons_t *buttons)
{
    sfEvent event;
    buttons_t *btn = NULL;
    int type = -1;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        change_buttons_state(buttons, &event, window);
        if (event.type == sfEvtMouseButtonReleased)
            btn = get_clicked_button(window, buttons);
        if (btn != NULL && type == -1)
            type = btn->type;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            type = PAUSE_RESUME;
    }
    return (type);
}

static buttons_t *create_pause_buttons(void)
{
    sfTexture *exit = sfTexture_createFromFile("assets/exit.png", NULL);
    sfTexture *menu = sfTexture_createFromFile("assets/start_menu.png", NULL);
    sfTexture *resume = sfTexture_createFromFile("assets/resume.png", NULL);
    sfTexture *save = sfTexture_createFromFile("assets/save.png", NULL);
    buttons_t *list = create_button(exit, (sfVector2f){850, 800}, PAUSE_EXIT);
    sfVector2f resume_pos = {820, 200};

    list->next = create_button(menu, (sfVector2f){820, 600}, PAUSE_MENU);
    list->next->next = create_button(save, (sfVector2f){850, 400}, PAUSE_SAVE);
    list->next->next->next = create_button(resume, resume_pos, PAUSE_RESUME);
    return (list);
}

int pause_menu(game_t *game, sfSound *music)
{
    int clicked = -1;
    buttons_t *buttons = create_pause_buttons();
    sfTexture *bg = sfTexture_createFromFile("assets/bg_pause.png", NULL);

    sfSound_pause(music);
    while (sfRenderWindow_isOpen(game->window) && clicked == -1) {
        sfRenderWindow_clear(game->window, sfBlack);
        disp_texture(bg, game->window);
        display_buttons(buttons, game->window);
        sfRenderWindow_display(game->window);
        clicked = handle_pause_events(game->window, buttons);
    }
    sfSound_play(music);
    csfml_destroyer("tb", bg, buttons);
    if (clicked == PAUSE_EXIT)
        sfRenderWindow_close(game->window);
    if (clicked == PAUSE_MENU)
        game->playing = false;
    return (clicked);
}
