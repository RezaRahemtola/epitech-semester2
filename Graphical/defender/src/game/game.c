/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Function to use the game structure
*/

#include "defender.h"

game_t *init_game(info_t *info)
{
    game_t *game = malloc(sizeof(game_t));

    game->gold = 500;
    game->spent = 0;
    game->hp = 500;
    game->kills = 0;
    game->enemies = NULL;
    game->towers = NULL;
    game->wave = sfClock_create();
    game->next = rand() % 50 + 2;
    game->death_sound = sound_create("assets/death_sound.ogg", false, false);
    game->info = info;
    game->display_range = true;
    return (game);
}

void free_game(game_t *game)
{
    clear_enemies(game->enemies);
    clear_towers(game->towers);
    sfClock_destroy(game->wave);
    sound_destroy(game->death_sound);
    free(game);
}
