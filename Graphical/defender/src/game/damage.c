/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Damage
*/

#include <math.h>
#include "defender.h"

void shoot_enemy(game_t *game, enemy_t *enemy, tower_t *tower)
{
    switch (tower->type->dmg_type) {
        case SINGLE_DMG:
        case ZONE_DMG:
            enemy->health -= tower->type->damage;
            break;
        case SLOW:
            enemy->speed = MAX(enemy->speed - tower->type->damage, 4);
            break;
        case MID:
            enemy->health = enemy->health / 3 * 2;
            break;
    }
    if (enemy->health <= 0) {
        remove_enemy(&game->enemies, enemy);
        game->gold += 25;
        game->kills += 1;
    }
}

static void attack_all(tower_t *tower, game_t *game)
{
    sfFloatRect bounds = sfCircleShape_getGlobalBounds(tower->range);
    sfFloatRect hitbox;
    enemy_t *current = game->enemies;
    bool restart = false;

    while (current != NULL) {
        hitbox = sfSprite_getGlobalBounds(current->sprite);
        if (sfFloatRect_intersects(&bounds, &hitbox, NULL)) {
            shoot_enemy(game, current, tower);
            restart = true;
        }
        current = current->next;
    }
    if (restart) {
        sfClock_restart(tower->shot);
    }
}

static enemy_t *get_nearest(tower_t *tower, game_t *game)
{
    sfFloatRect bounds = sfCircleShape_getGlobalBounds(tower->range);
    sfFloatRect hitbox;
    enemy_t *enemy = game->enemies;
    enemy_t *nearest = NULL;
    float dist = 0;
    float near = 0;
    bool condition = false;

    while (enemy != NULL) {
        hitbox = sfSprite_getGlobalBounds(enemy->sprite);
        if (sfFloatRect_intersects(&bounds, &hitbox, NULL)) {
            dist = get_distance(tower->pos, enemy->pos);
            condition = (dist < near || nearest == NULL);
            nearest = (condition ? enemy : nearest);
            near = (condition ? dist : near);
        }
        enemy = enemy->next;
    }
    return nearest;
}

static void tower_shoot(tower_t *tower, game_t *game)
{
    enemy_t *nearest = NULL;

    if (tower->type->dmg_type == ZONE_DMG) {
        attack_all(tower, game);
        return;
    }
    nearest = get_nearest(tower, game);
    if (nearest != NULL) {
        sfClock_restart(tower->shot);
        shoot_enemy(game, nearest, tower);
    }
}

void update_towers(game_t *game)
{
    sfUint64 time = 0;
    sfUint64 limit = 0;
    tower_t *current = game->towers;

    while (current != NULL) {
        time = sfClock_getElapsedTime(current->shot).microseconds;
        limit = 10000000 / current->type->speed;
        if (time >= limit) {
            tower_shoot(current, game);
        }
        current = current->next;
    }
}
