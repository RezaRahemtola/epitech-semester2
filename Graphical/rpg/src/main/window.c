/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Main game window
*/

#include <stdbool.h>
#include "main_menu.h"
#include "rpg.h"

static void resize_all(game_t *game)
{
    if (game->main_menu != NULL) {
        resize_main_menu(game->main_menu, game->window);
    }
}

sfRenderWindow *init_window(settings_t *settings)
{
    sfVideoMode mode = { settings->width, settings->height, 32 };
    sfUint32 style = sfClose;
    sfRenderWindow *window = NULL;

    if (settings->fullscreen) {
        style = style | sfFullscreen;
        mode = sfVideoMode_getDesktopMode();
    } else {
        style = style | sfResize;
    }
    window = sfRenderWindow_create(mode, "My RPG", style, NULL);
    if (window != NULL) {
        sfRenderWindow_setFramerateLimit(window, settings->framerate);
    }
    return (window);
}

bool switch_fullscreen(game_t *game, settings_t *settings)
{
    settings->fullscreen = !settings->fullscreen;

    sfRenderWindow_close(game->window);
    sfRenderWindow_destroy(game->window);
    game->window = init_window(settings);
    if (game->window != NULL) {
        resize_all(game);
        return (true);
    }
    return (false);
}
