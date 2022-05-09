/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Map zooming
*/

#include "maps.h"
#include "my.h"

static void zoom_map(sfSprite *sprite, sfRenderWindow *window, float zoom)
{
    sfVector2f scale = sfSprite_getScale(sprite);
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f *center = calc_center(sprite, window);
    sfVector2f *new_center = NULL;

    scale.x += zoom;
    scale.y += zoom;
    sfSprite_setScale(sprite, scale);
    new_center = calc_center(sprite, window);
    pos.x -= (center->x - new_center->x) * (scale.x);
    pos.y -= (center->y - new_center->y) * (scale.y);
    sfSprite_setPosition(sprite, pos);
    my_free(2, center, new_center);
}

static void zoom_player(sfSprite *sprite, float zoom, float repos)
{
    sfVector2f scale = sfSprite_getScale(sprite);
    sfVector2f pos = sfSprite_getPosition(sprite);

    scale.x += zoom;
    scale.y += zoom;
    pos.x += repos;
    pos.y += repos;
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
}

static void handle_zoom_in(map_menu_t *menu, game_t *game)
{
    sfVector2f scale = sfSprite_getScale(menu->map_sprite);

    if (scale.x >= MAX_ZOOM) {
        return;
    }
    zoom_map(menu->map_sprite, game->window, 0.01f);
    zoom_map(menu->objects_sprite, game->window, 0.01f);
    zoom_player(game->player->sprite, 0.01f, -0.7f);
    refresh_offset(menu);
    refresh_mobs(game, menu);
    sfClock_restart(menu->zoom);
}

static void handle_zoom_out(map_menu_t *menu, game_t *game)
{
    sfVector2f scale = sfSprite_getScale(menu->map_sprite);

    if (scale.x <= MIN_ZOOM) {
        return;
    }
    zoom_map(menu->map_sprite, game->window, -0.01f);
    zoom_map(menu->objects_sprite, game->window, -0.01f);
    zoom_player(game->player->sprite, -0.01f, 0.7f);
    refresh_offset(menu);
    refresh_mobs(game, menu);
    sfClock_restart(menu->zoom);
}

void handle_zoom(map_menu_t *menu, game_t *game)
{
    long millis = sfClock_getElapsedTime(menu->zoom).microseconds;

    if (millis < 20000) {
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyAdd)) {
        handle_zoom_in(menu, game);
    } else if (sfKeyboard_isKeyPressed(sfKeySubtract)) {
        handle_zoom_out(menu, game);
    }
}
