/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** Particle renderer functions
*/

#include <stdio.h>
#include "particles.h"

void render_particle(particle_t *particle, sfRenderWindow *window)
{
    if (particle->sprite == NULL)
        return;
    sfRenderWindow_drawSprite(window, particle->sprite, NULL);
    sfSprite_setPosition(particle->sprite,
        particle->motion->position_component->value.v2f_value);
}

void render_particles(particle_t *particles, sfRenderWindow *window)
{
    particle_t *head = NULL;

    while (particles != head) {
        if (head == NULL)
            head = particles;
        render_particle(particles, window);
        particles = particles->next;
    }
}
