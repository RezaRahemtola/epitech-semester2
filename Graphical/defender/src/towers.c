/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Towers management
*/

#include "defender.h"

void clear_towers(tower_t *towers)
{
    tower_t *tower = towers;
    tower_t *tmp = NULL;

    while (tower != NULL) {
        tmp = tower;
        tower = tower->next;
        sfSprite_destroy(tmp->sprite);
        sfCircleShape_destroy(tmp->range);
        free(tmp->pos);
        sfClock_destroy(tmp->clock);
        sfClock_destroy(tmp->shot);
        free(tmp);
    }
}

void add_tower(tower_t **list, tower_t *tower)
{
    tower_t *current = *list;

    if (*list == NULL) {
        *list = tower;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = tower;
}

tower_t *find_tower(tower_t *list, int x, int y)
{
    tower_t *current = list;

    while (current != NULL) {
        if ((int) current->pos->x == x && (int) current->pos->y == y) {
            return (current);
        }
        current = current->next;
    }
    return (NULL);
}
