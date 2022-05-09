/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle opacity motion handler
*/

#include "particles.h"

static void init_opacity(motion_component_t *opacity_component)
{
    apply_sfuint8_offset(&opacity_component->value.ui8_value,
        opacity_component->start_value_offset.ui8_value);
    apply_sfuint8_offset(&opacity_component->speed.ui8_value,
        opacity_component->start_speed_offset.ui8_value);
    apply_sfuint8_offset(&opacity_component->acceleration.ui8_value,
        opacity_component->start_acceleration_offset.ui8_value);
    opacity_component->initialized = true;
}

void update_opacity(motion_component_t *opacity_component)
{
    sfUint8 value = opacity_component->value.ui8_value;
    sfUint8 speed = opacity_component->speed.ui8_value;
    sfUint8 acceleration = opacity_component->acceleration.ui8_value;

    if (!opacity_component->initialized) {
        init_opacity(opacity_component);
        return;
    }
    speed += acceleration;
    opacity_component->speed.ui8_value = speed;
    value += speed;
    opacity_component->value.ui8_value = value;
}
