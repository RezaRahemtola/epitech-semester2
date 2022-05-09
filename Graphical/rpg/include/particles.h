/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Particle system header file
*/

#pragma once

#include <SFML/Graphics.h>
#include "rpg.h"

typedef union motion_component_type {
    float float_value;
    sfVector2f v2f_value;
    sfUint8 ui8_value;
} motion_component_type_t;

typedef struct motion_component {
    bool initialized;
    motion_component_type_t value;
    motion_component_type_t start_value_offset;
    motion_component_type_t speed;
    motion_component_type_t start_speed_offset;
    motion_component_type_t acceleration;
    motion_component_type_t start_acceleration_offset;
} motion_component_t;

typedef struct motion {
    motion_component_t *position_component;
    motion_component_t *rotation_component;
    motion_component_t *scale_component;
    motion_component_t *opacity_component;
} motion_t;

typedef struct particle {
    sfSprite *sprite;
    motion_t *motion;
    unsigned int lifetime;
    struct particle *next;
    struct particle *prev;
    bool first;
    bool last;
} particle_t;

// Motion offsets
void apply_sfvector2f_offset(sfVector2f *value, sfVector2f *offset);
void apply_sfuint8_offset(sfUint8 *value, sfUint8 offset);
void apply_int_offset(int *value, int offset);
void apply_float_offset(float *value, float offset);

// Motion Updates
void update_position(motion_component_t *scale_component);
void update_rotation(motion_component_t *rotation_component);
void update_scale(motion_component_t *scale_component);
void update_opacity(motion_component_t *opacity_component);
void update_motion(motion_t *motion);

motion_t *copy_motion(motion_t *motion);

// Particle tick and render
bool update_particle(particle_t *particle, sfRenderWindow *window);
void render_particle(particle_t *particle, sfRenderWindow *window);
void update_particles(particle_t *particles, sfRenderWindow *window);
void render_particles(particle_t *particles, sfRenderWindow *window);

// Particles utils
particle_t *create_particles(motion_t *motion, sfSprite *sprite, size_t number,
    unsigned int lifetime);
void destroy_particle(particle_t *particle);

particle_t *make_rain(void);
