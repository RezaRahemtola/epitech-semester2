/*
** EPITECH PROJECT, 2021
** CSFML Utils
** File description:
** Game objects functions
*/

#include "mycsfml_game_obj.h"

void destroy_object_list(game_obj_t *head)
{
    game_obj_t *current = head;
    game_obj_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        sfSprite_destroy(tmp->sprite);
        clock_destroy(tmp->clock);
        free(tmp);
    }
}
