/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions for the pause menu of the game
*/

#include "defender.h"

static buttons_t *create_pause_buttons(void)
{
    sfTexture *resume = sfTexture_createFromFile("assets/resume.png", NULL);
    sfTexture *exit = sfTexture_createFromFile("assets/exit.png", NULL);
    sfTexture *start = sfTexture_createFromFile("assets/start_menu.png", NULL);
    buttons_t *list = NULL;

    list = create_button(resume, (sfVector2f){800, 350}, BUTTON_RESUME);
    list->next = create_button(exit, (sfVector2f){865, 475}, BUTTON_EXIT);
    list->next->next = create_button(start, (sfVector2f){820, 600},
    BUTTON_START_MENU);
    return (list);
}

bool pause_menu(sfRenderWindow *window)
{
    framebuffer_t *fb = framebuffer_create(WIDTH, HEIGHT, 32);
    sfTexture *texture = sfTexture_create(WIDTH, HEIGHT);
    buttons_t *buttons = create_pause_buttons();
    buttons_t *clicked = NULL;
    int type = -1;

    framebuffer_fill(fb, (sfColor){0, 0, 0, 100});
    disp_framebuffer(texture, fb, window);
    while (sfRenderWindow_isOpen(window) && clicked == NULL) {
        display_buttons(buttons, window);
        sfRenderWindow_display(window);
        clicked = handle_menu_events(window, buttons);
    }
    type = clicked == NULL ? -1 : clicked->type;
    if (type == BUTTON_EXIT)
        sfRenderWindow_close(window);
    csfml_destroyer("ftb", fb, texture, buttons);
    return (type == BUTTON_START_MENU);
}
