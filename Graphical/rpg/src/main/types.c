/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Enemy types
*/

#include <stdlib.h>
#include "configuration.h"
#include "mobs.h"
#include "my_math.h"
#include "my_string.h"

mob_type_t *create_mob_type(char *config_path)
{
    configuration_t *config = load_configuration(config_path, false);
    sfTexture *texture = NULL;
    mob_type_t *type = malloc(sizeof(mob_type_t));

    if (type == NULL || config == NULL) {
        my_dprintf(2, "Error: Cannot create mob type\n");
        return (NULL);
    }
    texture = sfTexture_createFromFile(GCVOR(config, "texture", ""), NULL);
    type->texture = texture;
    type->rects = my_getnbr(GCVOR(config, "rects", "1"));
    type->name = my_strdup(GCVOR(config, "name", "Unknown"));
    type->base_hp = my_getnbr(GCVOR(config, "hp", "1"));
    type->base_attack = my_getnbr(GCVOR(config, "attack", "1"));
    type->base_defense = my_getnbr(GCVOR(config, "defense", "1"));
    type->base_speed = my_getnbr(GCVOR(config, "speed", "1"));
    type->xp = my_getnbr(GCVOR(config, "xp", "1"));
    destroy_configuration(config);
    return (type);
}

static void init_mob_sprite(mob_t *mob)
{
    sfVector2u size = sfTexture_getSize(mob->type->texture);
    sfIntRect rect = { 0, 0, size.x / mob->type->rects, size.y };

    sfSprite_setTexture(mob->sprite, mob->type->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, rect);
}

mob_t *create_mob(mob_type_t *type, int level, sfVector2f pos)
{
    mob_t *mob = malloc(sizeof(mob_t));
    sfVector2f *vec = malloc(sizeof(sfVector2f));

    if (mob == NULL || vec == NULL) {
        my_dprintf(2, "Error: Cannot create mob\n");
        return (NULL);
    }
    mob->sprite = sfSprite_create();
    mob->anim = sfClock_create();
    mob->move = sfClock_create();
    mob->pos = vec;
    vec->x = pos.x;
    vec->y = pos.y;
    mob->type = type;
    mob->health = type->base_hp + (level - 1) * 2;
    mob->attack = type->base_attack + (level - 1) / 3;
    mob->defense = type->base_defense + (level - 1) / 2;
    mob->speed = type->base_speed + (level - 1) / 2;
    init_mob_sprite(mob);
    return (mob);
}
