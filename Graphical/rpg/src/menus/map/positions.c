/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Collisions handling
*/

#include "maps.h"

sfVector2f *calc_center(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2f sc = sfSprite_getScale(sprite);
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2u ts = sfRenderWindow_getSize(window);
    sfVector2f *center = malloc(sizeof(sfVector2f));

    center->x = (ts.x / 2 - pos.x) / sc.x;
    center->y = (ts.y / 2 - pos.y) / sc.y;
    return (center);
}

void set_center(sfSprite *sprite, sfRenderWindow *window, sfVector2f *center)
{
    sfVector2f sc = sfSprite_getScale(sprite);
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2u ts = sfRenderWindow_getSize(window);

    pos.x = ts.x / 2 - center->x * sc.x;
    pos.y = ts.y / 2 - center->y * sc.y;
    sfSprite_setPosition(sprite, pos);
}

void refresh_position(game_t *game, map_menu_t *menu)
{
    sfVector2u size = sfTexture_getSize(menu->map_texture);
    sfVector2f *center = calc_center(menu->map_sprite, game->window);
    sfVector2f pos = { 0, 0 };

    pos.x = (float) center->x / (float) size.x * (float) menu->map_size->x;
    pos.y = (float) center->y / (float) size.y * (float) menu->map_size->y;
    free(center);
    game->player->map_x = pos.x;
    game->player->map_y = pos.y;
}

void set_position(game_t *game, map_menu_t *menu, sfVector2f *pos)
{
    sfVector2f center = { 0, 0 };
    sfVector2u ts = sfTexture_getSize(menu->map_texture);

    center.x = (float) ts.x / (float) menu->map_size->x * (float) pos->x;
    center.y = (float) ts.y / (float) menu->map_size->y * (float) pos->y;
    set_center(menu->map_sprite, game->window, &center);
    set_center(menu->objects_sprite, game->window, &center);
    game->player->map_x = pos->x;
    game->player->map_y = pos->y;
}

void set_default_position(game_t *game, map_menu_t *menu)
{
    sfVector2f def = { 0, 0 };

    def.x = (float) menu->map_default_pos->x + 0.5f;
    def.y = (float) menu->map_default_pos->y + 0.5f;
    set_position(game, menu, &def);
}
