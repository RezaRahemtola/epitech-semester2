/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle motion functions
*/

#include "particles.h"

motion_component_t *copy_motion_component(motion_component_t *component)
{
    motion_component_t *result;

    if (component == NULL)
        return NULL;
    result = malloc(sizeof(motion_component_t));
    if (result == NULL)
        return NULL;
    result->value = component->value;
    result->speed = component->speed;
    result->acceleration = component->acceleration;
    result->start_value_offset = component->start_value_offset;
    result->start_speed_offset = component->start_speed_offset;
    result->start_acceleration_offset = component->start_acceleration_offset;
    return result;
}

motion_t *copy_motion(motion_t *motion)
{
    motion_t *result = malloc(sizeof(motion_t));

    if (result == NULL)
        return NULL;
    result->position_component = copy_motion_component
        (motion->position_component);
    result->rotation_component = copy_motion_component
        (motion->rotation_component);
    result->scale_component = copy_motion_component(motion->scale_component);
    result->opacity_component = copy_motion_component
        (motion->opacity_component);
    return result;
}

void update_motion(motion_t *motion)
{
    if (motion == NULL)
        return;
    if (motion->position_component != NULL)
        update_position(motion->position_component);
    if (motion->rotation_component != NULL)
        update_rotation(motion->rotation_component);
    if (motion->scale_component != NULL)
        update_scale(motion->scale_component);
    if (motion->opacity_component != NULL)
        update_opacity(motion->opacity_component);
}
