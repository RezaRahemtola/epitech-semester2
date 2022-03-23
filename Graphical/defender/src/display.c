/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** Display functions
*/

#include "defender.h"

void display_enemies(sfRenderWindow *window, enemy_t *enemies)
{
    enemy_t *current = enemies;
    sfTexture *hp_textu = sfTexture_createFromFile("assets/hp_bar.png", NULL);
    sfTexture *bg_textu = sfTexture_createFromFile("assets/hp_bg.png", NULL);
    sfSprite *hp_sprite = sfSprite_create();
    sfSprite *bg_sprite = sfSprite_create();

    sfSprite_setTexture(hp_sprite, hp_textu, sfTrue);
    sfSprite_setTexture(bg_sprite, bg_textu, sfTrue);
    while (current != NULL) {
        sfRenderWindow_drawSprite(window, current->sprite, NULL);
        display_healthbar(current, hp_sprite, bg_sprite, window);
        current = current->next;
    }
    csfml_destroyer("tsts", hp_textu, hp_sprite, bg_textu, bg_sprite);
}

void display_towers(sfRenderWindow *window, game_t *game)
{
    tower_t *current = game->towers;

    while (current != NULL) {
        if (sfClock_getElapsedTime(current->clock).microseconds >= 100000) {
            move_spriterect(current->sprite, 88);
            sfClock_restart(current->clock);
        }
        sfRenderWindow_drawSprite(window, current->sprite, NULL);
        if (game->display_range)
            sfRenderWindow_drawCircleShape(window, current->range, NULL);
        current = current->next;
    }
}
