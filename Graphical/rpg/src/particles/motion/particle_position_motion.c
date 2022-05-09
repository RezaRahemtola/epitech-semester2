/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle position motion handler
*/

#include "particles.h"

static void init_position(motion_component_t *position_component)
{
    apply_sfvector2f_offset(&position_component->value.v2f_value,
        &position_component->start_value_offset.v2f_value);
    apply_sfvector2f_offset(&position_component->speed.v2f_value,
        &position_component->start_speed_offset.v2f_value);
    apply_sfvector2f_offset(&position_component->acceleration.v2f_value,
        &position_component->start_acceleration_offset.v2f_value);
    position_component->initialized = true;
}

void update_position(motion_component_t *position_component)
{
    sfVector2f value = position_component->value.v2f_value;
    sfVector2f speed = position_component->speed.v2f_value;
    sfVector2f acceleration = position_component->acceleration.v2f_value;

    if (!position_component->initialized) {
        init_position(position_component);
        return;
    }
    speed.x += acceleration.x;
    speed.y += acceleration.y;
    position_component->speed.v2f_value = speed;
    value.x += speed.x;
    value.y += speed.y;
    position_component->value.v2f_value = value;
}
