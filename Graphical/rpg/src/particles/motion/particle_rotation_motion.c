/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle rotation motion updater
*/

#include "particles.h"

static void init_rotation(motion_component_t *rotation_component)
{
    apply_float_offset(&rotation_component->value.float_value,
        rotation_component->start_value_offset.float_value);
    apply_float_offset(&rotation_component->speed.float_value,
        rotation_component->start_speed_offset.float_value);
    apply_float_offset(&rotation_component->acceleration.float_value,
        rotation_component->start_acceleration_offset.float_value);
    rotation_component->initialized = true;
}

void update_rotation(motion_component_t *rotation_component)
{
    float value = rotation_component->value.float_value;
    float speed = rotation_component->speed.float_value;
    float acceleration = rotation_component->acceleration.float_value;

    if (!rotation_component->initialized) {
        init_rotation(rotation_component);
        return;
    }
    speed += acceleration;
    rotation_component->speed.float_value = speed;
    value += speed;
    rotation_component->value.float_value = value;
}
