/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Shots management
*/

#include <stdio.h>
#include "defender.h"

static void init_tower(tower_t *tower, tower_type_t *type, float x, float y)
{
    tower->type = type;
    tower->sprite = sfSprite_create();
    tower->range = sfCircleShape_create();
    tower->clock = sfClock_create();
    tower->shot = sfClock_create();
    tower->pos = malloc(sizeof(sfVector2f));
    tower->pos->x = x + 0.5f;
    tower->pos->y = y + 0.5f;
    tower->next = NULL;
}

static void manage_sprite(tower_t *tower, info_t *info)
{
    sfVector2i max = { my_strlen(info->map[0]), my_arraylen(info->map) };
    sfVector2f scale = { 0, 0 };
    sfVector2f origin = { (float) 88 / 2, (float) 159 / 1.5f };
    float nx = tower->pos->x * info->scale->x;
    float ny = tower->pos->y * info->scale->y;
    sfVector2f pos = { nx, ny };

    scale.x = (float) WIDTH / (float) max.x / (float) 88 * 0.75f;
    scale.y = (float) HEIGHT / (float) max.y / (float) 88 * 0.75f;
    sfSprite_setTextureRect(tower->sprite, (sfIntRect) {0, 0, 88, 159});
    sfSprite_setTexture(tower->sprite, tower->type->texture, sfFalse);
    sfSprite_setOrigin(tower->sprite, origin);
    sfSprite_setScale(tower->sprite, scale);
    sfSprite_setPosition(tower->sprite, pos);
}

static void manage_circle(tower_t *tower, info_t *info)
{
    sfVector2i max = { my_strlen(info->map[0]), my_arraylen(info->map) };
    sfVector2f scale = { 0, 0 };
    sfColor color = { 0, 0, 0, 0 };
    float center = (float) tower->type->range * 40;
    sfVector2f origin = { center, center };
    float nx = tower->pos->x * info->scale->x;
    float ny = tower->pos->y * info->scale->y;
    sfVector2f pos = { nx, ny };

    scale.x = (float) WIDTH / (float) max.x / (float) 88 * 0.75f;
    scale.y = (float) HEIGHT / (float) max.y / (float) 88 * 0.75f;
    sfCircleShape_setRadius(tower->range, (float) tower->type->range * 40);
    sfCircleShape_setScale(tower->range, scale);
    sfCircleShape_setFillColor(tower->range, color);
    sfCircleShape_setOutlineColor(tower->range, sfRed);
    sfCircleShape_setOutlineThickness(tower->range, 2);
    sfCircleShape_setOrigin(tower->range, origin);
    sfCircleShape_setPosition(tower->range, pos);
}

void create_tower(sfVector2f *vector, const sfTexture *texture,
game_t *game, info_t *info)
{
    sfVector2i max = { my_strlen(info->map[0]), my_arraylen(info->map) };
    int x = vector->x / info->scale->x;
    int y = vector->y / info->scale->y;
    tower_t *tower = NULL;
    tower_type_t *type = find_type(texture, info);

    if (x < 0 || x >= max.x || y < 0 || y >= max.y || type == NULL)
        return;
    if (game->gold - type->cost < 0)
        return;
    if (info->map[y][x] != CHAR_FLOOR || find_tower(game->towers, x, y))
        return;
    tower = malloc(sizeof(tower_t));
    init_tower(tower, type, (float) x, (float) y);
    game->gold -= type->cost;
    game->spent += type->cost;
    manage_sprite(tower, info);
    manage_circle(tower, info);
    add_tower(&game->towers, tower);
}
