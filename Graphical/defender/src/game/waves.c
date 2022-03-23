/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Enemy waves management
*/

#include "defender.h"

static void enemy_move(enemy_t *enemy, game_t *game, info_t *info)
{
    sfVector2f vec = { 0, 0 };
    int up = rand() % 20;
    double dx = 0;
    double dy = 0;

    if (up == 0 && enemy->speed < enemy->type->speed) {
        enemy->speed += 1;
    }
    enemy->pos->x += enemy->dir->x;
    enemy->pos->y += enemy->dir->y;
    vec.x = enemy->pos->y * info->scale->x;
    vec.y = enemy->pos->x * info->scale->y;
    sfSprite_setPosition(enemy->sprite, vec);
    dx = (double) enemy->pos->x - (int) enemy->pos->x;
    dy = (double) enemy->pos->y - (int) enemy->pos->y;
    if (dx > 0.45 && dx < 0.55 && dy > 0.45 && dy < 0.55) {
        update_direction(enemy, game, info);
    }
}

static void manage_sprite(enemy_t *enemy, game_t *game, info_t *info)
{
    sfVector2i max = { my_strlen(info->map[0]), my_arraylen(info->map) };
    sfVector2u size = sfTexture_getSize(enemy->type->texture);
    sfVector2f scale = { 0, 0 };
    sfVector2f origin = { 0, 0 };

    scale.x = (float) WIDTH / (float) max.x / (float) size.x * 0.75f;
    scale.y = (float) HEIGHT / (float) max.y / (float) size.y * 0.75f;
    origin.x = (float) size.x / 2;
    origin.y = (float) size.y / 2;
    sfSprite_setTexture(enemy->sprite, enemy->type->texture, sfFalse);
    sfSprite_setOrigin(enemy->sprite, origin);
    sfSprite_setScale(enemy->sprite, scale);
    enemy_move(enemy, game, info);
}

static void generate_enemy(game_t *game, info_t *info)
{
    enemy_t *new = malloc(sizeof(enemy_t));

    new->type = info->enemy_types[rand() % 4];
    new->sprite = sfSprite_create();
    new->clock = sfClock_create();
    new->pos = malloc(sizeof(sfVector2f));
    new->pos->x = info->spawn->x;
    new->pos->y = info->spawn->y;
    new->dir = malloc(sizeof(sfVector2f));
    new->dir->x = 0.1f;
    new->dir->y = 0;
    new->health = new->type->health;
    new->speed = new->type->speed;
    new->next = NULL;
    manage_sprite(new, game, info);
    add_enemy(&game->enemies, new);
}

static void bonus_enemies(game_t *game, info_t *info)
{
    int random = 0;
    int num = game->kills / 10;

    for (int i = 0; i < num; i++) {
        random = rand() % 8;
        if (random == 0) {
            generate_enemy(game, info);
        }
    }
}

void update_enemies(game_t *game, info_t *info)
{
    enemy_t *current = game->enemies;
    enemy_t *tmp = NULL;
    int time = sfClock_getElapsedTime(game->wave).microseconds;

    if (time >= game->next * 100000) {
        generate_enemy(game, info);
        sfClock_restart(game->wave);
        game->next = rand() % 30 + 2;
        bonus_enemies(game, info);
    }
    while (current != NULL) {
        time = sfClock_getElapsedTime(current->clock).microseconds;
        tmp = current->next;
        if (time >= 750000 / current->speed) {
            sfClock_restart(current->clock);
            enemy_move(current, game, info);
        }
        current = tmp;
    }
}
