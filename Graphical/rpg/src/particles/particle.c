/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle utilities
*/

#include "particles.h"

static particle_t *create_particle(motion_t *motion, sfSprite *sprite,
    unsigned int lifetime)
{
    particle_t *particle = malloc(sizeof(particle_t));
    if (particle == NULL || sprite == NULL || motion == NULL)
        return NULL;
    particle->motion = copy_motion(motion);
    particle->sprite = sfSprite_copy(sprite);
    particle->lifetime = lifetime;
    return particle;
}

particle_t *create_particles(motion_t *motion, sfSprite *sprite, size_t number,
    unsigned int lifetime)
{
    particle_t *head = create_particle(motion, sprite, lifetime);
    particle_t *previous = NULL;
    particle_t *current = head;

    if (current == NULL)
        return NULL;
    for (size_t i = 0; i < number - 1; i++) {
        current->next = create_particle(motion, sprite, lifetime);
        if (current->next == NULL)
            return NULL;
        current->prev = previous;
        previous = current;
        current = current->next;
    }
    current->next = head;
    current->prev = previous;
    current->last = true;
    head->prev = current;
    head->first = true;
    return head;
}

void destroy_particle(particle_t *particle)
{
    if (particle == NULL)
        return;
    particle->prev->next = particle->next;
    particle->next->prev = particle->prev;
    if (particle->first)
        particle->next->first = true;
    if (particle->last)
        particle->prev->last = true;
    sfSprite_destroy(particle->sprite);
    if (particle->motion != NULL) {
        free(particle->motion->position_component);
        free(particle->motion->rotation_component);
        free(particle->motion->scale_component);
        free(particle->motion->opacity_component);
        free(particle->motion);
    }
    free(particle);
}
