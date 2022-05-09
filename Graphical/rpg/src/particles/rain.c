/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Rain utils
*/

#include "particles.h"
#include "mycsfml_elements.h"

static sfSprite *load_rain_sprite(void)
{
    char const *path = "assets/droplet.png";
    sfIntRect area = {0, 0, 1080, 1080};
    sfTexture *texture = sfTexture_createFromFile(path, &area);

    return create_sprite(texture, (sfVector2f) {0, 0});
}

static void init_position_component(motion_component_t *position_component)
{
    position_component->value.v2f_value = (sfVector2f) {0, -500};
    position_component->start_value_offset.v2f_value = (sfVector2f) {8000,
        -1000};
    position_component->speed.v2f_value = (sfVector2f) {0, 12};
    position_component->start_speed_offset.v2f_value = (sfVector2f) {0, 0};
    position_component->acceleration.v2f_value = (sfVector2f) {0, 0};
    position_component->start_acceleration_offset.v2f_value = (sfVector2f) {0,
        0};
    position_component->initialized = false;
}

particle_t *make_rain(void)
{
    motion_component_t position_component;
    motion_t motion;
    sfSprite *sprite = load_rain_sprite();

    sfSprite_setScale(sprite, (sfVector2f) {0.1f, 0.1f});
    init_position_component(&position_component);
    motion = (motion_t) {&position_component, NULL, NULL, NULL};
    return create_particles(&motion, sprite, 1000, 10000);
}
