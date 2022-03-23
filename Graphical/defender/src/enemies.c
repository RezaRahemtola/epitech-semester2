/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Enemies management
*/

#include "defender.h"

static bool enemy_equals(enemy_t *enemy, enemy_t *obj)
{
    bool pos = (enemy->pos->x == obj->pos->x && enemy->pos->y == obj->pos->y);
    bool stats = (enemy->health == obj->health && enemy->speed == obj->speed);

    return (pos && stats);
}

static void free_enemy(enemy_t *enemy)
{
    sfSprite_destroy(enemy->sprite);
    free(enemy->pos);
    free(enemy->dir);
    sfClock_destroy(enemy->clock);
    free(enemy);
}

void clear_enemies(enemy_t *enemies)
{
    enemy_t *enemy = enemies;
    enemy_t *tmp = NULL;

    while (enemy != NULL) {
        tmp = enemy;
        enemy = enemy->next;
        free_enemy(tmp);
    }
}

void add_enemy(enemy_t **list, enemy_t *enemy)
{
    enemy_t *current = *list;

    if (*list == NULL) {
        *list = enemy;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = enemy;
}

void remove_enemy(enemy_t **list, enemy_t *enemy)
{
    enemy_t *current = *list;
    enemy_t *prev = NULL;

    if (*list == NULL)
        return;
    if (enemy_equals(*list, enemy)) {
        current = *list;
        *list = current->next;
        return;
    }
    while (current != NULL) {
        if (enemy_equals(current, enemy)) {
            prev->next = current->next;
            free_enemy(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
