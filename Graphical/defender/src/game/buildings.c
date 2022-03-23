/*
** EPITECH PROJECT, 2022
** defender
** File description:
** Functions to play with buildings
*/

#include "defender.h"

static void init_building_stats(building_t *building, textures_t *t)
{
    sfSprite *gold = create_sprite(t->gold, (sfVector2f){1580, 55});
    sfSprite *kill = create_sprite(t->kill, (sfVector2f){1430, 50});
    sfSprite *health = create_sprite(t->health, (sfVector2f){1260, 55});

    building->gold = gold;
    building->kill = kill;
    building->health = health;
}

building_t *init_building(textures_t *t)
{
    building_t *building = malloc(sizeof(building_t));
    sfSprite *buy_fire = create_sprite(t->buy_fire, (sfVector2f){123, 7});
    sfSprite *buy_mid = create_sprite(t->buy_mid, (sfVector2f){290, 7});
    sfSprite *buy_ice = create_sprite(t->buy_ice, (sfVector2f){457, 7});
    sfSprite *buy_poison = create_sprite(t->buy_poison, (sfVector2f){624, 7});
    sfSprite *dragged = sfSprite_create();
    sound_t *button_sound = sound_create("assets/button.ogg", false, false);

    sfSprite_setTextureRect(dragged, (sfIntRect){0, 0, 88, 159});
    building->buy_fire = buy_fire;
    building->buy_ice = buy_ice;
    building->buy_poison = buy_poison;
    building->buy_mid = buy_mid;
    building->is_dragged = sfFalse;
    building->dragged_sprite = dragged;
    building->button_sound = button_sound;
    init_building_stats(building, t);
    return (building);
}

void free_building(building_t *building)
{
    csfml_destroyer("ss", building->buy_fire, building->buy_ice);
    csfml_destroyer("ss", building->buy_poison, building->dragged_sprite);
    csfml_destroyer("ss", building->gold, building->kill);
    csfml_destroyer("sS", building->health, building->button_sound);
    csfml_destroyer("s", building->buy_mid);
    free(building);
}
