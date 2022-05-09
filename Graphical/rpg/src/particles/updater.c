/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle update functions
*/

#include <stdio.h>
#include "particles.h"

bool update_particle(particle_t *particle, sfRenderWindow *window)
{
    if (particle == NULL || window == NULL)
        return false;
    if (particle->lifetime != 0) {
        particle->lifetime--;
        update_motion(particle->motion);
        return true;
    } else {
        particle->sprite = NULL;
        return true;
    }
}

void update_particles(particle_t *particles, sfRenderWindow *window)
{
    particle_t *head = NULL;
    particle_t *next;

    while (particles != head) {
        next = particles->next;
        if (head == NULL)
            head = particles;
        if (!update_particle(particles, window) && head == particles)
            head = next;
        particles = next;
    }
}
