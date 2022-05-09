/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle scale motion updater
*/

#include "particles.h"

static void init_scale(motion_component_t *scale_component)
{
    apply_sfvector2f_offset(&scale_component->value.v2f_value,
        &scale_component->start_value_offset.v2f_value);
    apply_sfvector2f_offset(&scale_component->speed.v2f_value,
        &scale_component->start_speed_offset.v2f_value);
    apply_sfvector2f_offset(&scale_component->acceleration.v2f_value,
        &scale_component->start_acceleration_offset.v2f_value);
    scale_component->initialized = true;
}

void update_scale(motion_component_t *scale_component)
{
    sfVector2f value = scale_component->value.v2f_value;
    sfVector2f speed = scale_component->speed.v2f_value;
    sfVector2f acceleration = scale_component->acceleration.v2f_value;

    if (!scale_component->initialized) {
        init_scale(scale_component);
        return;
    }
    speed.x += acceleration.x;
    speed.y += acceleration.y;
    scale_component->speed.v2f_value = speed;
    value.x += speed.x;
    value.y += speed.y;
    scale_component->value.v2f_value = value;
}
