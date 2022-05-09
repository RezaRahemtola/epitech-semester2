/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Movement handling
*/

#include "maps.h"
#include "mycsfml_all.h"

void refresh_offset(map_menu_t *menu)
{
    sfVector2f pos = sfSprite_getPosition(menu->map_sprite);
    sfVector2f scale = sfSprite_getScale(menu->map_sprite);

    pos.x -= (float) menu->offset_pos->x * scale.x;
    pos.y -= (float) menu->offset_pos->y * scale.y;
    sfSprite_setPosition(menu->offset_sprite, pos);
    sfSprite_setScale(menu->offset_sprite, scale);
}

static directions_t get_direction(const bool array[4])
{
    for (int i = 0; i < 4; i++) {
        if (array[i]) {
            return i;
        }
    }
    return (0);
}

static void refresh_player(game_t *game, map_menu_t *menu, const bool array[4])
{
    directions_t dir = get_direction(array);
    const sfTexture *old = sfSprite_getTexture(game->player->sprite);
    sfTexture *new = game->player->textures[dir];
    sfVector2u size = sfTexture_getSize(new);
    long millis = sfClock_getElapsedTime(menu->anim).microseconds;
    sfIntRect rect = { 0, 0, size.x / 4, size.y };

    if (old != new) {
        sfSprite_setTexture(game->player->sprite, new, sfTrue);
        sfSprite_setTextureRect(game->player->sprite, rect);
    }
    if (millis > 100000) {
        move_spriterect(game->player->sprite, size.x / 4);
        sfClock_restart(menu->anim);
    }
}

static bool move_player(game_t *game, map_menu_t *menu, float x, float y)
{
    int mult = get_total_speed(game->player);
    float multiplier = 1.0f + (float) (mult - 1) * 5 / 100.0f;
    sfVector2f speed = { x, y };
    sfVector2f pos = sfSprite_getPosition(menu->map_sprite);
    sfVector2f zoom = sfSprite_getScale(menu->map_sprite);

    if (!check_collisions(game, menu, speed, multiplier)) {
        return (false);
    }
    pos.x += x * zoom.x * (5 * multiplier) * -1;
    pos.y += y * zoom.y * (5 * multiplier) * -1;
    sfSprite_setPosition(menu->map_sprite, pos);
    sfSprite_setPosition(menu->objects_sprite, pos);
    refresh_offset(menu);
    refresh_mobs(game, menu);
    return (true);
}

bool handle_movement(map_menu_t *menu, game_t *game)
{
    if (sfClock_getElapsedTime(menu->move).microseconds < 20000)
        return (false);
    bool up = sfKeyboard_isKeyPressed(sfKeyUp);
    bool down = sfKeyboard_isKeyPressed(sfKeyDown);
    bool left = sfKeyboard_isKeyPressed(sfKeyLeft);
    bool right = sfKeyboard_isKeyPressed(sfKeyRight);
    bool moved = false;
    bool array[4] = { up, down, left, right };
    if ((up || down) && !(up && down))
        moved = move_player(game, menu, 0, up ? -0.5f : 0.5f);
    if ((left || right) && !(left && right))
        moved = move_player(game, menu, left ? -0.5f : 0.5f, 0) || moved;
    if (moved) {
        refresh_player(game, menu, array);
        sfClock_restart(menu->move);
        refresh_position(game, menu);
        return (true);
    }
    return (false);
}
