/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Stats getter
*/

#include "player.h"

int get_total_attack(player_t *player)
{
    int total = player->attack;
    list_t *current = player->inventory;
    item_t *item = NULL;

    while (current != NULL) {
        item = current->data;
        total += item->attack;
        current = current->next;
    }
    return (total);
}

int get_total_defense(player_t *player)
{
    int total = player->defense;
    list_t *current = player->inventory;
    item_t *item = NULL;

    while (current != NULL) {
        item = current->data;
        total += item->defense;
        current = current->next;
    }
    return (total);
}

int get_total_speed(player_t *player)
{
    int total = player->speed;
    list_t *current = player->inventory;
    item_t *item = NULL;

    while (current != NULL) {
        item = current->data;
        total += item->speed;
        current = current->next;
    }
    return (total);
}

int get_total_health(player_t *player)
{
    int total = (int) player->life;
    list_t *current = player->inventory;
    item_t *item = NULL;

    while (current != NULL) {
        item = current->data;
        total += item->health;
        current = current->next;
    }
    return (total);
}
